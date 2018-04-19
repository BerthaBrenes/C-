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

int Current_oofset = 0;
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

int typeget (string info){
    if (info.find("Get this: ")>info.length()){
        return 0;
    }else if (info.find("Size")<=info.length()){
        return 2;
    }
    else {
        return 1;
    }
}
void set_on_memory (json info){

}
void *TYPES(json info);
string getDirection(void *direction);
void *loop (void *m) {

    pthread_detach(pthread_self());

    while (true){
        srand (time (NULL));
        char ch = 'a' + rand () % 26;

        string s(1,ch);
        string str = tcp.getMessage();
        if( str != "" )
        {
            if (typeget(str) == 1){
                string variable = str.substr(10, str.length());
                tcp.Send(Var[variable].dump());
                tcp.clean();
            }
            else {
                cout << "New Variable: " << str << endl;
                // Analizar str a json osea convertir un str a json
                auto j3 = json::parse (str);

                j3["direction"] = getDirection(TYPES(j3));
                j3["offset"] = Current_oofset;
                j3 = convert(j3);
                Var.merge_patch(j3);
                cout << Var << endl;
                tcp.Send(Var.dump());
                tcp.clean();
            }
        }
        usleep(1000);
}
        tcp.detach();
        }
bool exist  (json info) {
    string t = info["label"];

    if (Var[t].is_null())

        return 0;

   else{
        return 1;
    }
}
void* TYPES (json info){
    string tipo = info["type"];

    if (exist(info)){
        string var = info["label"];
        Var[var]["value"] = info["label"];
        return Memorymap + (int)Var[var]["offset"];
    }else{
    if (tipo == "int") //Caso para int
    {
        int *entero = (int*)Currentposition+first;
        *entero = (int)info["value"];
        Two = Currentposition;

        Currentposition = entero;
        if (first == 0){
            Currentposition+=(int)info["size"];

        } else {
            Current_oofset+=(int)info["size"];
        }
        first=1;

        return Two;
    }
    else if (tipo ==  "char") //Caso para char
    {
        char* arreglo = (char*)Currentposition+first;
        Two = Currentposition;
        Currentposition = arreglo;
        if (first == 0){
            Currentposition+=(int)info["size"];
        } else {
            Current_oofset+=(int)info["size"];
        }
        first=1;
        return Two;
    }
    else if (tipo == "float") //Caso para float
    {
        float* flotante = (float*)Currentposition+first;
        *flotante = (float)info["value"];
        Two = Currentposition;

        Currentposition = flotante;
        if (first == 0){
            Currentposition+=(int)info["size"];
        } else {
            Current_oofset+=(int)info["size"];
        }
        first=1;

        return Two;
    }
    else if( tipo == "double" )//Caso double
    {
        double *doble = (double*)Currentposition+first;
        *doble = (double)info["value"];
        Two = Currentposition;
        Currentposition = doble;
        if (first == 0){
            Currentposition+=(int)info["size"];
        } else {
            Current_oofset+=(int)info["size"];
        }
        first=1;
        return Two;
    }
    else if (tipo == "long") // Caso long
    {
        long *larg = (long*)Currentposition+first;
        *larg = (long)info["value"];
        Two = Currentposition;
        Currentposition = larg;
        if (first == 0){
            Currentposition+=(int)info["size"];
        } else {
            Current_oofset+=(int)info["size"];
        }
        first=1;
        return Two;
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
        uno ["type"] = "float";
        uno ["value"] = 5.2;
        uno ["size"] = 4;
        uno ["label"] = "Número flotante";
        uno ["countr"] = 1;

        float *var1 = (float*)TYPES(uno);

        uno ["offset"] = Current_oofset;


        uno ["direction"] = getDirection(var1);
        uno.erase ("label");
        Var["Número flotante"] = uno;


        json dos;
        dos ["type"] = "int";
        dos ["value"] = 3;
        dos ["size"] = 4;
        dos ["label"] = "Número entero";
        dos["countr"] = 1;

        int *var2 = (int*)TYPES (dos);

        dos["offset"] = Current_oofset;


        dos ["direction"] = getDirection(var2);
        dos.erase ("label");
        Var["Número entero"] = dos;

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



