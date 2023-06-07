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



// 字符串比较
// 给定字符串A、B和正整数V，A的长度与B的长度相等， 请计算A中满足如下条件的最大连续子串的长度：
vector<string> getArrForString(string s) {
    vector<string> sVec;
    
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            sVec.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        sVec.push_back(tmp);
    }
    
    return sVec;
}

class UnoinFindSet {
public:  int count;
    vector<int>fa;
public:   UnoinFindSet(int n) {
        fa = vector<int>(n);
        count = n;
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    
  int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
            return fa[x];
        } else {
            return x;
        }
    }
    
    void uniond(int x, int y) {
        int fa_x = find(x);
        int fa_y = find(y);
        if (fa_x != fa_y ) {
            fa[fa_y] = fa_x;
            count--;
        }
    }
    
};

int getResult(string s1, string s2, int v) {
    int n = (int)s1.length();
    vector<int> preSum(n + 1);
    for (int i = 1; i <= s1.length(); i++) {
        preSum[i] = preSum[i - 1] + abs(s1[i-1]- s2[i-1]);
    }
    
    int ans = 0;
    for (int i = 0; i < n ; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (preSum[j] - preSum[i] <= v) {
                ans = max(ans, j - i);
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    int v;
    cin >> v;
    
    cout << getResult(s1,s2,v) << endl;
    
    return 0;
}
