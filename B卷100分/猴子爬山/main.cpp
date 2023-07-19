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

// 猴子爬山
// 一天一只顽猴想去从山脚爬到山顶，途中经过一个有个N个台阶的阶梯，但是这猴子有一个习惯：

int getResult(int n) {
   
    vector<int> dp(51);
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 3];
    }
    return dp[n];
}

int main(int argc, const char * argv[]) {
   
    int n;
    cin >> n;
    
    cout << getResult(n) << endl;
    
    return 0;
}
