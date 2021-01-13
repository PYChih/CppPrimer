// Exercise 12.15:
//  Rewrite the first exercise to use a lambda (10.3.2, p.388) in place of the end_connection function.
#include <iostream>
#include <memory>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;

struct connection {
    string ip;
    int port;
    connection(string ip_, int port_):ip(ip_), port(port_){}
};
struct destination {
    string ip;
    int port;
    destination(string ip_, int port_) : ip(ip_), port(port_){}
};

connection connect(destination* pDest)
{
    shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
    cout<<"creating connection(" << pConn.use_count() << ")" << std::endl;
    return *pConn;
}

void disconnect(connection pConn)
{
    cout << "connection close(" << pConn.ip << ":" << pConn.port << ")" << endl;
}

void end_connection(connection *pConn)
{
    disconnect(*pConn);
}

void f(destination &d)
{
    connection conn = connect(&d);
    shared_ptr<connection> p(&conn, [](connection *p){disconnect(*p);});
    cout << "connecting now(" << p.use_count() << ")" << endl;
}

int main()
{
    destination dest("123.456.789", 9527);
    f(dest);
}

