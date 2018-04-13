#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>
#include <fstream>
#include "tcpserver.cpp"
#include <QCoreApplication>
#include <QInputDialog>
#include <orderram.h>
using namespace rapidjson;
using namespace std;
TCPServer tcp;
int PORT;
int SIZE;
void *Memorymap;
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


int main(int argc, char *argv[]) {
        QCoreApplication a(argc, argv);

        cout << "Ingrese el Puerto" << endl;
        cin >> PORT;
        cout << "Ingrese el tamaño de la memoria" << endl;
        cin >> SIZE;
        Memorymap = (void*) malloc (SIZE);
        cout << sizeof (Memorymap) << " Bytes" << endl;
        pthread_t msg;
        tcp.setup(PORT);
        Document json;
        json.Parse ("{\"Uno\" : \"gg\"}");
        cout << json["Uno"].GetString() << endl;
        cout << "A la espera de un cliente" << endl;
        if( pthread_create(&msg, NULL, loop, (void *)0) == 0)
        {
                tcp.receive();
        }
        return a.exec();
}

