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

// 最小循环子数组
// 给定一个由若干整数组成的数组nums，请检查数组是否是由某个子数组重复循环拼接而成，请输出这个最小的子数组。
//



vector<string> getArrNumsForString(string s) {
    vector<string> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',' && tmp.length() > 0) {
            nums.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(tmp);
    }
    return nums;
}


vector<int> getNext(int n, vector<int> nums) {
    vector<int> next(n);
    int j = 1;
    int k = 0;
    while (j < n) {
        if (nums[j] == nums[k]) {
            next[j] = k + 1;
            j++;
            k++;
        } else {
            if (k > 0) {
                k = next[k - 1];
            } else {
                j++;
            }
        }
    }
    return next;
}

string getResult(int n, vector<int> nums) {
    vector<int> next = getNext(n, nums);
    int m = next[n - 1];
    int len = n % (n - m) == 0? n - m : n;
    string res;
    for (int i = 0; i < len; i++) {
        if (res.length() > 0) {
            res += " ";
        }
        res += to_string(nums[i]);
    }
    
    
    return res;
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
