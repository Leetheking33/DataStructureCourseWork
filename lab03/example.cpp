#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	int x = 7;
	int arr[5]={0, 10, 20, 30, 40};
	
	// #1. declares a pointer p1 that is pointing at x 
	int *p1 = &x;
	cout << *p1 << endl;
	
	// #2.changes val of x to 33 w/o using x
	*p1 = 33;
	cout << x << endl;
	
	// #3. declares point p2 that points to 1st item in arr
	int *p2 = arr;	
	cout << *p2 << endl;
	
	// #4. changes 1st item in arr to 5 w/o using arr
	*p2 = 5;
	cout << arr[0] << endl;
	
	// #5. Changes 3rd val in arr to 15 without using arr
	p2[2] = 15;
	cout << arr[2] << endl;
	
	// #6. changes the 4th val of arr to 35 without using arr or []
        *(p2 + 3) = 35;
	cout << arr[3] << endl;
	
	// print memory location p2 points to
	cout << p2 << endl;
	
	// prints memory location of 3rd val in arr
	cout << &arr[2] << endl;
	
	// #7. changes the the memory location p2 is pointing to from the 1st 
	// element in arr to the memory location of the 3rd element in arr w/o
	// using arr
	p2 = (p2 + 2);
	cout << p2 << endl;

	// #8. changes the item pointed at by p2 to 77 w/o using arr 
	*p2 = 77;
        cout << arr[2] << endl;	

	// #9. boolean expression that returns true iff p3 and p4 are pointing
	// to an equvalent val
	int a = 5;
	int b = 5;
	int *p3 = &a;
	int *p4 = &b;
	
	cout << "p3 location " << p3 << " p4 location " << p4 << endl;

	if (*p3 == *p4)
		cout << "true" << endl;

	// #10. bool expression that returns true iff p5 and p6 are pointing
	// to the exact same location
	
	int *p5 = arr;
        int *p6 = arr;

	if (p5 == p6)
                cout << "true" << endl;

	// #11. makes p1 point to a dynamically allocated interger
	int *c = new int;
	*c = 5;
	p1 = c;
	
	cout << *p1 << endl;
	
	// #12. Free memory at p1
	delete p1;

	// #13. Makes p1 point to a dynamically allocated array of x ints
	int *ar = new int[x]; 
	for (int i=0; i < x; i++){
		ar[i] = 0;
	}
	
	cout << "First val in ar " << ar[0] << endl;

	p1 = ar;

	cout << "Print *p1 " << *p1 << endl;

	// #14. free memory at p1
	delete p1;
	

	return 0;


}
