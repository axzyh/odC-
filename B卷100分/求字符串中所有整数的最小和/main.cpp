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

// 求字符串中所有整数的最小和
// 输入字符串s，输出s中包含所有整数的最小和。


string getResult(string str) {
    bool isNegative = false;
    string negative;
    
    long ans = 0;
    
    
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c >= '0' && c <= '9') {
            if (isNegative) {
                negative += c;
            } else {
                ans += (c - '0');
            }
        } else {
            if (isNegative) {
                ans -= stol(negative);
                negative = "";
            }
            isNegative = c == '-';
        }
    }
    if (negative.length() > 0) {
        ans -= stol(negative);
    }
   
    return to_string(ans);
}


int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    
    cout << getResult(str) << endl;
    
    return 0;
}
