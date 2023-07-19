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

// 跳格子1
// 小明和朋友玩跳格子游戏，有 n 个连续格子，每个格子有不同的分数，小朋友可以选择以任意格子起跳，但是不能跳连续的格子，也不能回头跳；
//



vector<int> getArrNumsForString(string s) {
    vector<int> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' && tmp.length() > 0) {
            nums.push_back(stoi(tmp));
            tmp = "";
        }
        else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(stoi(tmp));
    }
    return nums;
}


int getResult(vector<int> nums) {
    int n = (int)nums.size();
    vector<int> dp(n);
    if (n >= 1) {
        dp[0] = nums[0];
    }
    if (n >= 2) {
        dp[1] = max(dp[0], nums[1]);
    }
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[n - 1];
    
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    vector<int> nums = getArrNumsForString(str);
    cout << getResult(nums) << endl;
    return 0;
}
