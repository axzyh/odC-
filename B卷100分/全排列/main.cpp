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

// 全排列
// 给定一个只包含大写英文字母的字符串S，要求你给出对S重新排列的所有不相同的排列数。


int  getFact(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int getResult(string s1) {
    int n = (int)s1.length();
    int total = getFact(n);
    unordered_map<char, int> count;
    for (int i = 0; i < n; i++) {
        char k = s1[i];
        count[k]++;
    }
    for (auto k: count) {
        int m = k.second;
        if (m > 1) {
            total /= getFact(m);
        }
    }
    return total;
}

int main(int argc, const char * argv[]) {
    
    string s1;
    getline(cin, s1);

    cout << getResult(s1) << endl;
    
    return 0;
}
