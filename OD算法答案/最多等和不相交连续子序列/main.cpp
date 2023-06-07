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



// 最多等和不相交连续子序列
// 给定一个数组，我们称其中连续的元素为连续子序列，，称这些元素的和为连续子序列的和。

bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second < b.second) {
        return true;
    }
    return false;
}

int buxiangjiao(vector<pair<int, int>>v) {
    int count = 1;
    sort(v.begin(), v.end(), compare);
    int t = v[0].second;
    for (int i = 1; i < v.size(); i++) {
        pair<int, int>p = v[i];
        int l = p.first;
        int r = p.second;
        if (t < l) {
            count++;
            t = r;
        }
    }
    
    return count;
}
int getResult(vector<int>v, int n){
    map<int, vector<pair<int, int>>> map;
    vector<int>dp;
    dp.push_back(v[0]);
    for (int i = 1; i < n; i++) {
        dp.push_back(dp[i - 1] + v[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == 0) {
                int sum = dp[j];
                vector<pair<int, int>> dd = map[sum];
                dd.push_back(make_pair(i, j));
                map[sum] = dd;
            } else {
                int sum = dp[j] - dp[i-1];
                vector<pair<int, int>> dd= map[sum];
                dd.push_back(make_pair(i, j));
                map[sum] = dd;
            }
        }
    }
    
    int max1 = 0;
    for (auto &t :map) {
        vector<pair<int, int>> dd = t.second;
        max1 = max(max1, buxiangjiao(dd));
    }
    cout << endl;
    return max1;
}

int main(int argc, const char * argv[]) {
    
    int a,b;
    vector<int>vec;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> b;
        vec.push_back(b);
    }
    cout << getResult(vec, a) << endl;
    
    
    return 0;
}
