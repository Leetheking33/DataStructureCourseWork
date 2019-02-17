#ifndef HTML_PARSER_HPP
#define HTML_PARSER_HPP

#include <string>

class HTMLParser {
    public:
        HTMLParser();
        ~HTMLParser();
        void parse(std::string filename);
        bool isBalanced(std::string filename);
        int pageVisitAmount(std::string filename);
};

#endif
