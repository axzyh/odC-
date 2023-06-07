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

// 基站维护工程师
// 小王是一名基站维护工程师，负责某区域的基站维护。
//   某地方有  n  个基站(1 < n < 10)，已知各基站之间的距离 s(0 < s < 500)，并且基站 x 到基站 y 的距离，与基站 y 到基站 x 的距离并不一定会相同。

void dfs(int n, vector<bool> used, vector<int>path,vector<int> &ans,vector<vector<int>> matrix) {
    if (path.size() == n - 1) {
        int dis = matrix[0][path[0]];
        for (int i = 0 ; i < path.size() - 1; i++) {
            int p = path[i];
            int c = path[i+1];
            dis += matrix[p][c];
        }
        dis +=matrix[path.back()][0];
        ans[0] = min(ans[0], dis);
        return;
    }
    for (int i = 1; i < n; i++) {
        if (!used[i]) {
            path.push_back(i);
            used[i] = true;
            dfs(n, used, path, ans, matrix);
            used[i] = false;
            path.pop_back();
        }
    }
}

int getResult(vector<vector<int>>matrix,int n) {
    vector<bool>used(n);
    vector<int> path;
    vector<int> res = {INT_MAX};
    dfs(n, used, path, res, matrix);
    return res[0];
    
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
    vector<vector<int>>matrix(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << getResult(matrix, n) << endl;
    
    return 0;
}
