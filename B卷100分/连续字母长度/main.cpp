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

// 连续字母长度
// 给定一个字符串，只包含大写字母，求在包含同一字母的子串中，长度第 k 长的子串的长度，相同字母只取最长的那个子串。

bool compare(pair<char, int> a, pair<char, int> b) {
    if (a.second >= b.second) {
        return true;
    } else {
        return false;
    }
}

int getResult(string str, int k) {
    
    unordered_map<char, int> count;
    char b = str[0];
    int len = 1;
    for (int i = 1; i < str.length(); i++) {
        char c = str[i];
        if (b == c) {
            len++;
        } else {
            if (!count.count(b) || count[b] < len) {
                count[b] = len;
            }
            len = 1;
            b = c;
        }
    }
    
    vector<pair<char, int>> vec(count.begin(),count.end());
    if (k > vec.size()) {
        return -1;
    } else {
        sort(vec.begin(), vec.end(), compare);
    }

    return vec[k - 1].second;

}

int main(int argc, const char * argv[]) {

    string str;
    getline(cin, str);
    int k;
    cin >> k;
    cout << getResult(str, k) << endl;
    
    return 0;
}
