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

// 矩阵扩散
// 存在一个m×n的二维数组，其成员取值范围为0或1。


vector<int> getArrForString(string s) {
    vector<int> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',' && tmp.length() > 0) {
            nums.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(stoi(tmp));
    }
    return nums;
}

int getResult(int m,int n, int i, int j, int k, int l) {
    
    vector<vector<int>> matrix(m, vector<int>(n));
    matrix[i][j] = 1;
    matrix[i][j] = 1;
    int count = m * n - 2;
    
    queue<vector<int>> queue;
    queue.push({i,j});
    queue.push({k,l});
    
    int offsets[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int day = 1;
    while (queue.size() > 0 && count > 0) {
        vector<int> tmp = queue.front();
        queue.pop();
        int x = tmp[0];
        int y = tmp[1];
        day = matrix[x][y] + 1;
        for (auto offset:offsets) {
            int newI = x + offset[0];
            int newJ = y + offset[1];
            if (newI >= 0 && newI < m && newJ >= 0 && newJ < n && matrix[newI][newJ] == 0) {
                matrix[newI][newJ] = day;
                queue.push({newI,newJ});
                count--;
            }
            
        }
    }
    
      return day - 1;
    
}

int main(int argc, const char * argv[]) {
    string str;
    
    getline(cin, str);
    
    vector<int> nums = getArrForString(str);
    
    cout << getResult(nums[0],nums[1],nums[2],nums[3],nums[4],nums[5]) << endl;
    return 0;
}
