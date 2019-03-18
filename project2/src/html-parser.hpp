#ifndef HTML_PARSER_HPP
#define HTML_PARSER_HPP

#include <string>
#include <stack>
#include <iostream>
using namespace std;
class HTMLParser {
	private:
		stack<string> mStack;	
    public:
        HTMLParser();
        ~HTMLParser();
        void parse(std::string filename);
        bool isBalanced(std::string filename);
        int pageVisitAmount(std::string filename);
};

#endif
