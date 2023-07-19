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

// 最长连续子序列
// 有N个正整数组成的一个序列。给定整数sum，求长度最长的连续子序列，使他们的和等于sum，返回此子序列的长度，如果没有满足要求的序列，返回-1。

vector<int> getArrNumsForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ','&& tmp.length() > 0) {
            vec.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(stoi(tmp));
    }
    return vec;
}

int getResult(vector<int> nums, int sum) {
    int ans = -1;
    if (sum <= 0) {
        return ans;
    }
    int l = 0;
    int r = 0;
    int n = (int)nums.size();
    int total = nums[l];
    while (true) {
        if (total > sum) {
            total -= nums[l];
            l++;
            if (l < n && r < n) {
                r = l;
                total += nums[r];
            }
        } else if (total < sum) {
            r++;
            if (r < n) {
                total += nums[r];
            } else {
                break;
            }
        } else {
            ans = max(ans, r - l + 1);
            l++;
            r++;
            if (r < n) {
                total += nums[r] - nums[l - 1];
            } else {
                break;
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    
    vector<int> nums = getArrNumsForString(str);
    int sum;
    cin >> sum;
    
 
    cout << getResult(nums,sum) << endl;
    
    return 0;
}
