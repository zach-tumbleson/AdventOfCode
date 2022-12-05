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

    // Add shape bonus
    switch(mine) {
        case 'X':
            result += 1;
            break;
        case 'Y':
            result += 2;
            break;
        case 'Z':
            result += 3;
            break;
    }

    // Add round bonus
    switch(mine) {
        case 'X': // Rock
            switch(opp) {
                case 'A': // Rock vs. Rock
                    result += 3;
                    break;
                case 'B': // Rock vs Paper
                    result += 0;
                    break;
                case 'C': // Rock vs scissors
                    result += 6;
                    break;
            }
            break;
        case 'Y': // Paper
            switch(opp) {
                case 'A': // Paper vs Rock
                    result += 6;
                    break;
                case 'B': // Paper vs Paper
                    result += 3;
                    break;
                case 'C': // Paper vs Scissors
                    result += 0;
                    break;
            }
            break;
        case 'Z': // Scissors
            switch(opp) {
                case 'A': // Scissors vs Rock
                    result += 0;
                    break;
                case 'B': // Scissors vs Paper
                    result += 6;
                    break;
                case 'C': // Scissors vs Scissors
                    result += 3;
                    break;
            }
            break;
    }

    //cout << "Resulting score is: " << result << endl;
    return result;
}

//Cheat sheet
// Rock = A/X
// Paper = B/Y
// Scissors = C/Z
