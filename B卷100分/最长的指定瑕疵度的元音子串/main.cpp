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

// 最长的指定瑕疵度的元音子串
// 开头和结尾都是元音字母（aeiouAEIOU）的字符串为元音字符串，其中混杂的非元音字母数量为其瑕疵度。比如:


int getResult(string s, int n) {
    
    vector<char> vec = {'a','e','i','o','u','A','E','I','O','U'};
    set<char> set;
    for (char c : vec) {
        set.insert(c);
    }
    vector<int> idxs;
    for (int i = 0; i < s.length(); i++) {
        if (set.count(s[i]) == 1) {
            idxs.push_back(i);
        }
    }
    int ans = 0;
    int m = (int)idxs.size();
    int l = 0;
    int r = 0;
    int diff;
    while (r < m) {
        if (r - l == idxs[r] - idxs[l]) {
            diff = 0;
        } else {
            diff = idxs[r] - idxs[l] - (r - l);
        }
        if (diff > n) {
            l++;
        } else if (diff < n) {
            r++;
        } else {
            ans = max(ans, idxs[r] - idxs[l] + 1);
            r++;
        }
    }
    return ans;

}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    cin.ignore();
    
    string s;
    getline(cin, s);
    
    cout << getResult(s,n) << endl;
    
    return 0;
}
