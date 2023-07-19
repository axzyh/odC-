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

// 机器人
// 现有一个机器人，可放置于 M × N 的网格中任意位置，每个网格包含一个非负整数编号，当相邻网格的数字编号差值的绝对值小于等于 1 时，机器人可以在网格间移动。
/*
 4 4
 1 2 5 2
 2 4 4 5
 3 5 7 1
 4 6 2 4
*/

class UnionFindSet {
public:int count;
    vector<int> fa;
    
public: UnionFindSet(int n){
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
        int x_fa = find(x);
        int y_fa = find(y);
        if (x_fa != y_fa) {
            count--;
            fa[y_fa] = x_fa;
        }
    }
};

bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.second > b.second) {
        return true;
    }
    return false;
}

int getResult(vector<vector<int>>matrix, int m, int n) {
    UnionFindSet ufs = UnionFindSet(m * n);
    vector<vector<int>> offsets = {{-1,0},{1,0},{0,-1},{0,1}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (vector<int> offset:offsets) {
                int newI = i + offset[0];
                int newJ = j + offset[1];
                if (newI < 0 || newI >= m || newJ < 0 || newJ > n) {
                    continue;
                }
                if (abs(matrix[i][j] - matrix[newI][newJ]) <= 1) {
                    ufs.unionn(i * m + j, newI * m + newJ);
                }
            }
        }
    }
    int total = m * n;
    if (ufs.count == 1) {
        return total;
    }
    
    for (int i = 0; i < total; i++) {
        ufs.find(i);
    }
    
    unordered_map<int, int> count;
    for (int i : ufs.fa) {
        count[i]++;
    }
    
    vector<pair<int, int>> vec(count.begin(), count.end());
    sort(vec.begin(), vec.end(),compare);

    return vec.front().second;
}



int main(int argc, const char * argv[]) {
  
    int n,m;
    cin >> m >> n;
    
    vector<vector<int>> matrix(m,vector<int>(n));
    
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
  
   cout << getResult(matrix,m,n) << endl;
//
    return 0;
}




