#include <iostream>
#include <stdio.h>
using namespace std;

class Student{
	public:
		int mId;
		double mGPA;
};

int main(int argc, char *argv[]){
	Student *students = new Student[100];
	Student ** studentsPtr = new Student*[100];

	srand(100);
	for(int i = 0; i < 100; i++){
		students[i].mId = i+1;

		students[i].mGPA = 4 * (((double)rand())/RAND_MAX);

		studentsPtr[i] = students+i;
	}
	
	for (int i = 0; i < 100; i++){
		for (int j = 1; j < 100; j++){
			if(studentsPtr[j-1]->mGPA > studentsPtr[j]->mGPA) {
				Student *temp = studentsPtr[j];
				studentsPtr[j] = studentsPtr[j-1];
				studentsPtr[j-1] = temp;
			}
		}
	}

	for (int i =0; i < 100; i++) {
		printf(" %f\n", studentsPtr[i]->mGPA);
	}

	delete studentsPtr;
	delete students;
	return 0;
}
