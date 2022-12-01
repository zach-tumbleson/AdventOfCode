#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

struct Elf {
    int calories;
    vector<int> items;
};

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Error: Usage is $day1 <inputFileName>, please include the input file as the only input." << endl;
        return EXIT_FAILURE;
    }

    //Prepare elf data
    vector<Elf> elves = vector<Elf>();

    //Open the file
    ifstream inFile = ifstream();
    inFile.open(argv[1]);

    //Read in all elves
    string line;
    Elf temp = Elf();
    while(getline(inFile, line)) {
        try
        {
            //cout << "New number: " << line << endl;
            temp.items.push_back(stoi(line));
        }
        catch(const std::exception& e)
        {
            //cout << "Cast failed, create a new elf." << endl;
            elves.push_back(temp);
            temp = Elf();
        }    
    }

    //Calculate total calories for all
    for(int i=0; i < elves.size(); i++) {
        //cout << "Handling Elf #" << i+1 << endl;
        Elf elf = elves[i];
        int sum = 0;
        for(int j = 0; j < elf.items.size(); j++) {
            //cout << "Adding " << elf.items[j] << " to this elf's total calories." << endl;
            elves[i].calories += elf.items[j];
        }

        //cout << "This elf has " << elf.calories << " total calories." << endl;    
    }

    //Get max
    //cout << "\nCalculating Max\n**********************" << endl;
    int max = 0;
    for(int i = 0; i < elves.size(); i++) {
        Elf elf = elves[i];
        if(max < elf.calories) {
            max = elf.calories;
        }
    }

    cout << "Max is: " << max << endl;
    //cout << "Number of Elves: " << elves.size() << endl;

    return EXIT_SUCCESS;
}