#include <iostream>
#include <signal.h>
#include "tcpclient.cpp"

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
string Execute(string Data)
{
    signal(SIGINT, sig_exit);
    if (ready == false) {
        tcp.setup("127.0.0.1",PORT);
        ready = true;
    }
    tcp.Send(Data);

    string rec = tcp.receive();


    return "Data received: " +rec;

}
