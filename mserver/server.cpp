#include <iostream>
#include <string>
#include <fstream>
#include "tcpserver.cpp"
#include <QCoreApplication>
#include <QInputDialog>
#include <orderram.h>
#include <json.hpp>
using json = nlohmann::json;
using namespace std;
TCPServer tcp;
int PORT;
int SIZE;
void *Memorymap;
void *Currentposition;
void *Two;
int first = 0;
int convert (string str){


    return 0;
}

void Memory (){

}
void *loop (void *m) {

    pthread_detach(pthread_self());
    while (true){
        srand (time (NULL));
        char ch = 'a' + rand () % 26;

        string s(1,ch);
        string str = tcp.getMessage();
        if( str != "" )
        {
                cout << "Cliente Conectado" << endl;
                cout << "New Variable: " << str << endl;
                tcp.Send(str);
                tcp.clean();
        }
        usleep(1000);
}
        tcp.detach();
        }

void* TYPES (int type){

    switch (type) {
    case 1: //Caso para int
    {
        int *entero = (int*)Currentposition+first;
        Two = Currentposition;
        Currentposition = entero;
        if (first == 0){
            Currentposition = Currentposition+4;
        }
        first=1;


        return Two;
        break;
    }
    case 2: //Caso para char
    {
        char* arreglo = (char*)Currentposition+first;
        Two = Currentposition;
        Currentposition = arreglo;
        if (first == 0){
            Currentposition = Currentposition+1;
        }
        first=1;


        return Two;
        break;
    }
    case 3: //Caso para float
    {
        float* flotante = (float*)Currentposition+first;
        Two = Currentposition;
        Currentposition = flotante;
        if (first == 0){
            Currentposition = Currentposition+4;
        }
        first=1;


        return Two;
        break;
    }
    case 4: //Caso double
    {
        double *doble = (double*)Currentposition+first;
        Two = Currentposition;
        Currentposition = doble;
        if (first == 0){
            Currentposition = Currentposition+8;
        }
        first=1;
        return Two;
        break;
    }
    case 5: // Caso long
    {
        long *larg = (long*)Currentposition+first;
        Two = Currentposition;
        Currentposition = larg;
        if (first == 0){
            Currentposition = Currentposition+8;
        }
        first=1;
        return Two;
        break;
    }
    }

}
int main(int argc, char *argv[]) {
        QCoreApplication a(argc, argv);

        cout << "Ingrese el Puerto" << endl;
        cin >> PORT;
        cout << "Ingrese el tamaño de la memoria en Bytes " << endl;
        cin >> SIZE;
        // Unico Malloc de la memoria
        Memorymap = (void*) malloc (sizeof(void)+SIZE);
        pthread_t msg;
        Currentposition = Memorymap;
        cout << TYPES(5) << endl;
        cout << TYPES(1) << endl;
        cout << TYPES(3) << endl;
        cout << TYPES(2) << endl;
        cout << TYPES(5) << endl;
        cout << TYPES(1) << endl;
        cout << TYPES(1) << endl;

        cout << Memorymap << endl;

        tcp.setup(PORT);
        cout << "A la espera de un cliente" << endl;
        if( pthread_create(&msg, NULL, loop, (void *)0) == 0)
        {
                tcp.receive();
        }
        return a.exec();
}


