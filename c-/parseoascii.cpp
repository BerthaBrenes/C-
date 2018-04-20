#include "parseoascii.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

parseoASCII::parseoASCII(const char* text1)
{
    text = text1;

}

int parseoASCII::convert()
{
    int result = 0;
    for(int i = 0; text[i];i++){
        result = result +(int)text[i];
    }
    cout<<result<<endl;
    return result;

}

double parseoASCII::charToint(char *num1)
{
    int exc = largochar(num1);
    cout<<"largo"<<exc<<endl;
    double result = 0;
    int a =0;
    double b = 0;
    for(int i =0; num1[i];i++)
    {
        b = auxlargochar(num1[i]);
        a = b* pow(10,exc-1);
        result = result +a;
        a,b =0;
        exc--;
    }
    return result;
}

int parseoASCII::largochar(char *num)
{
    int largo = 0;
    for(int i= 0; num[i];i++){
        largo++;
    }
    return largo;
}

double parseoASCII::auxlargochar(int num1)
{
    switch(num1){
        case 48:
            return 0;
        case 49:
            return 1;
        case 50:
            return 2;
        case 51:
            return 3;
        case 52:
            return 4;
        case 53:
            return 5;
        case 54:
            return 6;
        case 55:
            return 7;
        case 56:
            return 8;
        case 57:
            return 9;
    }

}

parseoASCII::parseoASCII()
{

}
/**int a =0;
        for(int i = 0; num1[i];i++){
            int b = (int)num1[i];
            cout<<"b: "<<b<<endl;
            a = (num1[i])*(pow(10,exc));
            cout<<"Valor de num"<<num1[i]<<endl;
            cout<<"Valor de poe"<<(pow(10,exc))<<endl;
            cout<<"Valor de a "<<a<<endl;
            result = result +a;
            exc--;
            a =0;
            **/
