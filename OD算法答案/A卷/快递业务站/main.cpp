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
#include <iomanip>


using namespace std;

// 快递业务站
// 快递业务范围有 N 个站点，A 站点与 B 站点可以中转快递，则认为 A-B 站可达，
/*
 4
 1 1 1 1
 1 1 1 0
 1 1 1 0
 1 0 0 1
*/

// 并查集

class UnionFindSet {
public: int count;
    vector<int> fa;
    
public: UnionFindSet(int n) {
    count = n;
    fa = vector<int>(n);
    for (int i = 0; i < n; i++) {
        fa[i] = i;
    }
}
    int find(int x) {
        if (x != fa[x]) {
            return fa[x] = find(fa[x]);
        }
        return x;
    }
    
    void unionn(int x, int y) {
        int fa_x = find(x);
        int fa_y = find(y);
        if (fa_x != fa_y) {
            fa[fa_x] = fa_y;
            count--;
        }
    }

    
};

int getResult(vector<vector<int>> matrix, int n) {
    UnionFindSet ufs = UnionFindSet(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                ufs.unionn(i, j);
            }
        }
    }
    
    return ufs.count;

}



int main(int argc, const char * argv[]) {
  
    int n;
    cin >> n;
    vector<vector<int>> matrix(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
  
    cout << getResult(matrix,n) << endl;
//
    return 0;
}




