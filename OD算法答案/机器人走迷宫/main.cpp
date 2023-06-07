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



// 机器人走迷宫
// 房间由XY的方格组成，例如下图为64的大小。每一个方格以坐标(x，y)描述。

bool dfs(int cx, int cy,int x,int y, vector<vector<int>> &matrix) {
    if (cx >= x || cy >= y) {
        return false;
    }
    if (matrix[cx][cy] == 1) {
        return false;
    }
    if (matrix[cx][cy] == -1) {
        return false;
    }
    if (matrix[cx][cy] == 2) {
        return true;
    }
    if (matrix[cx][cy] == 0) {
        bool east = dfs(cx + 1, cy, x, y, matrix);
        bool north = dfs(cx, cy + 1, x, y, matrix);
        if (east || north) {
            matrix[cx][cy] = 2;
        } else {
            matrix[cx][cy] = -1;
        }
    }
    return matrix[cx][cy] == 2;
    
}

string getResult(vector<vector<int>>matrix,int x, int y) {
    matrix[x - 1][y - 1] = 2;
    dfs(0, 0, x, y, matrix);
    int trap = 0;
    int unreach = 0;
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (matrix[i][j] == 0) {
                unreach++;
            } else if(matrix[i][j] == -1){
                trap++;
            }
        }
    }
    
    return to_string(trap) + " " + to_string(unreach);
}

int main(int argc, const char * argv[]) {
   
    int x,y ,n;
    cin >> x >> y >> n;
    vector<vector<int>> matrix(x,vector<int>(y));
    int left,right;
    for (int i = 0; i < n; i++) {
        cin >> left >> right;
        matrix[left][right] = 1;
    }
    
    cout << getResult(matrix,x,y) << endl;
    return 0;
}
