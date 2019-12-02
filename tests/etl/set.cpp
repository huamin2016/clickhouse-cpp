#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
struct student {
    string name;
    int score;

    friend bool operator<(const student& stu1, const student& stu2) { return stu1.score < stu2.score; }
};

int main() {
    // vector<student> vectorStudents;
    set<student> setStudents;
    // int n = 5;
    int n = 6;
    while (n--) {
        student oneStudent;
        string name = "stu" + to_string(n);
        int score   = n*2;
        // cin >> name >> score;
        // strcpy(oneStudent.name, name.c_str());
        oneStudent.name  = name;
        oneStudent.score = score;
        setStudents.insert(oneStudent);
    }

    /*
    cout << "===========排序前================" << endl;
    for (set<student>::iterator it = setStudents.begin(); it != setStudents.end(); it++) {
        cout << "name: " << it->name << " score: " << it->score << endl;
    }
    */

    // sort(setStudents.begin(), setStudents.end(), comp);

    cout << "===========排序后================" << endl;
    for (set<student>::iterator it = setStudents.begin(); it != setStudents.end(); it++) {
        cout << "name: " << it->name << " score: " << it->score << endl;
    }
    student t1;
    t1.score                   = 3;
    set<student>::iterator res = setStudents.lower_bound(t1);
    bool isNull                = setStudents.end() == res;
    if (isNull) {
        cout << "not find" << endl;
    } else {
        cout << "find ok " << res->name << endl;
    }

    // string res=setStudents.lower_bound(t1)->name;
    // cout << "-->" << res;

    return 0;
}
