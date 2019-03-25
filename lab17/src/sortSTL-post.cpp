#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



class Student {
    private:
        int mSid;
        string mName;
        char mData[10000];
    public:
        int id() const {return mSid;}
        void setId(int s) {mSid=s;}  /* your code must never call this method */
        void print () const {cout << mSid << '(' << mName << "), ";}
        void setName(const string &n) {mName=n;} /* your code must never call 
                                                  * this method
                                                  */

	string getName() const { return mName; }
	
	//overload == operator
	Student operator =(const Student *a){
		mSid = a->mSid;
		mName = a->mName;
		//mData = a.mData;

	}

}; 

struct lessThan {
     public:
	inline bool operator() (const Student& a, const Student& b){
		return (a.id() < b.id());
	}
};
	
struct pLessThan {
     public:
        inline bool operator() (const Student* a, const Student* b){
                return (a->id() < b->id());
        }
};

int main (int argc, char *argv[]) {
    const int backup[10] =
        {2,5,0,9,7,4,3,1,8,6};//constant array with data to sort
    const string names[10] =
        {"CJ", "F", "A", "JJ", "HZ", "E", "DD", "B", "IM", "G"};
    int n = 10;

    vector<int> vec;
    /* TODO: use an insert out of the vector class to get the integers from 
     * backup copied into vec should be done in 1 specific insert call, but 
     * make a loop if you have to.
     */
	
    vec.insert(vec.end(), &backup[0], &backup[n]);    

    cout << "\tunsorted vec print: ";
    for (int i = 0; i < 10; i++) {
        cout << vec[i] << ", ";
    }
 
    /* TODO: sort the vector using STL's sort */
    
    sort(vec.begin(), vec.end());

    cout << "\n\tsorted vec print: ";
    for (int i = 0; i < 10; i++) {
        cout << vec[i] << ", ";
    }
    cout << "\n\n";

    Student sarray[10];
    for (int i = 0; i < 10; i++) {
        sarray[i].setId(backup[i]);//initialize Student's ids from backup
        sarray[i].setName(names[i]);
    }

    cout << "Unsort Studs ";
    for (int i = 0; i < 10; i++) {
        sarray[i].print();
    }

    /* TODO: sort sarray using STL's sort, hint: you will need a predicate function */	
    sort(sarray, sarray + 10, lessThan());	
	
    cout << "\nSort Studs ";
    for (int i = 0; i < 10; i++) {
        sarray[i].print();
    }
    cout << "\n\n";


    for (int i = 0; i < 10; i++) {
        sarray[i].setId(backup[i]);//reset Student's ids from backup
    }

    /* We discussed in class that sorting students directly could be expensive
     * if they were big.  (Due to the time it takes to swap large data structs).
     * The solution is use pointers instead.
     */

    /* TODO: Declare an array of pointers to Students, name it psarray.
     * initialize the elements so that they point to the contents of sarray
     */
     Student* psarray[10];
	for(int i = 0; i < 10; i++){
		psarray[i] = &sarray[i];
	}
	
	cout << "Array of pointer: ";
	for(int i = 0; i < 10; i++){
		psarray[i]->print();
	}
	cout << endl;
    /* TODO: use STL to sort the students pointed at by psarray, hint: you need
     * a new predicate
     */
	
	sort(psarray, psarray + 10, pLessThan());
    /*This will print the students from psarray after you have correctly set it up.*/
        cout <<"sort pointer: ";
        for (int i = 0; i < 10; i++) {
            psarray[i]->print();
        }
        cout << "\n\n";
     

    /* TODO: Now figure out how to sort sarray based on the results of sorting
     * psarray notice this is printing sarray, so after sorting psarray, you 
     * need to use that info to sort sarray in O(N) time
     */
    cout << "3rd element in psarray: ";    
    psarray[3]->print();
    cout << endl;

    cout << "3rd element in sarray after setting = 3rd of psarray: ";
    sarray[3] = *psarray[3];
    sarray[3].print();
    cout << endl;

    cout << "sort Studs: ";
    for (int i = 0; i < 10; i++) {
	//Student rover = sarray[i];
	cout << "Before: ";
	sarray[i].print();
	cout << "After: ";
	sarray[i] = *psarray[i];   
        sarray[i].print();
    }
    cout << "\n\n";

    /* TODO: create another array of pointers to students that again point to
     * the students in sarray name the array psarrayN.  Then sort just the
     * pointers in DESCENDING (z to a) alphabetical order of Student's names.
     */

    /*  //This will print the students from psarrayN after you have correctly set it up.
    cout <<"sort pointer: ";
    for (int i = 0; i < 10; i++) {
        psarrayN[i]->print();
    }
    cout << "\n\n";
    */
    return 0;
}
