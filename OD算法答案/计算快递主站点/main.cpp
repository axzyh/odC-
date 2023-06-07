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



// 计算快递主站点
// 快递业务范围有N个站点，A站点与B站点可以中转快递，则认为A-B站可达，如果A-B可达，B-C可达，则A-C可达。
// 现在给N个站点编号0、1、…n-1，用s[i][j]表示i-j是否可达，s[i][j]=1表示i-j可达，s[i][j]=0表示i-j不可达。

vector<int> fa;
int countdd;

void unionFindSet(int n) {
//    vector<int> fa;
    for (int i = 0; i < n; i++) {
        fa.push_back(i);
    }
}

int find(int x) {
    if (x != fa[x]) {
        return fa[x] = find(fa[x]);
    }
    return x;
}

void unionF(int i, int j) {
    int i_fa = find(i);
    int j_fa = find(j);
    if (i_fa != j_fa) {
        fa[j_fa] = i_fa;
        countdd--;
    }
}


int getResult(vector<vector<int>> matrix,int n) {
    unionFindSet(n);
    countdd = n;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n ; j++) {
            if (matrix[i][j] == 1) {
                unionF(i, j);
            }
        }
    }
  
    return countdd;
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
    cout << getResult(matrix,n) << endl;
    
    return 0;
}
