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
json Var;
void *Memorymap;
void *Currentposition;
void *Two;
int first = 0;
json convert (json info){
    string label = info["label"];
    info.erase("label");
    json nuevo;
    nuevo[label] = info;
    return nuevo;
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
                cout << "New Variable: " << str << endl;
                // Analizar str a json osea convertir un str a json
                auto j3 = json::parse (str);
                j3 = convert(j3);
                Var.merge_patch(j3);

                tcp.Send(Var.dump());
                tcp.clean();
        }
        usleep(1000);
}
        tcp.detach();
        }

void* TYPES (json info){
    int tipo = info["type"];
    switch (tipo) {
    case 1: //Caso para int
    {
        int *entero = (int*)Currentposition+first;
        *entero = info["value"];
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
        *flotante = info["value"];
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
        *doble = info["value"];
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
string getDirection(void *direction) {
    // Obtener dirección de memoria
    ostringstream oss;
    oss << (void const*)(int*)(direction);
    string d = oss.str();
    cout << "This is direction: " <<d << endl;
    return d;
}
int main(int argc, char *argv[]) {
        QCoreApplication a(argc, argv);

        cout << "Ingrese el Puerto" << endl;
        cin >> PORT;
        cout << "Ingrese el tamaño de la memoria en Bytes " << endl;
        cin >> SIZE;

        // Unico Malloc de la memoria
        Memorymap = (void*) malloc (SIZE);
        Currentposition = Memorymap;

        //Solictud de memoria
        json uno;
        uno ["type"] = 3;
        uno ["value"] = 5.2;


        float *var1 = (float*)TYPES(uno);
        cout << *var1 << endl;
        uno ["direction"] = getDirection(var1);
         Var["Número flotante"] = uno;
        //Recorrer un json
        //json rp;
        //rp["This"] = "Hola";
        //for (auto it = rp.begin(); it != rp.end();++it){
        //   cout <<  it.key() << endl;
        //}



        // Ejecución del Servidor con el loop
        pthread_t msg;
        tcp.setup(PORT);
        cout << "A la espera de un cliente" << endl;
        if( pthread_create(&msg, NULL, loop, (void *)0) == 0)
        {
                tcp.receive();
        }
        return a.exec();
}



