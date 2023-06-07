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



// 查找充电设备组合
//某个充电站，可提供n个充电设备，每个充电设备均有对应的输出功率。任意个充电设备组合的输出功率总和，均构成功率集合P的1个元素。功率集合P的最优元素，表示最接近充电站最大输出功率p_max的元素。
int getResult(vector<int>vec, int n, int p_max){
    vector<vector<int>> dp(n+1,vector<int>(p_max + 1));
    
    for (int i = 0; i <= n ; i++) {
        for (int j = 0; j <= p_max; j++) {
            if (i == 0 || j == 0) {
                continue;
            }
            if (vec[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], vec[i - 1] + dp[i-1][j-vec[i-1]]);
            }
        }
    }
    
    return dp[n][p_max];
} 

int main(int argc, const char * argv[]) {
    int n,p_max;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    cin >> p_max;
    cout << getResult(vec, n, p_max) << endl;
    
    return 0;
}
