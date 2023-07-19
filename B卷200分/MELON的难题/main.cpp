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

// MELON的难题
// MELON有一堆精美的雨花石（数量为n，重量各异），准备送给S和W。MELON希望送给俩人的雨花石重量一致，请你设计一个程序，帮MELON确认是否能将雨花石平均分配。
//

int getResult(int n, vector<int> nums) {
    
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    
    if (sum % 2 != 0) {
        return -1;
    }
    int bag = sum / 2;
    
    vector<vector<int>> dp(n + 1,vector<int>(bag + 1));
    
    for (int i = 0; i <= bag; i++) {
        dp[0][i] = n;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int num = nums[i - 1];
        for (int j = 1; j <= bag; j++) {
            if (j < num) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] =min(dp[i - 1][j], dp[i - 1][j - num] +1);
            }
        }
    }
    
    if (dp[n][bag] == n) {
        return -1;
    } else {
        return dp[n][bag];
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
   cout << getResult(n, nums) << endl;
    
    
    return 0;
}
