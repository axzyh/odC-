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

// 求最多可以派出多少支团队
// 用数组代表每个人的能力，一个比赛活动要求参赛团队的最低能力值为N，每个团队可以由1人或者2人组成，且1个人只能参加1个团队，计算出最多可以派出多少只符合要求的团队。

int getResult(int n ,int target, vector<int> nums) {
   
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = n - 1;
    int ans = 0;
    
    while (l <= r && nums[r] >= target) {
        r--;
        ans++;
    }
    
    while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum >= target) {
            ans++;
            l++;
            r--;
        } else {
            l++;
        }
    }
    
    
    return ans;
}

int main(int argc, const char * argv[]) {

    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> target;
   
    cout << getResult(n, target, nums) << endl;
    
    return 0;
}
