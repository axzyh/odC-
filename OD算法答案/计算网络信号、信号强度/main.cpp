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

// 计算网络信号、信号强度
// 网络信号经过传递会逐层衰减，且遇到阻隔物无法直接穿透，在此情况下需要计算某个位置的网络信号值。
int getResult(vector<vector<int>>vec,int x, int y) {
    vector<vector<int>> offsets = {{1,0},{-1,0},{0,1},{0,-1}};
    queue<pair<int, int>> q;
    
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (vec[i][j] > 0) {
                q.push(make_pair(i, j));
                break;
            }
        }
    }
    
    while (q.size() > 0) {
        pair<int, int> p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        int ma = vec[i][j]-1;
        if (ma == 0) {
            break;
        }
        for (auto offset:offsets) {
            int newI = i + offset[0];
            int newJ = j + offset[1];
            if (newI >= 0 && newI < vec.size() && newJ >= 0 && newJ < vec[newI].size() && vec[newI][newJ] == 0) {
                vec[newI][newJ] = ma;
                q.push(make_pair(newI, newJ));
            }
        }
        
    }
    return vec[x][y];
}

void test22() {
  
    
}

int main(int argc, const char * argv[]) {
    int rows, cols,x,y;
    cin >> rows >> cols;
    vector<vector<int>>vec(rows,vector<int>(cols));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> vec[i][j];
        }
    }
    cin >> x >> y;
    cout << getResult(vec, x, y) << endl;
    
    return 0;
}
