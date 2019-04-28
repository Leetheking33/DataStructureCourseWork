#include "MinimumOverlap.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <istream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

MinimumOverlap::MinimumOverlap(const std::string &setFile) {
    //take students groups in setFile and put them in vector of vectors
    std::string temp;
    ifstream file;
    file.open(setFile);
    while (std::getline(file, temp)){
        std::istringstream buffer(temp);
        std::vector<int> line((std::istream_iterator<int>(buffer)), std::istream_iterator<int>());
        groups.push_back(line);
    }
    
    /*
    for(int i = 0; i < groups.size(); i++){
            for (int j =0; j < groups[i].size(); j++){
                    cout << groups[i][j] << ", ";
            }
            cout << endl;
    }		
    */
}

unsigned int MinimumOverlap::findMinimumOverlap(const std::vector<int> &cover, const bool &print) {
	//check if cover is empty if so return -1 cause we cant find min over
	//lap of no students
	if(cover.empty()){
		return -1;
	}
	
	//this bool will tell me if a student is already in combos
	bool isFound = false;
	
	//this var tells us what we need to resize combos to
	//its starts at 2 since we know cover isnt empty which gurantees at
	//least a size of 1 so we start at 2 and += as needed
	int comboSize = 2;

	//iterate through cover so we can add our students to combo which shows
	//how many groups a student is in
	for(int i = 0; i < cover.size(); i++){
		//check if combo is empty
		if(combos.empty()){
			combos.resize(1);
			combos[0].studentId = cover[i];
			continue;
		}
		//iterate through combos to check for dupes	
		for(int j = 0; j < combos.size(); j++){
			//if student is already in combo, add to the amt of
			//grades student needs
			if(cover[i] == combos[j].studentId){
				combos[j].gradesNeeded += 1;
				isFound = true;
				continue;	
			}
		}
		if(!isFound){
			combos.resize(comboSize);
			combos[comboSize - 1].studentId = cover[i];
			comboSize++;
		}
		isFound = false;
	}

	for(int i = 0; i < combos.size(); i++){
		cout << "student:" << combos[i].studentId << " grades needed:" << combos[i].gradesNeeded << ", ";
	}
	cout << endl;

}
