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


using namespace std;

// 英文输入法
// 主管期望你来实现英文输入法单词联想功能

bool isCharStr(char c) {
    
    return (c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z');
}

vector<string> getArrStrForString(string str) {
    vector<string> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if ((str[i] == ' ' || !isCharStr(str[i])) && tmp.length() > 0) {
            arr.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(tmp);
    }
    return arr;
}


string getResult(string str,string pre) {
    vector<string> arr = getArrStrForString(str);
    
    set<string> cache;
    
    for (auto i : arr) {
        if (cache.count(i) != 1) {
            cache.insert(i);
        }
    }
    
    string ans;
    
    for (auto i : cache) {
        if (i.find(pre) != string::npos) {
            if (ans.length() > 0) {
                ans += " ";
            }
            ans += i;
        }
    }
    
    if (ans.length() > 0) {
        return ans;
    } else {
        return pre;
    }
}

int main(int argc, const char * argv[]) {

    string str, pre;
    getline(cin, str);
    getline(cin, pre);
    cout << getResult(str, pre) << endl;
    
    return 0;
}
