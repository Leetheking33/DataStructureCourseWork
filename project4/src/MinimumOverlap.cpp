#include "MinimumOverlap.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <istream>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

//from my own personal testing this implementation does not account for
//duplicate students in a cover despite my best efforts. It does seem
//how ever to print correctly when there are no dupes in the cover 
//when I have ran my own tests

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
    
    /* print out vector of vectors to display groups */
    for(int i = 0; i < groups.size(); i++){
            for (int j =0; j < groups[i].size(); j++){
                    cout << groups[i][j] << ", ";
            }
            cout << endl;
    }		
    
}

unsigned int MinimumOverlap::findMinimumOverlap(const std::vector<int> &cover, const bool &print) {
	//check if cover is empty if so return -1 cause we cant find min over
	//lap of no students
	if(cover.empty()){
		return -1;
	}
	
	//copy cover into a member vector so it can be refered to
	mCover = cover;
	
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
	
	//iterate through vector of cover students than iterate through 
	//group vector<vec> add group index to groupStudentIsIn vector when
	//ever a the student is found 
	for(int i = 0; i < combos.size(); i++){
		for(int j = 0; j < groups.size(); j++){
			for(int k = 0; k < groups[j].size(); k++){
				if(groups[j][k] == combos[i].studentId){
					combos[i].groupsStudentIsIn.push_back(j);
				}
			}
		}
	}
	
	//build a vector that contains all the groups that the cover students 
	//are in with out any dupes I call this bad boy noDupes
	bool found = false;
	for(int i = 0; i < combos.size(); i++){
		for(int j = 0; j < combos[i].groupsStudentIsIn.size(); j++){
			if(noDupes.empty()){
				noDupes.push_back(combos[i].groupsStudentIsIn[j]);
			}
			for(int k = 0; k < noDupes.size(); k++){
				if(combos[i].groupsStudentIsIn[j] ==
						noDupes[k]){
					found = true;
				}
			}
			if(found){
				found = false;
				continue;
			}
			noDupes.push_back(combos[i].groupsStudentIsIn[j]);
			found = false;
		}
	}
	
	/* This is some personal testing to make sure I was getting the
	 * correct groups each student was in
	for(int i = 0; i < combos.size(); i++){
		cout << "student: " << combos[i].studentId << endl;
		cout << "Groups in: ";
		for(int j = 0; j < combos[i].groupsStudentIsIn.size(); j++){
			cout << combos[i].groupsStudentIsIn[j] << ", ";
		}
		cout << endl;
	}
	cout << endl;
	
	//prints out the groups each student the cover is in with out dupes
	cout << "Groups w/o dupes: ";	
	for(int i = 0; i < noDupes.size(); i++){
		cout << noDupes[i] << ", ";
	}
	cout << endl;
 	*/

	// getting every combinaton	
	int temp[noDupes.size()];	
	for(int i = 0; i < noDupes.size(); i++){
		comboUtil(noDupes, temp, 0, noDupes.size() - 1, 0, i);
	}	
	//cout << "Min: " << minimum;
	return minimum;
}

// function to calculate the possible combinations of r elements
void MinimumOverlap::comboUtil(vector<int> arr, int data[], int start,
        				int end,int index, int r){
	//group combination
	vector<int> groupNums;

	// this bool will tell me if a combo contains all of thr cover
	vector<bool> allFound (mCover.size(), false); 
	if(index == r){
		for(int j = 0; j < r; j++){
			//cout << data[j] << ", ";
			groupNums.push_back(data[j]);
		}
		cout << endl;
		
		// search groupNum which is the current combo of groups 
		// then see if this combo contains all of the cover students
		for(int i = 0; i < groupNums.size(); i++){
			for(int j = 0; j < groups[groupNums[i]].size(); j++){
				for(int k = 0; k < mCover.size(); k++){
					if(groups[groupNums[i]][j] == 
							mCover[k]){
						allFound[k] = true;
						
					}
				}
			}

		}
		
		//this will check if this current combo contains all the cover
		//if it hits a false return if not it will execute 
		//the min cover comparator
		for(int i = 0; i < allFound.size(); i++){
			if(!allFound[i]){
				//cout << "Does not work." << endl;
				return;
			}	
		}
		unsigned int comboGrade = 0;
		for(int i = 0; i < groupNums.size(); i++){
			comboGrade += groups[groupNums[i]].size();
		}
		
		if(comboGrade < minimum){
			minimum = comboGrade;
		}	
		
		
		return;
	}
	//this recursion allows me to get every combo for r
	for(int i = start; i <= end && end - i + 1 >= r - index; i++){
		data[index] = arr[i];
		comboUtil(arr, data, i+1, end, index+1, r);
	}
	
}
