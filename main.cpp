#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkWord( string filename,  string search){
	
	int offset;
	string line;
	ifstream Myfile;
	Myfile.open (filename);

	if(Myfile.is_open()){
		while(!Myfile.eof()){
			getline(Myfile,line);
			if((offset = line.find(search, 0)) != string::npos){
				cout << endl << "\"" << search << "\"" << " was found in " << "\"" << filename << "\"." << endl;
				return true;
			}
			else{
				continue;
			}

		}
		Myfile.close();
		cout << endl << "\"" << search << "\"" << " was not found in " << "\"" << filename << "\"." << endl;
	}
	else
		cout << "Unable to open this file." << endl;

	return false;
}

inline bool exists_test(string name){
	if(FILE *file = fopen(name.c_str(), "r")) {
		fclose(file);
		return true;
	}
	else {
		return false;
	}
}

int main(){

	string filename;
	string val;

	cout << "Enter the name of the file: ";
	cin >> filename;
	cout << endl;
	
	if(exists_test(filename)){

		cout << "Enter a value to search for: ";
		cin >> val;

		checkWord(filename, val);
	}
	else{
		cout << "Could not open \"" << filename << "\"." << endl;
	}
	return 0;
}
