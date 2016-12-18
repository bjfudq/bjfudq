/*
   cpp 伴随课转出 c 的辅助工具。完成初始化等以下功能：
   1. 将所有的 cpp 替换成 c
   2. 将所有的 c++ 替换成 c
   3. 只保留初始化代码，删除所有的伴随代码
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    string file = argv[1];
    ifstream fin(file);
    string tmp, str = "";
    int ci = 0, flag = 0;
    while (getline(fin, tmp)) {
        if (tmp == "#### 代码") {
            str = str + "#### 代码\n";
            flag = 1;
            continue;
        }
        if (tmp == "```c++") {
            str = str + "```c\n";
            continue;
        }
        if (tmp == "```") {
            flag = 0;
            str = str + "```\n";
            continue;
        }
        if (flag == 0) {
            int pos = tmp.find("cpp");
            if (pos != string::npos) {
                tmp = tmp.replace(pos, 3, "c");
            }
            str = str + tmp + "\n";
        }
    }
    fin.close();

    ofstream fout(file);
    fout << str;
    fout.close();

    cout << "done!" << endl;
    return 0;
}
