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

// 流水线
// 一个工厂有m条流水线，来并行完成n个独立的作业，该工厂设置了一个调度系统，在安排作业时，总是优先执行处理时间最短的作业。

int getResult(int m ,int n, vector<int> nums) {
    
   
    sort(nums.begin(), nums.end());
   
    vector<int> mArr(m);
    for (int i = 0; i < n; i++) {
        mArr[i % m] += nums[i];
    }
   
    sort(mArr.begin(), mArr.end());
    
    return mArr[m - 1];
}

int main(int argc, const char * argv[]) {

    int m, n;
    cin >> m >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
   
   
    cout << getResult(m, n, nums) << endl;
    
    return 0;
}
