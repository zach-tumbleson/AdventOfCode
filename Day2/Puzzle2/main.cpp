#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int calculateResult(char mine, char opp);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Error: Usage is \"programName inputFileName>\", please include the input file as the only input." << endl;
        return EXIT_FAILURE;
    }

    //Open the file
    ifstream inFile = ifstream();
    inFile.open(argv[1]);

    //Prepare data
    int score = 0;

    //Read in all elves
    string line;
    while(getline(inFile, line)) {
        score += calculateResult(line[2], line[0]);
    }

    cout << "Final score is: " << score << endl;

    return EXIT_SUCCESS;
}

int calculateResult(char mine, char opp) {
    int result = 0;

    // Add round bonus
    switch(mine) {
        case 'X': // Choose lose
            switch(opp) {
                case 'A': // Choose Scissors
                    result += 3;
                    break;
                case 'B': // Choose Rock
                    result += 1;
                    break;
                case 'C': // Choose Paper
                    result += 2;
                    break;
            }
            result += 0; // Round bonus
            break;
        case 'Y': // Choose Draw
            switch(opp) {
                case 'A': // Choose rock
                    result += 1;
                    break;
                case 'B': // Choose Paper
                    result += 2;
                    break;
                case 'C': // Choose Scissors
                    result += 3;
                    break;
            }
            result += 3; // round bonus
            break;
        case 'Z': // Choose win
            switch(opp) {
                case 'A': // Choose paper
                    result += 2;
                    break;
                case 'B': // Choose Scissors
                    result += 3;
                    break;
                case 'C': // Choose Rock
                    result += 1;
                    break;
            }
            result += 6; // Round bonus
            break;
    }

    //cout << "Resulting score is: " << result << endl;
    return result;
}
