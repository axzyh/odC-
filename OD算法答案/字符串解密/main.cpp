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

// 字符串解密
// 给定两个字符串string1和string2。
// string1由小写英文字母（’a’~’z’）和数字字符（’0’~’9’）组成，而加扰字符串由’0’~’9’、’a’~’f’组成。

int getStrCount(string str) {
    set<char>set;
    for (int i = 0; i < str.length(); i++) {
        set.insert(str[i]);
    }
    return (int)set.size();
}

bool isNumberAndChar(char c) {
    if ((c >= '0' && c <= '9') || (c >='a' && c <= 'f')) {
        return true;
    }
    return false;
}

bool compare(string a, string b) {
    
    return (a.size() >= b.size());
    
}

int main(int argc, const char * argv[]) {
    
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    string temp;
    vector<string>vecs;
    for (int i = 0; i < s1.length(); i++) {
        if (isNumberAndChar(s1[i])) {
            if (temp.length() > 0) {
                vecs.push_back(temp);
                temp ="";
            }
        } else {
            temp += s1[i];
        }
    }
    if (temp.length() > 0) {
        vecs.push_back(temp);
    }
    
    int count = getStrCount(s2);
    
    vector<string>svec;
    for (string i:vecs) {
        if (getStrCount(i)<= count) {
            svec.push_back(i);
        }
    }
    
    if (svec.size() == 0) {
        cout << "Not Found";
        return 0;
    }
    sort(svec.begin(), svec.end(), compare);
    cout << svec[0];
    
    return 0;
}
