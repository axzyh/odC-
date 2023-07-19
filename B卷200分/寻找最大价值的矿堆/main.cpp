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
#include <unordered_set>
#include <regex>

using namespace std;



// 寻找最大价值的矿堆
// 给你一个由 '0' (空地)、'1' (银矿)、'2'(金矿) 组成的的地图，矿堆只能由上下左右相邻的金矿或银矿连接形成。超出地图范围可以认为是空地。


vector<vector<int>> matrix;
int row;
int col;
vector<vector<int>> offsets = {{-1,0},{1,0},{0,-1},{0,1}};


int dfs(int i, int j ) {
    int sum = matrix[i][j];
    matrix[i][j] = 0;
    stack<vector<int>> stack;
    stack.push({i,j});
    while (stack.size() > 0) {
        vector<int> pos = stack.top();
        stack.pop();
        int x = pos[0], y = pos[1];
        for (vector<int> offset: offsets) {
            int newX = x + offset[0];
            int newY = y + offset[1];
            if (newX >= 0 && newX < row && newY >= 0 && newY < col && matrix[newX][newY] > 0) {
                sum += matrix[newX][newY];
                matrix[newX][newY] = 0;
                stack.push({newX,newY});
            }
        }
    }
    return sum;
}

int getResult(vector<vector<int>> matrix) {
    row = (int)matrix.size();
    if (row == 0) {
        return 0;
    }
    col = (int)matrix[0].size();
    int ans = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (matrix[i][j] > 0) {
                ans = max(ans, dfs(i,j));
            }
        }
    }
  
    return ans;
}



int main(int argc, const char * argv[]) {
    
    matrix = vector<vector<int>>();
    string str;
    
    while (true) {
        getline(cin, str);
        if (str == "") {
            cout << getResult(matrix) << endl;
            break;
        } else {
            vector<int> tmp;
            for (char c : str) {
                tmp.push_back(c - '0');
            }
            matrix.push_back(tmp);
        }
    }
    
    return 0;
}
