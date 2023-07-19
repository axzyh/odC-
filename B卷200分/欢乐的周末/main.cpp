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



// 欢乐的周末
// 小华和小为是很要好的朋友，他们约定周末一起吃饭。

class UnionFindSet {
    int count;
    vector<int>fa;
    
public: UnionFindSet(int n) {
    fa = vector<int>(n);
    count = n;
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
}
    int find(int x) {
        if (x != fa[x] ) {
            return fa[x] = find(fa[x]);
        } else {
            return fa[x];
        }
    }
    
    void uniond(int x, int y) {
        int fa_x = find(x);
        int fa_y = find(y);
        if (fa_x != fa_y) {
           fa[fa_y] = fa_x;
        }
    }
    
};


int getResult(int n,int m, vector<vector<int>> matrix) {
    UnionFindSet ufs = UnionFindSet(n * m);
    vector<int> huawei;
    vector<int> restaurants;
    vector<vector<int>> offsets = {{-1,0},{1,0},{0,-1},{0,1}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = i * m + j;
            if (matrix[i][j] == 2) {
                huawei.push_back(x);
            } else if(matrix[i][j] == 3){
                restaurants.push_back(x);
            }
            for (vector<int> offset : offsets) {
                int newI = i + offset[0];
                int newJ = j + offset[1];
                if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && matrix[newI][newJ] != 1) {
                    ufs.uniond(x, newI * m + newJ);
                }
                
            }
        }
    }
    
    int hua_fa = ufs.find(huawei[0]);
    int wei_fa = ufs.find(huawei[1]);
    if (hua_fa != wei_fa) {
        return 0;
    }
    int ans = 0;
    for (int restaurant : restaurants) {
        if (ufs.find(restaurant) == hua_fa) {
            ans++;
        }
    }
    
  
    return ans;
}



int main(int argc, const char * argv[]) {

    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
    
    cout << getResult(n,m,matrix) << endl;
    return 0;
}
