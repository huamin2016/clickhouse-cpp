#include <arpa/inet.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main() {
    //将整数IP转换为字符串表示的IP
    int ipInt = inet_addr("192.168.1.2");

    int dwAddr = inet_addr("127.0.0.1");
    cout << "ipInt:" << ipInt << " NO1 :IP的整数形式 " << dwAddr << endl;

    //将字符串形式的IP转换为整数形式表示，方法一
    struct in_addr inAddr;
    inAddr.s_addr = dwAddr;
    cout << "NO2: IP的字符串形式 " << inet_ntoa(inAddr) << endl;

    //将字符串形式的IP转换为整数形式表示，方法二
    unsigned char* pch = (unsigned char*)&dwAddr;
    char szIPAddr[64]  = {0};
    sprintf(szIPAddr, "%d.%d.%d.%d", *pch, *(pch + 1), *(pch + 2), *(pch + 3));
    cout << "NO3: IP的字符串形式 " << szIPAddr << endl;

    return 1;
}
