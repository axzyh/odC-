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

// 整数对最小和
// 给定两个整数数组array1、array2，数组元素按升序排列

int getResult(vector<int> nums1, vector<int> nums2, int k) {
    vector<int> pairs;
    for (int v1 : nums1) {
        for (int v2 : nums2) {
            pairs.push_back(v1+v2);
        }
    }
    sort(pairs.begin(), pairs.end());
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += pairs[i];
    }
    
    return sum;
}

int main(int argc, const char * argv[]) {
    int n,m,k;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }
    cin >> m;
    vector<int> nums2(m);
    for (int i = 0; i < m; i++) {
        cin >> nums2[i];
    }
    cin >> k;
    
    cout << getResult(nums1, nums2, k) << endl;
    
    return 0;
}
