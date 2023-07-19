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
#include <stack>
#include <queue>
#include <unordered_set>
#include <regex>

using namespace std;

// 最长的完全交替连续方波信号
// 输入一串方波信号，求取最长的完全连续交替方波信号，并将其输出，
//


string getResult(string s) {
    
    regex reg("^(01)+0$");
    int maxLen = 0;
    string ans = "-1";
    
    smatch regMatch;
    
    string res;
    for (int i = 0; i <s.length(); i++) {
        char c = s[i];
        if (c == '0') {
            if (res.length() > 0 && res[res.length() - 1] == '0') {
                if (regex_match(res, regMatch, reg) && res.length() > maxLen) {
                    maxLen = (int)res.length();
                    ans = res;
                }
                res = "";
            }
        }
        res += c;
    }
    if (res.length() > 0) {
        if (regex_match(res, regMatch, reg) && res.length() > maxLen) {
            return res;
        }
    }
    
    return ans;
   
   
}

int main(int argc, const char * argv[]) {
    string str;
    
    getline(cin, str);
    
   cout << getResult(str) << endl;
    
    
    return 0;
}
