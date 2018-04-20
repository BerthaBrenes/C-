#include <iostream>
#include <signal.h>
#include <tcpclient.h>
#include <typeinfo>
#include "json.hpp"
#include <string>
using namespace std;
using json = nlohmann::json;

TCPClient tcp;
int PORT;
bool ready = false;


void setPort (int port){
    PORT = port;
}
void sig_exit(int s)
{
    tcp.exit();
	exit(0);
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

}
