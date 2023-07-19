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

// 最小传输时延Ⅱ
// 有M*N的节点矩阵，每个节点可以向8个方向（上、下、左、右及四个斜线方向）转发数据包，每个节点转发时会消耗固定时延，连续两个相同时延可以减少一个时延值（即当有K个相同时延的节点连续转发时可以减少K- 1个时延值），


int n, m;
vector<vector<int>>matrix;
int offsets[8][2] = {{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};


void dfs(int i, int j, int delay,int last, set<int> &path,vector<int> &res) {
    int cur = matrix[i][j];
    bool flag = cur == last;
    if (i == n - 1 && j == m - 1) {
        delay += cur- (flag ? 1 : 0);
        res.push_back(delay);
        return;
    }
    
    for (auto offset:offsets) {
        int newI = i + offset[0];
        int newJ = j + offset[1];
        int pos = newI * m + newJ;
        if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && path.count(pos) != 1) {
            path.insert(pos);
            dfs(newI, newJ, delay + cur - (flag ? 1 : 0), cur, path, res);
            path.erase(pos);
        }
    }
    
}

int getResult() {
    
    vector<int> res;
    set<int> path;
    path.insert(0);
    dfs(0, 0, 0, INT_MAX, path, res);
    sort(res.begin(), res.end());
   
    return res[0];
    
}

int main(int argc, const char * argv[]) {
    
    cin >> n >> m;
   
    
    matrix = vector<vector<int>>(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << getResult() << endl;
    return 0;
}
