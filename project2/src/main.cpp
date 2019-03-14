#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <cstdlib>
using namespace std;

main(){

	string s;
	ifstream in;
	in.open("//notbalance.txt");

	getline(in, s);

	cout << "This is string " << s << endl;
	in.close();
	return 0;
}
