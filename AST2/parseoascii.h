#ifndef PARSEOASCII_H
#define PARSEOASCII_H


class parseoascii
{
public:
    parseoascii();
    int convert();
    double charToint(char* num);
    int largochar(char* num);
    double auxlargochar(int num);
    const char* text;
    parseoascii(const char* text);
};

#endif // PARSEOASCII_H
