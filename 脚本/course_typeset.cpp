/*
jisuanke 教学文案排版辅助工具。
实现了数字，英文字母前后加空格，数字前后加 $，加粗文字前后加空格等功能。
*/

#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
const int N = 1000010;
char str[N];
int flag;

int jud(char c, char p) {
    if (c == '-' && p == '-') return 0;
    if (c == '-' && p == '\0') return 0;
    if (c == '#' && p == ' ') return 0;
    if (c == '#' && p == '#') return 0;
    if (c == '-' && isdigit(p)) return 2;
    if (isdigit(c)) return 2;
    if (c == '>' || c == '<') return 1;
    if (c == '(' || c == ')') return 1;
    if (c == '[' || c == ']') return 1;
    if (c == '{' || c == '}') return 1;
    if (c == '+' || c == '-' || c == '*' || c == '\\' || c == '=') return 1;
    if (isalpha(c)) return 1;
    if (c == ';' || c == '!' || c == '.' || c == ',') return 1;
    if (c == '&' || c == '_') return 1;
    if (c == '#') return 1;
    if (c == '*' || c == '\\') return 1;
    return 0;
}

int main (int argc, char *argv[]) {
    ifstream fin;
    fin.open(argv[1], ios::in);
    ofstream fout;
    fout.open("output.txt", ios::out);
    flag = 0;
    int vis = 0;
    int cc = 0;
    int xx = 0;
    while(fin.getline(str, N, '\n')) {
        int len = (int)strlen(str);
        if (str[0] == '!' && str[1] == '[') {
            fout << str << endl;
            continue;
        }
        if (str[0] == '#' && str[1] == '#' && str[2] == '#' &&  strcmp(str + len - 3, "：") == 0) {
            str[len - 3] = '\0';
            fout << str << endl;
            continue;
        }
        if (strcmp(str, "```c++") == 0) {
            vis = 1;
            flag = 1;
            fout << str << endl;
            continue;
        }
        if (strcmp(str,"```") == 0) {
            vis = 1;
            if (flag == 0) {
                fout << "```c++" << endl;
                flag = 1;
            } else {
                fout << "```" << endl;
                flag = 0;
            }
            continue;
        }
        if (flag == 1) {
            fout << str << endl;
            continue;
        }
        if (vis == 0) {
            fout << str << endl;
            continue;
        }
        for (int i = 0; i < len; i++) {
            if (str[i] == '*' && str[i + 1] == '*') {
                fout << "**";
                i++;
                continue;
            }
            if (str[i] == '`') {
                if (cc == 0 && str[i - 1] != ' ' && str[i - 1] != '*') fout << " ";
                fout << str[i];
                if (cc == 1 && str[i + 1] != ' ' && str[i + 1] != '*') fout << " ";
                cc = (cc + 1) % 2;
                continue;
            }
            if (str[i] == '$') {
                if (xx == 0 && str[i - 1] != ' ' && str[i - 1] != '*') fout << " ";
                fout << str[i];
                if (xx == 1 && str[i + 1] != ' ' && str[i + 1] != '*') fout << " ";
                xx = (xx + 1) % 2;
                continue;
            }
            int res = jud(str[i], str[i + 1]);
            if (res  == 0 || cc == 1 || xx == 1) {
                fout << str[i];
                continue;
            }
            if (res == 1) {
                fout << "`";
                while (jud(str[i], str[i + 1]) > 0 || (str[i] == ' ' && jud(str[i + 1], str[i + 2]) > 0)) {
                    fout << str[i];
                    i++;
                }
                fout << "`";
            } else if (res == 2) {
                fout << "$";
                while (jud(str[i], str[i + 1]) > 0 || (str[i] == ' ' && jud(str[i + 1], str[i + 2]) > 0)) {
                    fout << str[i];
                    i++;
                }
                fout << "$";
            }
            i--;
        }
        fout << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
