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

// 可以组成网络的服务器
// 在一个机房中，服务器的位置标识在 n*m 的整数矩阵网格中，1 表示单元格上有服务器，0 表示没有。如果两台服务器位于同一行或者同一列中紧邻的位置，则认为它们之间可以组成一个局域网
bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second >= b.second) {
        return true;
    } else {
        return false;
    }
}

int dfs(int m, int n, vector<vector<int>> &matrix,int i, int j, int count) {
    if (i < 0 || i >= m || j < 0 || j >= n|| matrix[i][j] == 0) {
        return count;
    }
    count++;
    matrix[i][j] = 0;
    count = dfs(m, n, matrix, i + 1, j, count);
    count = dfs(m, n, matrix, i - 1, j, count);
    count = dfs(m, n, matrix, i, j - 1, count);
    count = dfs(m, n, matrix, i, j + 1, count);
    return count;
}


int getResult(int m,int n , vector<vector<int>> matrix) {
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dfs(m,n,matrix,i,j,0));
        }
    }

    return ans;
    
}

int main(int argc, const char * argv[]) {
   
    int m, n;
    cin >> m >> n;
    vector<vector<int>> relations(m,vector<int>(n));
    for (int i = 0; i < m ; i++) {
        for (int j = 0; j < n; j++) {
            cin >> relations[i][j];
        }
//        cin >> relations[i][0] >> relations[i][1];
    }
    
    cout << getResult(m, n, relations) << endl;
    return 0;
}
