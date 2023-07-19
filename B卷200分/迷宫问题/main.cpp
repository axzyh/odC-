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

// 迷宫问题
// 定义一个二维数组 N*M ，如 5 × 5 数组下所示：

void dfs(int x,int y, vector<string>&path,vector<string> &ans ,int n, int m, vector<vector<int>> &matrix,vector<vector<int>>offsets) {
    if (x == n - 1 && y == m - 1) {
        path.push_back("(" + to_string(x) + "," + to_string(y) + ")");
//        ans.p
        for (string str: path) {
            ans.push_back(str);
        }
        return;
    }
    for (vector<int>offset :offsets) {
        int newI = x + offset[0];
        int newJ = y + offset[1];
        if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && matrix[newI][newJ] == 0) {
            path.push_back("(" + to_string(x) + "," + to_string(y) + ")");
            matrix[x][y] = 2;
            dfs(newI, newJ, path, ans, n, m, matrix, offsets);
            path.pop_back();
        }
    }
}

void getResult(int m, int n, vector<vector<int>> matrix) {
    vector<string> path;
    vector<string> ans;
    vector<vector<int>> offsets = {{-1,0},{1,0},{0,-1},{0,1}};
    dfs(0, 0, path, ans, n, m, matrix, offsets);
    for (string str : ans) {
        cout << str << endl;
    }
}



int main(int argc, const char * argv[]) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>>matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    getResult(m,n,matrix);
    return 0;
}
