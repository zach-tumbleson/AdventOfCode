#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

int calculatePriority(string sack1, string sack2, string sack3);
map<char, bool> reduceToCharacterMap(string sack);
int getLargestSack(int count1, int count2, int count3);

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
    string sack1;
    string sack2;
    string sack3;
    while(getline(inFile, sack1)) {
        getline(inFile, sack2);
        getline(inFile, sack3);
        
        //cout << endl << "Sacks: ********************" << endl << "Sack1: " << sack1 << endl << "Sack2: " << sack2 << endl << "Sack3: " << sack3 << endl; 
        sum += calculatePriority(sack1, sack2, sack3);
    }

    cout << "Total Sum is " << sum << endl;

    return EXIT_SUCCESS;
}

int calculatePriority(string sack1, string sack2, string sack3) {
    char priorityChar;
    int priority = 0;
    
    //Figure out which sack is the largest
    int largest = getLargestSack(sack1.length(), sack2.length(), sack3.length());
    
    //Reduce smallest sacks to hashmaps
    string largestSack;
    map<char, bool> smaller1;
    map<char, bool> smaller2;
    //cout << "Largest: " << largest << endl;
    switch(largest) {
        case 1:
            largestSack = sack1;
            smaller1 = reduceToCharacterMap(sack2);
            smaller2 = reduceToCharacterMap(sack3);
            break;
        case 2:
            largestSack = sack2;
            smaller1 = reduceToCharacterMap(sack1);
            smaller2 = reduceToCharacterMap(sack3);
            break;
        case 3:
            largestSack = sack3;
            smaller1 = reduceToCharacterMap(sack1);
            smaller2 = reduceToCharacterMap(sack2);
            break;
    }

    //Look for matches
    for(int i = 0; i < largestSack.length(); i++) {
        //cout << "Letter: " << largestSack[i] << endl;
        //cout << "Sack1 Match: " << smaller1.count(largestSack[i]) << endl;
        //cout << "Sack2 Match: " << smaller2.count(largestSack[i]) << endl;
        if(smaller1.count(largestSack[i]) == 1 && smaller2.count(largestSack[i]) == 1){
            priorityChar = largestSack[i];
            break;
        }
    }

    //Calculate priority number, if necessary
    if(priorityChar != 0) {
        int a = 1;
        int A = 27;
        if(priorityChar >= 'a' && priorityChar <= 'z') {
            // If lower case, compare to 'a'
            priority = a + priorityChar - 'a';
        } else if (priorityChar >= 'A' && priorityChar <= 'Z') {
            // If upper case, compare to "A"
            priority = A + priorityChar - 'A';
        }
    } else {
        cout << "No badge found!" << endl;
        exit(1);
    }
    
    //Return 
    //cout << "Priority value: " << priority << "(" << priorityChar << ")" << endl;
    return priority;
}

map<char, bool> reduceToCharacterMap(string sack) {
    map<char, bool> map;
    for(int i = 0; i < sack.length(); i++){
        if(map.count(sack[i]) == 1) {
            continue;
        }
        map[sack[i]] = true;
        //cout << sack[i];
    }

    //cout << endl;

    return map;
}

int getLargestSack(int count1, int count2, int count3) {
    int largest;
    if(count1 > count2) {
        if(count1 > count3) {
            largest = 1;
        } else {
            largest = 3;
        }
    } else if(count2 > count3) {
        largest = 2;
    } else {
        largest = 3;
    }
    
    return largest;
}