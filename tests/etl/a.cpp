#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(3);
    t.push_back(4);
    t.push_back(6);
    t.push_back(7);
    t.push_back(8);

    int low = lower_bound(t.begin(), t.end(), 5) - t.begin();
    int upp = upper_bound(t.begin(), t.end(), 5) - t.begin();
    cout << low << endl;
    cout << upp << endl;
    return 0;
}
