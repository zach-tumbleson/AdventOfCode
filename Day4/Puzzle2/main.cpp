#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Range {
    string printRange() {
        cout << start << " " << end << endl;
        return "Range: " + to_string(start) + "-" + to_string(end); 
    }

    int start;
    int end;
};

bool overlaps(Range range1, Range range2);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Error: Usage is \"programName inputFileName>\", please include the input file as the only input." << endl;
        return EXIT_FAILURE;
    }

    //Open the file
    ifstream inFile = ifstream();
    inFile.open(argv[1]);

    // Data
    int total = 0;

    string line;
    while(getline(inFile, line)) {
        stringstream stream = stringstream(line);
        string range1Start;
        string range1End;
        string range2Start;
        string range2End;

        getline(stream, range1Start, '-');
        getline(stream, range1End, ',');
        getline(stream, range2Start, '-');
        getline(stream, range2End);

        //Input check
        //cout << range1Start << "-" << range1End << "," << range2Start << "-" << range2End << endl;
    
        //Check the ranges
        Range range1 = { stoi(range1Start), stoi(range1End) };
        Range range2 = { stoi(range2Start), stoi(range2End) };

        if(overlaps(range1, range2)) {
            total++;
        }
    }

    cout << "Total: " << total << endl;

    return EXIT_SUCCESS;
}

bool overlaps(Range range1, Range range2){
    //cout << range1.printRange() << endl << range2.printRange() << endl << endl;
    return range1.start == range2.start 
    || range1.end == range2.start
    || range1.start == range2.end
    || range1.end == range2.end
    || range1.start <= range2.end && range1.start >= range2.start
    || range2.start <= range1.end && range2.start >= range1.start;
}