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

// 分割数组的最大差值
// 给定一个由若干整数组成的数组nums ，可以在数组内的任意位置进行分割，将该数组分割成两个非空子数组（即左数组和右数组），分别对子数组求和得到两个值，计算这两个值的差值，请输出所有分割方案中，差值最大的值。

long getResult(int n, vector<int> nums) {
    long leftSum = 0;
    long rightSum = 0;
    long maxDiff = 0;
    for (int i = 0; i < n; i++) {
        rightSum += nums[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        leftSum += nums[i];
        rightSum -= nums[i];
        long diff = abs(leftSum - rightSum);
        maxDiff = max(maxDiff, diff);
    }
   
    return maxDiff;
    
}

int main(int argc, const char * argv[]) {
   
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << getResult(n,nums) << endl;
    return 0;
}
