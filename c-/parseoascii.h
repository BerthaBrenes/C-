#ifndef PARSEOASCII_H
#define PARSEOASCII_H


class parseoASCII
{
public:
    const char* text;
    parseoASCII(const char* text);
    int convert();
    double charToint(char* num);
    int largochar(char* num);
    double auxlargochar(int num);
    parseoASCII();
};

#endif // PARSEOASCII_H
