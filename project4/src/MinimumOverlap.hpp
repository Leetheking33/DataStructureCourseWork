#ifndef MinimumOverlap_HPP
#define MinimumOverlap_HPP

#include <string>
#include <vector>
#include <iostream>
using namespace std;
class student {
	public:
	   int studentId;
	   int gradesNeeded = 1;
	   vector<int> groupsStudentIsIn;
        


};
class MinimumOverlap {
    public:
	//vector of vectors each y vector holds the students in group
	vector<vector<int> > groups; 	    
	//contains the group combination for each student in vector
	//students come from cover
	vector<student> combos;

        // Passes in a string pointing to the set/group file.
        // Make sure you store all the sets/groups!
        MinimumOverlap(const std::string &setFile);

        // Returns the minimum number of overlaps possible given a cover.
        // If print is true, it prints the set(s).
        unsigned int findMinimumOverlap(const std::vector<int> &cover, const bool &print);
};

#endif
