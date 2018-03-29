#ifndef PARSEREXCEPTION_H
#define PARSEREXCEPTION_H
#include <iostream>

using namespace std;
class ParserException: public std::exception{
    int m_Pos;
public:
    ParserException(const std::string& message, int pos){


    }
};

#endif // PARSEREXCEPTION_H
