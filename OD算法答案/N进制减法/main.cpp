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

using namespace std;

// N进制减法
// 主管期望你实现一个基于字符串的N进制的减法。

bool isValid(string str,int n) {
    if (str[0] == '0' && str != "0") {
        return false;
    }
    for (char c: str) {
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))) {
            return false;
        }
    }
    if (str.length() > 100) {
        return false;
    }
    for (char c : str) {
        if (c >= '0' && c <= 9 && c + '0' >= n) {
            return false;
        }
        if (c >= 'a' && c <= 'z' && c - 87 >= n) {
            return false;
        }
    }
    return true;
    
}

// 进制转换
int charInt(char target) {
    if (target >= '0' && target <= '9') {
        return target - '0';
    } else {
        return target - 'A' + 10;
    }
}

long coverM2T(string str,int m) {
    long number = 0;
    for (int i = 0; i < str.length(); i++) {
        number *= m;
        number += charInt(str[i]);
    }
    return number;
}

string coverMT(long number,int n) {
    string str;
    while (number > 0) {
        str += to_string(number % n);
        number /= n;
    }
    reverse(str.begin(), str.end());
    return to_string(stol(str));
}

string getResult( int n, string b_sub, string sub) {
    if (n < 2 || n > 35) {
        return "- 1";
    }
    
    if (!isValid(b_sub, n) || !isValid(sub, n)) {
        return "-1";
    }
    long b_sub_val = coverM2T(b_sub, n);
    long sub_val = coverM2T(sub, n);
    string diff = coverMT(abs(b_sub_val - sub_val), n);
    string sign = b_sub_val >= sub_val ? "0":"1";
    
    
    
    return sign + " " + diff;
}



int main(int argc, const char * argv[]) {
    int n;
    string b_sub, sub;
    cin >> n >> b_sub >> sub;
   
   
//    getline(cin, b_sub);
//    getline(cin, b_sub);
    
    
   cout << getResult(n,b_sub,sub) << endl;
    return 0;
}
