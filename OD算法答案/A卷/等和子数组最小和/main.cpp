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
#include <iomanip>


using namespace std;

// 等和子数组最小和
// 给定一个数组nums，将元素分为若干个组，使得每组和相等，求出满足条件的所有分组中，组内元素和的最小值。

bool compare(int a, int b) {
    if (a > b) {
        return true;
    }
    return false;
}

bool partition(vector<int>link, int index, vector<int> &buckets, int subSum) {
    if (index == link.size()) {
        return true;
    }
    int select = link[index];
    for (int i = 0; i < buckets.size(); i++) {
        if (i > 0 && buckets[i] == buckets[i - 1]) {
            continue;
        }
        if (select + buckets[i] <= subSum) {
            buckets[i] += select;
            if (partition(link, index + 1, buckets,subSum)) {
                return true;
            }
            buckets[i] -=select;
        }
    }
    return false;
}

bool canPartitionMSubsets(vector<int> &arr, int sum, int m) {
    if (sum % m != 0) {
        return false;
    }
    int subSum = sum / m;
    if (subSum < arr[0]) {
        return false;
    }
    while (arr.size() > 0 && arr[0] == subSum) {
        arr.erase(arr.begin() + 0);
        m--;
    }
    vector<int> buckets(m);
    return partition(arr, 0, buckets, subSum);
}

int getResult(int n, vector<int> arr) {
    sort(arr.begin(), arr.end(), compare);
    int sum = 0;
    for (int ele : arr) {
        sum += ele;
    }
    
    while (n > 0) {
        vector<int> arr_cp = arr;
        if (canPartitionMSubsets(arr_cp, sum, n)) {
            return sum / n;
        }
        n--;
    }
    
    
    return sum;
}



int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    
    cout << getResult(n,arr) << endl;
//
    return 0;
}




