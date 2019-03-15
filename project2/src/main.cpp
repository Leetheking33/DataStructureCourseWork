#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;

main(){

	string s;
	ifstream cin;
	cin.open("notbalance.txt");

	getline(cin, s);

	cout << "This is string " << s << endl;
	cin.close();
	return 0;
}
