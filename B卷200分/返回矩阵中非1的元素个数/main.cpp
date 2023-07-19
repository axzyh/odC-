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
//#include <algorithm>
#include <queue>
#include <unordered_set>
//#include <iterator>

using namespace std;

// 返回矩阵中非1的元素个数
// 存在一个m*n的二维数组，其成员取值范围为0，1，2。
//

int getResult(int m, int n, vector<vector<int>> matrix) {

    vector<vector<int>> offsets = {{-1,0},{1,0},{0,-1},{0,1}};
    queue<vector<int>> q;
    q.push({0,0});
    int count = 1;
    while (q.size() > 0) {
        vector<int> pos = q.front();
        q.pop();
        int x = pos[0];
        int y = pos[1];
        for (vector<int> offset : offsets) {
            int newX = x + offset[0];
            int newY = y + offset[1];
            if (newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[newX][newY] == 0) {
                matrix[newX][newY] = 1;
                count++;
                q.push({newX,newY});
            }
        }
    }
    return m * n - count;
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
    matrix[0][0] = 1;
   cout << getResult(m, n, matrix) << endl;
    
    
    return 0;
}
