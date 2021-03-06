#include <iostream>
#include <signal.h>
#include "tcpclient.cpp"
#include <typeinfo>
#include "json.hpp"
#include <string>
using namespace std;
using json = nlohmann::json;

TCPClient tcp;
int PORT;
bool ready = false;

void sig_exit(int s)
{
    tcp.exit();
	exit(0);
}
void setPort (int port){
    signal(SIGINT, sig_exit);
    ready = false;
    PORT = port;

}
json Execute(string Data)
{
    signal(SIGINT, sig_exit);
    if (ready == false) {
        tcp.setup("127.0.0.1",PORT);
        ready = true;
    }
    tcp.Send(Data);

    string rec = tcp.receive();
    auto j3 = json::parse (rec);
    cout << j3 << endl;

    return j3;

}
json Get (string label){
    signal(SIGINT, sig_exit);
    if (ready == false) {
        tcp.setup("127.0.0.1",PORT);
        ready = true;
    }
    tcp.Send("Get this: "+label);

    string rec = tcp.receive();

    auto j3 = json::parse (rec);
    return j3;
}

void Reset (){
    signal(SIGINT, sig_exit);
    if (ready == false) {
        tcp.setup("127.0.0.1",PORT);
        ready = true;
    }
    tcp.Send("Reset");
}
