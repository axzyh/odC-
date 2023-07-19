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

//  路灯照明问题
// 在一条笔直的公路上安装了N个路灯，从位置0开始安装，路灯之间间距固定为100米。

bool compare(pair<int, int>a, pair<int, int> b) {
    if (a.first < b.first) {
        return true;
    } else if (a.first == b.first) {
        return a.second - b.second;
    } else {
        return false;
    }
}

int getResult(int n, vector<pair<int, int>> ranges) {
    int ans = 0;
    sort(ranges.begin(), ranges.end(), compare);
    int t = ranges[0].second;
    for (int i = 1; i < n; i++) {
        int s = ranges[i].first;
        int e = ranges[i].second;
        if (t >= s) {
            t = max(t, e);
        } else {
            ans += s - t;
            t = e;
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int n,r;
    cin >> n;
    vector<pair<int, int>> ranges (n);
    for (int i = 0; i < n; i++) {
        cin >> r;
        int center = i * 100;
        ranges[i] = make_pair(center - r, center + r);
       
    }
    
    cout << getResult(n,ranges) << endl;
    
    return 0;
}
