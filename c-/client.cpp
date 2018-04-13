#include <iostream>
#include <signal.h>
#include "tcpclient.cpp"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
TCPClient tcp;
using namespace rapidjson;
int PORT;
void setPort (int port){
    PORT = port;
}
void sig_exit(int s)
{
    tcp.exit();
	exit(0);
}
string Execute(string Data)
{
    signal(SIGINT, sig_exit);
    tcp.setup("127.0.0.1",PORT);
    tcp.Send(Data);

    string rec = tcp.receive();


    return rec;

}

