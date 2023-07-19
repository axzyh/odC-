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

// 字符串序列判定
// 输入两个字符串S和L，都只包含英文小写字母。S长度<=100，L长度<=500,000。


int getResult(string s, string l) {
    int i = 0, j = 0;
    while (i < s.length() && j < l.length()) {
        if (s[i] == l[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    if (i == s.length()) {
        return j - 1;
    }
    
    return -1;

}

int main(int argc, const char * argv[]) {

    string s,l;
    getline(cin, s);
    getline(cin, l);
    
    cout << getResult(s,l) << endl;
    
    return 0;
}
