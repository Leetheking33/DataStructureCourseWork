#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	int x = 7;
	int arr[5]={0, 10, 20, 30, 40};

	int *p1 = &x;
	cout << *p1 << endl;

	*p1 = 33;
	cout << x << endl;
	
	int *p2 = arr;	
	cout << *p2 << endl;
	
	*p2 = 5;
	cout << arr[0] << endl;

	p2[2] = 15;
	cout << arr[2] << endl;

       cout << (void*)(p2) << endl;
	cout << &arr[3] << endl;
	return 0;




}
