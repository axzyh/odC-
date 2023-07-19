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

// 滑动窗口最大和
// 有一个N个整数的数组，和一个长度为M的窗口，窗口从数组内的第一个数开始滑动直到窗口不能滑动为止，

int getResult(int n, vector<int> nums, int m) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += nums[i];
    }
    
    int ans = sum;
    
    for (int i = 1; i <= n - m; i++) {
        sum += nums[i + m -1] - nums[i - 1];
        ans = max(ans, sum);
    }
    
    
    return ans;
}

int main(int argc, const char * argv[]) {
   
    int n,m;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    
    cout << getResult(n, arr, m) << endl;
    
    return 0;
}
