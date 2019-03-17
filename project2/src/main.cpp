#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <istream>
#include <cstdlib>
using namespace std;

main(){

	std::string s;
	stack<string> tags;
	char ch;
	std::string temp;
	//char_type hold;
	ifstream cin;
	cin.open("/home/leetheking33/csci-315-spring-2019/project2/pages/index.html");

	cout << s << endl;

	while(!cin.eof()){
		getline(cin, temp);
		for(unsigned int i = 0; i < temp.length(); i++){
			string str = "";
			string newStr = "";

			if(temp[i] == '<'){

				if(temp[i + 1] == 'a'){
					break;
				}
				if(temp[i + 1] == '/'){
					for(unsigned int j = i + 1; temp[j] != char(32) && j < temp.length(); j++){
						ch = temp[j + 1];
						newStr += ch;
					}
					if(newStr == tags.top()){
						tags.pop();
					}
						
				} else{
					for(unsigned int j = i; temp[j] != char(32) && j < temp.length(); j++){
						ch = temp[j + 1];
						str += ch;
					}
					tags.push(str); //cout << str << endl;
				}
			} 

		}
		
	}
	if(tags.empty()){
		tags.top() = "";
	}
	cout << "Stacks top: " << tags.top() << endl;
	//cout << temp << endl;
	//cout << s << endl;
	//getline(cin, s, '>');
	//cout << s << endl;
	if(ch == '<'){
		cout << "found beginning of a tag." << endl;
	} else 
		cout << "no tag found." << endl;
	
	//temp = cin.get(hold);
	//s.append(temp);
	/*
	while(!cin.eof()){
		cin.get(temp);
		s.append(temp);	
	}
	*/
	//cout << "This is string " << s << endl;
	//cin.close();
	return 0;
}
