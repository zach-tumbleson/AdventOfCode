#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int calculatePriority(string sack1, string sack2);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Error: Usage is \"programName inputFileName>\", please include the input file as the only input." << endl;
        return EXIT_FAILURE;
    }

    //Open the file
    ifstream inFile = ifstream();
    inFile.open(argv[1]);

    //Prepare the data
    int sum = 0;

    //Read in
    string line;
    while(getline(inFile, line)) {
        int end = line.size() ;
        int midpoint = line.size() / 2;
        string compartment1 = line.substr(0, midpoint);
        string compartment2 = line.substr(midpoint, end);
        //cout << "Rucksack Items: " << line << endl;
        //cout << "Compartment 1: " << compartment1 << endl << "Compartment 2: " << compartment2 << endl;
        sum += calculatePriority(compartment1, compartment2);
    }

    cout << "Total Sum is " << sum << endl;

    return EXIT_SUCCESS;
}

int calculatePriority(string sack1, string sack2) {
    string priorityChars = "";
    int priority = 0;
    map<char, bool> characterMap1;
    map<char, bool> characterMap2;
    
    //Check for matches
    for(int i = 0; i < sack1.size(); i++) {
        characterMap1[sack1[i]] = true;
        characterMap2[sack2[i]] = true;
        //cout << "Letters: " << sack1[i] << " " << sack2[i] << endl;
        if(characterMap1[sack1[i]] && characterMap2[sack1[i]]) {
            priorityChars += sack1[i];
            break;
        } 
        else if(characterMap1[sack2[i]] && characterMap2[sack2[i]]) {
            priorityChars += sack2[i];
            break;
        }
    }

    //Calculate priority number, if necessary
    if(priorityChars.length() != 0) {
        int a = 1;
        int A = 27;
        for(int i = 0; i < priorityChars.length(); i++) {
            if(priorityChars[i] >= 'a' && priorityChars[i] <= 'z') {
                // If lower case, compare to 'a'
                priority = a + priorityChars[i] - 'a';
            } else if (priorityChars[i] >= 'A' && priorityChars[i] <= 'Z') {
                // If upper case, compare to "A"
                priority = A + priorityChars[i] - 'A';
            }
        }
    }
    
    //Return 
    //cout << "Priority value: " << priority << "(" << priorityChars << ")" << endl;
    return priority;
}