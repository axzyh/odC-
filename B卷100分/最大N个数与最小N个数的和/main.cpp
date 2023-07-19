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

// 最大N个数与最小N个数的和
// 给定一个数组，编写一个函数来计算它的最大N个数与最小N个数的和。你需要对数组进行去重。

int getResult(int m, vector<int> nums, int n) {
    
    set<int> set;
    for (int i = 0; i < m; i++) {
        if (set.count(nums[i]) != 1) {
            set.insert(nums[i]);
        }
    }
    
    if (set.size() < 2  * n) {
        return -1;
    }
    vector<int> vec(set.begin(),set.end());
    int l = 0;
    int r = (int)vec.size() - 1;
    int ans = 0;
    while (n > 0) {
        ans += vec[l] + vec[r];
        l++;
        r--;
        n--;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    
    int m,n;
    cin >> m;
    vector<int> nums(m);
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }
    cin >> n;
 
    cout << getResult(m,nums,n) << endl;
    
    return 0;
}
