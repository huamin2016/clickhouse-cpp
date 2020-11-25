
#include <3rd/libconfig.h++>
#include <lz4/lz4.h>
#include <cstring>
#include <iostream>

using namespace std;
using namespace libconfig;

void test_libconfig() {
	
	Config conf;
    conf.readFile("conf.txt");
    string name=conf.lookup("name");
    cout << "name:" << name << endl;
    
}

int main() {
    test_libconfig();
    return 0;
}