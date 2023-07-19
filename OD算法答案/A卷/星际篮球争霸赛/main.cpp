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

// 星际篮球争霸赛
// 在星球争霸篮球赛对抗赛中，最大的宇宙战队希望每个人都能拿到
/*
 9
 5 2 1 5 2 1 5 2 1
*/

bool partition(vector<int> &buckets, vector<int> &link_cp, int index, int subSum) {
    if (index == buckets.size()) {
        return true;
    }
    int select = (int)link_cp[index];
    for (int i = 0; i < buckets.size(); i++) {
        if (i > 0 && buckets[i] == buckets[i - 1]) {
            continue;
        }
        if (buckets[i] + select <= subSum) {
            buckets[i] += select;
            if (partition(buckets, link_cp, index + 1,subSum)) {
                return true;
            }
            buckets[i] -= select;
        }
    }
    return false;
}

bool canPartitionMSubSets(vector<int> &link_cp,int sum, int m) {
    if (sum % m != 0) {
        return false;
    }
    int subSum = sum / m;
    if (subSum < link_cp.back()) {
        return false;
    }
    while (subSum == link_cp.back()) {
        link_cp.pop_back();
        m--;
    }
    
    vector<int>buckets(m);
    
    return partition(buckets, link_cp, 0,subSum);
    
    
}

int getResult(int n, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }
    while (n > 1) {
        vector<int> arr_cp = arr;
        if (canPartitionMSubSets(arr_cp, sum, n)) {
            return sum / n;
        }
        n--;
    }
    return sum;
}



int main(int argc, const char * argv[]) {
  
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
  
   cout << getResult(n,arr) << endl;
//
    return 0;
}




