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


using namespace std;

// 关联子串
// 给定两个字符串str1和str2，如果字符串str1中的字符，经过排列组合后的字符串中，只要有一个字符串是str2的子串，则认为str1是str2的关联子串。


int getResult(string s1, string s2) {
    vector<char> count(128);
    for (int i = 0; i < s1.length(); i++) {
        char c = s1[i];
        count[c]++;
    }
    
    int total = (int)s1.length();
    
    for (int i = 0; i < s1.length(); i++) {
        char add = s2[i];
        if (count[add]-- > 0) {
            total--;
        }
    }
    
    if (total == 0) {
        return 0;
    }
    
    for (int i = 1; i < s2.length() - s1.length() + 1; i++) {
        char remove = s2[i - 1];
        char add = s2[i + s1.length() - 1];
        if (count[remove]++ > 0) {
            total++;
        }
        if (count[add]-- > 0) {
            total--;
        }
        if (total == 0) {
            return i;
        }
    }
    return -1;
    
}

int main(int argc, const char * argv[]) {
    
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);

    cout << getResult(s1,s2) << endl;
    
    return 0;
}
