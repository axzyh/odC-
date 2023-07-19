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

// 数组连续和
// 给定一个含有N个正整数的数组, 求出有多少个连续区间（包括单个正整数）, 它们的和大于等于x。

long getResult(int n, int x, vector<int> arr) {
    vector<int> preSum(n + 1);
    for (int i = 1; i <= n; i++) {
        preSum[i] = preSum[i - 1] + arr[i - 1];
    }
    
    int l = 0;
    int r = l;
    long ans = 0;
    
    while (r <= n) {
        if (preSum[r] - preSum[l] >= x) {
            ans += n - r + 1;
            l++;
            r = l + 1;
        } else {
            r++;
        }
    }
    
    return ans;
    
}

int main(int argc, const char * argv[]) {
    
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << getResult(n, x, arr) << endl;
    
    return 0;
}
