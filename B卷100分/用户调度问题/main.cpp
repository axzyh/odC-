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

// 用户调度问题
// 在通信系统中，一个常见的问题是对用户进行不同策略的调度，会得到不同的系统消耗和性能。

void dfs(vector<vector<int>> res, int m, int level, int index, int total, int &ans) {
    if (level == m) {
        ans = min(ans, total);
        return;
    }
    vector<int> r = res[level];
    for (int i = 0; i < r.size(); i++) {
        if (i != index) {
            dfs(res, m, level + 1, i, total + r[i], ans);
        }
    }
}

int getResult(int m, vector<vector<int>> res) {
    int ans = INT_MAX;
    dfs(res, m, 0, 0, 0, ans);
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int m;
    cin >> m;
    vector<vector<int>> res(m,vector<int>(3));
    
    for (int i = 0; i < m; i++) {
        cin >> res[i][0] >> res[i][1] >> res[i][2];
    }
    
    
    cout << getResult(m, res) << endl;
    
    return 0;
}
