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

// 快速人名查找
// 给一个字符串，表示用’,’分开的人名。

vector<string> getArrNumsForString(string s) {
    vector<string> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',' && tmp.length() > 0) {
            nums.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(tmp);
    }
    
    return nums;
}

vector<string> getArrStrForString(string s) {
    vector<string> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' && tmp.length() > 0) {
            nums.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(tmp);
    }
    
    return nums;
}

bool dfs(vector<string> &parts, int index,string abbr,int start) {
    if (start >= abbr.length()) {
        return index >= parts.size();
    }
    for (int i = index; i < parts.size(); i++) {
        string part = parts[i];
        for (int j = 0; j < part.length(); j++) {
            if (start < abbr.length() && part[j] == abbr[start]) {
                start++;
                bool res = dfs(parts, i + 1, abbr, start);
                if (res) {
                    return true;
                }
            } else {
                return false;
            }
        }
    }
    return false;
}

string getResult(vector<string>names, string abbr) {
    vector<string> ans;
    for (string name : names) {
        vector<string> parts = getArrStrForString(name);
        if (parts.size() > abbr.length()) {
            continue;
        }
        bool res = dfs(parts, 0, abbr, 0);
        if (res) {
            ans.push_back(name);
        }
    }
    
    string result;
    for (string str:ans) {
        if (result.length() > 0) {
            result += ",";
        }
        result += str;
    }
    

    return result;
    
}

int main(int argc, const char * argv[]) {
   
    string str;
    string abbr;
    getline(cin, str);
    getline(cin, abbr);
    vector<string>names = getArrNumsForString(str);
    
    cout << getResult(names, abbr) << endl;
    return 0;
}
