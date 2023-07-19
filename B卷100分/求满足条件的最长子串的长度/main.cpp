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

// 求满足条件的最长子串的长度
// 给定一个字符串，只包含字母和数字，按要求找出字符串中的最长（连续）子串的长度，字符串本身是其最长的子串，子串要求：


bool isChar(char c) {
    if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') ) {
        return true;
    }
    return false;
}

int getResult(string str) {
    
    int maxLen = -1;
    bool hasLetter = false;
    int l = 0, r = 0;
    vector<int> letterIdx;
    
    while (r < str.length()) {
        char c = str[r];
        if (isChar(c)) {
            hasLetter = true;
            letterIdx.push_back(r);
            if (letterIdx.size() > 1) {
                l = letterIdx[0] + 1;
                letterIdx.erase(letterIdx.begin() + 0);
            }
            if (r == l) {
                r++;
                continue;;
            }
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    if (!hasLetter) {
        return -1;
    }
    return maxLen;
}


int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    
    cout << getResult(str) << endl;
    
    return 0;
}
