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



// 上班之路
// Jungle 生活在美丽的蓝鲸城，大马路都是方方正正，但是每天马路的封闭情况都不一样。

bool dfs(int si,int sj, int ut, int uc,int lastDirect,set<int>path,int n , int m,vector<vector<int>>offsets,vector<vector<char>>matrix,int c,int t) {
    if (matrix[si][sj] == 'T') {
        return true;
    }
    for (auto offset:offsets) {
        int direct = offset[2];
        int newI = si + offset[0];
        int newJ = sj + offset[1];
        bool flag1 = false; // 记录转弯
        bool flag2 = false; // 记录破壁
        if (newI >= 0 && newI < n && newJ >=0 && newJ < m) {
            int pos = newI * m + newJ;
            if (path.count(pos) == 1) {
                continue;
            }
            if (lastDirect != 0 && lastDirect != direct) {
                if (ut+1 >t) {
                    continue;
                } else {
                    flag1 = true;
                }
            }
            if (matrix[newI][newJ] == '*') {
                if (uc + 1 > c) {
                    continue;
                } else {
                    flag2 = true;
                }
            }
            path.insert(pos);
            bool res = dfs(newI, newJ, ut + (flag1 ? 1: 0), uc + (flag2 ? 1:0), direct, path, n, m, offsets, matrix, c, t);
            if (res) {
                return true;
            }
            path.erase(pos);
        }
    }
    return false;
}

string getResult(int t, int c,int n, int m, vector<vector<char>>matrix) {
    
    vector<vector<int>>offsets = {{1,0,1},{-1,0,2},{0,1,3},{0,-1,4}};
    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            if (matrix[i][j] == 'S') { // 起点
                set<int> path;
                path.insert(i*m+j);
                return dfs(i, j, 0, 0, 0, path, n, m, offsets, matrix, c, t) ? "YES" : "NO";
            }
        }
    }
    return "NO";
}

int main(int argc, const char * argv[]) {
    
    int t,c,n,m;
    cin >> t >> c >> n >> m;
    cin.ignore();
    string str;
    vector<vector<char>>matrix(n,vector<char>(m));
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        for (int j = 0; j < m ; j++) {
            matrix[i][j] = str[j];
        }
    }
    cout << getResult(t, c,n,m,matrix) << endl;
    
    
    return 0;
}
