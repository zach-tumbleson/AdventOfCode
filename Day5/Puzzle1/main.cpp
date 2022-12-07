#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

vector< stack<char> > organizeCrateLines(vector<string> crateLines);
void makeMove(vector< stack<char> > &crates, int numberToMove, int origin, int destination);
void printStacks(vector< stack<char> > crates);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Error: Usage is \"programName inputFileName>\", please include the input file as the only input." << endl;
        return EXIT_FAILURE;
    }

    //Open the file
    ifstream inFile = ifstream();
    inFile.open(argv[1]);
    
    //Data
    vector<string> crateLines;
    vector<stack<char> > crates;

    string line;
    while(getline(inFile, line)) {
        if(line != "") {
            crateLines.push_back(line);
        } else {
            //cout << "Found the end of the crates in the input" << endl;
            crates = organizeCrateLines(crateLines);
            break;
        }
    }

    while(getline(inFile, line)){
        //cout << line << endl;
        stringstream stream = stringstream(line);
        string junk;
        int numberToMove;
        int origin;
        int destination;
        stream >> junk;
        stream >> numberToMove;
        stream >> junk;
        stream >> origin;
        stream >> junk;
        stream >> destination;

        //printStacks(crates);
        makeMove(crates, numberToMove, origin, destination);
        //printStacks(crates);
    }

    for(int i = 0; i < crates.size(); i++) {
        cout << crates[i].top();
    }

    cout << endl;

    return EXIT_SUCCESS;
}   

vector< stack<char> > organizeCrateLines(vector<string> crateLines) {
    vector< stack<char> > crates;

    //Figure out how many crate stacks we have (each crate takes up 4 characters counting the space)
    int numStacks = (crateLines[crateLines.size() - 1].length() + 1) / 4;
    
    //Create a stack in memory for each crate stack
    for(int i = 0; i < numStacks; i++){
        crates.push_back(stack<char>());
    }

    //In each crate line, the crate letter we care about is 1...5...9...13...etc, (1 + 4*i)
    //Parse crates into stacks
    for(int i = crateLines.size() - 2; i >= 0; i--) {
        //cout << "Row: " << i+1 << endl;
        for(int j = 1, k = 0; j < crateLines[i].length() && k < numStacks; j = j + 4, k++) {
            if(crateLines[i][j] != ' ') {
                //cout << "Pushing " << crateLines[i][j] << " onto Stack " << k+1 << endl;
                crates[k].push(crateLines[i][j]);
            }
        }
    }

    return crates;
}

void makeMove(vector< stack<char> > &crates, int numberToMove, int origin, int destination){
    for(int i = 0; i < numberToMove; i++) {
        char crate = crates[origin-1].top();
        crates[origin-1].pop();
        crates[destination-1].push(crate);
    }
}

void printStacks(vector< stack<char> > crates) {
    //cout << "Printing stacks:" << endl;
    //Figure out how many rows we're printing
    int maxHeight = 0;
    for(int i = 0; i < crates.size(); i++) {
        if(crates[i].size() > maxHeight) {
            maxHeight = crates[i].size();
        }
    }

    //Print each row
    for(int i = maxHeight; i > 0 ; i--) {
        for(int j = 0; j < crates.size(); j++) {
            if(crates[j].size() >= i) {
                cout << "[" << crates[j].top() << "] " ;
                crates[j].pop();
            } else {
                cout << "    ";
            }
        }
        cout << endl;
    }
}