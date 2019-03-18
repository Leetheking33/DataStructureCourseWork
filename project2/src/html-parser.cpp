#include "html-parser.hpp"
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include <istream>
#include <cstdlib>
using namespace std;
HTMLParser::HTMLParser() {
}

HTMLParser::~HTMLParser() {
}

void HTMLParser::parse(std::string filename) {
	ifstream cin;
	std::string temp;
	char ch;
	stack<string> stack;
	mStack = stack;
	
        cin.open(filename);


        while(!cin.eof()){
                getline(cin, temp);
                for(unsigned int i = 0; i < temp.length(); i++){
                        string str = "";
                        string newStr = "";

                        if(temp[i] == '<'){

                                if(temp[i + 1] == 'a'){
                                        break;
                                }
                                else if(temp[i + 1] == '/'){
                                        for(unsigned int j = i + 1; temp[j] != '>' && j < temp.length(); j++){
                                                ch = temp[j + 1];
                                                newStr += ch;
                                        }
                                        if(newStr == mStack.top()){
                                                if(!mStack.empty())
                                                        mStack.pop();
                                        }
                                }

                                else{
                                        for(unsigned int j = i; temp[j] != '>' && j < temp.length(); j++){
                                                ch = temp[j + 1];
                                                str += ch;
                                        }
                                        mStack.push(str); //cout << str << endl;
                                }
                        }


                }
        }
	cin.close();
}

bool HTMLParser::isBalanced(std::string filename) {
	parse(filename);
	if(mStack.empty())
    		return true;
	else
		return false;
}

int HTMLParser::pageVisitAmount(std::string filename) {
	if(isBalanced(filename)){
		ifstream cin;
        	std::string temp;
        	char ch;
		int count = 0;
		cin.open(filename);


        	while(!cin.eof()){
                	getline(cin, temp);
                	for(unsigned int i = 0; i < temp.length(); i++){
                        	string str = "";
                        	string newStr = "";

                        	if(temp[i] == '<'){

                                	if(temp[i + 1] == 'a'){
                                        	for(unsigned int j = i + 7; temp[j] != 'l' && j < temp.length(); j++){
                                                	ch = temp[j + 1];
                                                	newStr += ch;
                                       		}
						newStr.insert(0, "/home/leetheking33/csci-315-spring-2019/project2/");
						ifstream file;
						file.open(newStr);
						if(file.is_open()){
							count += 1;
							file.close();
						} else
							return count;
						pageVisitAmount(newStr);
                                	}
				}
			}
		
		}
	return count;
	}
	return 0;
}
