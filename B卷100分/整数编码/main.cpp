//
//  main.cpp
//  ODTest3
//
//  Created by YuChao on 2023/6/1.
//

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <regex>
#include <iomanip>


using namespace std;

// 整数编码
// 实现一种整数编码方法，使得待编码的数字越小，编码后所占用的字节数越小。

char getCharInt(int c) {
    string str = "0123456789ABCDEF";
    return str[c];
}

string getInt2(int num, int n) {
    string str;
    while (num > 0) {
        int c = num % n;
        str += getCharInt(c);
        num /= n;
    }
    reverse(str.begin(), str.end());
    return str;
}

int getInt10(string str, int n) {
    int number = 0;
    for (int i = 0; i < str.length(); i++) {
        number *= n;
        number += str[i] - '0';
    }
    return number;
}

string getResult(int n) {
    
    string tmp2 = getInt2(n, 2);
    
    int end = (int)tmp2.length();
    string ans;
    while (end > 7) {
        string tmp = tmp2.substr(end - 7,end);
        tmp = "1" + tmp;
        int number = getInt10(tmp, 2);
        string res = getInt2(number, 16);
        ans += res;
        end -=7;
    }
    
    if (end >=0) {
        string tmp = tmp2.substr(0,end);
        int number = getInt10(tmp, 2);
        string res = getInt2(number, 16);
        while (res.length() < 2) {
            res = "0" + res;
        }
        ans += res;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    

    cout << getResult(n) << endl;
//
    return 0;
}




