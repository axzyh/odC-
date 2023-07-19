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



// 字符串化繁为简
// 给定一个输入字符串，字符串只可能由英文字母（ 'a' ~ 'z'、'A' ~ 'Z' ）和左右小括号（ '('、')' ）组成。

bool canCombie(set<char>set1,set<char>set2) {
    
    for (char c = 'a'; c <= 'z'; c++) {
        char uc = c - 32;
        if ((set1.count(c) || set1.count(uc)) && ((set2.count(c) || set2.count(uc)))) {
            return true;
        }
    }
    return false;
}

void getResult() {
    string str;
    getline(cin, str);
    vector<char> vec;
    vector<set<char>> eqs;
    
    bool isOpen = false;
    
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '(') {
            isOpen = true;
            set<char> s;
            eqs.push_back(s);
        } else if (c == ')') {
            isOpen = false;
            set<char> s;
            s = eqs.back();
            if (s.size() == 0) {
                eqs.pop_back();
            }
        } else {
            if (!isOpen) {
                vec.push_back(c);
            }else {
                 eqs.back().insert(c);
            }
        }
    }
    
    // 暴力合并等效容器
    while (true) {
        for (int i = 0; i < eqs.size(); i++) {
            for (int j = i + 1; j < eqs.size(); j++) {
                if (canCombie(eqs[i], eqs[j])) {
                    eqs[i].insert(eqs[j].begin(),eqs[j].end());
                    eqs.erase(eqs.begin() + j);
                    continue;
                }
            }
        }
        break;
    }
    
    
    for (int i = 0; i < eqs.size(); i++) {
        set<char> s = eqs[i];
        char c = *s.begin();
        for (int j = 0; j < vec.size(); j++) {
            if (s.count(vec[j])) {
                vec[j] = c;
            }
        }
    }
    
    string str1(vec.begin(),vec.end());
    
    if (str1.length() == 0) {
        cout << "0" << endl;
    } else {
        cout << str1 << endl;
    }
}

int main(int argc, const char * argv[]) {
 
    getResult();
    
    return 0;
}
