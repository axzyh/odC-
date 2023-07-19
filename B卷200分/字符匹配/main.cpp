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



// 字符匹配
// 给你一个字符串数组（每个字符串均由小写字母组成）和一个字符规律（由小写字母和.和*组成），识别数组中哪些字符串可以匹配到字符规律上。

vector<string> getArrForString(string s) {
    vector<string> sVec;
    
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            sVec.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        sVec.push_back(tmp);
    }
    
    return sVec;
}

bool eq(char p, char s) {
    return p == s || p == '.';
}

bool isMatch(string s, string p) {
    s = " " + s;
    p = " " + p;
    int n = (int)s.length();
    int m = (int)p.length();
    vector<vector<bool>>dp(n,vector<bool>(m));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (p[j] == '*') {
                dp[i][j] = (j >=2 && dp[i][j-2]) || (eq(p[j-1], s[i]) && dp[i- 1][j]);
            } else {
                dp[i][j] = eq(p[j], s[i] )&& i >=1 && dp[i - 1][j - 1];
            }
        }
    }
    return dp[n-1][m -1];
}


string getResult(vector<string>arr,string reg) {
    string ans;
    for (int i = 0; i < arr.size(); i++) {
        if (isMatch(arr[i], reg)) {
            if (ans.length() > 0) {
                ans += ",";
            }
            ans += to_string(i);
        }
    }
    
    if (ans.length() == 0) {
        return "-1";
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
  
    string s,reg;
    getline(cin, s);
    vector<string> arr = getArrForString(s);
    getline(cin, reg);
   cout << getResult(arr,reg) << endl;
    return 0;
}
