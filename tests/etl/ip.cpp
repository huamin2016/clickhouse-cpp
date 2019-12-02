#include <arpa/inet.h>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Ip {
public:
    unsigned int start;
    unsigned int end;
    string country;
    string province;

    friend bool operator<(const Ip& ip1, const Ip& ip2) { return ip1.start < ip2.start; }

public:
    Ip(int start, int end, string country, string province);
    void tostring();
};

Ip::Ip(int start, int end, string country, string province) : start(start), end(end), country(country), province(province) {
}

void Ip::tostring() {
    cout << start << "|" << end << "|" << country << "|" << province << endl;
}

set<Ip> ips;

Ip* defIp = new Ip(0, 0, "", "");

int init(string ipFile) {
    cout << ipFile << endl;
    return 0;
}

Ip* getIp(const char* ip) {
    int ipNum = inet_addr(ip);
    cout << ip << " -> " << ipNum << endl;
    return defIp;
}

int main() {
    init("ipv4.txt");
    Ip* t = new Ip(1, 1, "a", "b");
    t->tostring();
    defIp->tostring();
    string a="123";
    Ip* res=getIp(a.c_str());
    res->tostring();

    cout<<a.c_str()<<endl;
    return 0;
}
