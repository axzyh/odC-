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



// 食堂供餐
// 某公司员工食堂以盒饭方式供餐。为将员工取餐排队时间降低为0，食堂的供餐速度必须要足够快。

bool check(int m, int add,vector<int>nums) {
    m -= nums[0];
    for (int i = 1; i <nums.size(); i++) {
        m += add;
        if (m > nums[i]) {
            m -= nums[i];
        } else {
            return false;
        }
    }
    return true;
}

int getResult(vector<int> nums,int n,int m) {
    int min1 = 0;
    int max1 = *max_element(nums.begin(), nums.end());
    
    int ans = 0;
    while (min1 <= max1) {
        int mid = (min1 + max1) >> 1;
        if (check(m, mid, nums)) {
            ans = mid;
            max1 = mid - 1;
        } else {
            min1 = mid + 1;
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int n,m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << getResult(nums, n, m);
    return 0;
}
