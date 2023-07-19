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


using namespace std;

// 最大矩阵和
// 给定一个二维整数矩阵，要在这个矩阵中选出一个子矩阵，使得这个子矩阵内所有的数字和尽量大，我们把这个子矩阵称为和最大子矩阵，子矩阵的选取原则是原矩阵中一块相互连续的矩形区域。


int maxSubArraySum(vector<int> nums) {
    vector<int> dp(nums.size());
    int res = dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i-1], 0) + nums[i];
        res = max(dp[i], res);
    }
    return res;
}

vector<int> matrixZip(vector<vector<int>> matrix) {
    int cols = (int)matrix[0].size();
    int rows = (int)matrix.size();
    vector<int> zip(cols);
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            zip[c] += matrix[r][c];
        }
    }
    return zip;
}

int getResult(int n, int m, vector<vector<int>> matrix) {
 
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        dp.push_back(maxSubArraySum(matrix[i]));
        for (int j = i + 1; j < n; j++) {
            vector<vector<int>> tmp(matrix.begin() + i,matrix.begin() +j + 1);
            dp.push_back(maxSubArraySum(matrixZip(tmp)));
        }
    }
    sort(dp.begin(), dp.end());
    
    return dp[dp.size() - 1];
}

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> martix(n,vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> martix[i][j];
        }
    }
    
    
    
  cout << getResult(n,m,martix) << endl;
    
    return 0;
}
