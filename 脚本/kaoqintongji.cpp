/*
统计考勤工具。
按提示输入天，最后按格式输出。
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, month1, month2;
    vector<int>v1, v2;
    v1.clear();
    v2.clear();
    cout << "input month1: ";
    cin >> month1;
    cout << "input days:" << endl;
    while (cin >> a) {
        if (a < 1 || a > 31) break;
        v1.push_back(a);
    }
    cout << "input month2: ";
    cin >> month2;
    cout << "input days:" << endl;
    while (cin >> a) {
        if (a < 1 || a > 31) break;
        v2.push_back(a);
    }
    for (int i = 0; i < v1.size(); i++) {
        cout << month1 << "." << v1[i] << ",";
    }
    for (int i = 0; i < v2.size(); i++) {
        if (i) cout << ",";
        cout << month2 << "." << v2[i];
    }
    cout << endl << "tot: " << v1.size() + v2.size() << " days." << endl;
    return 0;
}
