#include <sstream>
#include "html-parser.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <istream>
#include <cstdlib>
using namespace std;

std::string trim(std::string const& str) {
    std::string word;
    std::stringstream stream(str);
    stream >> word;

    return word;
}

main(int argc, char *argv[]){

	std::string programName = trim(argv[0]);
    	HTMLParser htmlParser;

	// First we parse each page
    	for (int i = 1; i < argc; i++) {
        	// get each argument to the program.
        	std::string htmlpage = argv[i];
		
        	// If the argument is not the program
        	size_t pos = htmlpage.find(programName);
        	if (pos == std::string::npos) {
            		// then ask to parse the HTML page.
            		std::cout << "Parsing: '" << htmlpage << "'\n";
            		htmlParser.parse(htmlpage);
        	}
    	}

	// Second we print the results
    	for (int i = 1; i < argc; i++) {
        	// get each argument to the program.
        	std::string htmlpage = argv[i];

        	// If the argument is not the program
        	size_t pos = htmlpage.find(programName);
        	if (pos == std::string::npos) {
            		/* then print out if it is balanced and number of web pages
             		* that can be visited from the page
             		*/
            		std::cout << htmlpage << " is " << (htmlParser.isBalanced(htmlpage) ? "" : "not ") << "balanced." << "\n";
            		std::cout << htmlpage << " can visit " << htmlParser.pageVisitAmount(htmlpage) << " pages.\n";
		}
	}
	return 0;
}

	/*
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
				else if(temp[i + 1] == '/'){
					for(unsigned int j = i + 1; temp[j] != char(32) && j < temp.length(); j++){
						ch = temp[j + 1];
						newStr += ch;
					}
					if(newStr == tags.top()){
						if(!tags.empty())
							tags.pop();
					}
				}
						
				else{
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
		cout << "File is balanced" << endl;
	} else
		cout << "File is not balenced" << endl;
		
	//cout << "Stacks top: " << tags.top() << endl;
	//cout << temp << endl;
	//cout << s << endl;
	//getline(cin, s, '>');
	//cout << s << endl;
	if(ch == '<'){
		cout << "found beginning of a tag." << endl;
	} else 
		cout << "no tag found." << endl;
	*/
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
	
