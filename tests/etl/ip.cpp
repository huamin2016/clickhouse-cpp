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
};

Ip::Ip(int start, int end, string country, string province) : start(start), end(end), country(country), province(province) {
}

set<Ip> ips;

Ip * defIp = new Ip(0, 0, "", "");

int init(string ipFile) {
    cout << ipFile;
    return 0;
}

Ip* getIp(char* ip) {
    int ipNum = inet_addr(ip);
    cout << ip << " -> " << ipNum << endl;
    return defIp;
}

int main() {
    init("ipv4.txt");
   // Ip * res=getIp("123".c_str());
    //cout<< res->country<<endl;
    return 0;
}
