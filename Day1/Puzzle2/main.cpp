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

bool compareByLength(const Elf &a, const Elf &b)
{
    return a.calories < b.calories;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Error: Usage is $day1 <inputFileName>, please include the input file as the only input." << endl;
        return EXIT_FAILURE;
    }

    //Prepare elf data
    vector<Elf> elves = vector<Elf>();
    vector<Elf> topThree(3);

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

        for (int j = 0; j < 3; j++) {
            if(elves[i].calories > topThree[j].calories) {
                topThree[j] = elves[i];
                sort(topThree.begin(), topThree.end(), compareByLength);
                break;
            }
        }
    }

    //Get top three sum
    int topThreeSum = 0;
    for(int i = 0; i < 3; i++) {
        topThreeSum += topThree[i].calories;
    }

    cout << "Top Three Total is: " << topThreeSum << endl;

    return EXIT_SUCCESS;
}