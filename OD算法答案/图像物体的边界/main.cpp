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

// 图像物体的边界
// 存在一个m×n的二维数组，其成员取值范围为0或1。

class UnoinFindSet {
public: int count;
        vector<int> fa;
public: UnoinFindSet(int n) {
        count = n;
        fa = vector<int>(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    
    int find(int x) {
        if (x != fa[x]) {
            fa[x] = find(fa[x]);
            return fa[x];
        }
        return x;
    }
    
    void uniond(int x, int y) {
        int fa_x = find(x);
        int fa_y = find(y);
        if (fa_x != fa_y) {
            fa[fa_x] = fa_y;
            count--;
        }
        
    }
    
    
};

int getResult(int m,int n, vector<vector<int>> matrix) {
    
    vector<vector<int>> brands;
    for (int i = 0; i < m; i++) {
        for (int j = 0 ; j < n; j++) {
            if (matrix[i][j] == 5) {
                brands.push_back({i,j});
            }
        }
    }
    
    int k = (int)brands.size();
    if (k == 0 || k == m * n) {
        return 0;
    }
    UnoinFindSet ufs = UnoinFindSet(k);
    
    for (int i = 0; i < k; i++) {
        int x1 = brands[i][0], y1 = brands[i][1];
        for (int j = i + 1; j < k; j++) {
            int x2 = brands[j][0], y2 = brands[j][1];
            
            if (abs(x2 - x1) <= 3 && abs(y2 - y1) <= 3) {
                ufs.uniond(i, j);
            }
        }
    }

      return ufs.count;
    
}

int main(int argc, const char * argv[]) {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m,vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    cout << getResult(m, n, matrix) << endl;
    return 0;
}
