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



// 数据最节约的备份方法
// 有若干个文件，使用刻录光盘的方式进行备份，假设每张光盘的容量是500MB，求使用光盘最少的文件分布方式

// 字符串分割成整型数组
vector<int> sprtStringToVecInt(string str,char c) {
    vector<int> vec ;
    string temp;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c && temp.length() > 0) {
            vec.push_back(stoi(temp));
            temp = "";
        } else {
            temp += str[i];
        }
    }
    if (temp.length() > 0) {
        vec.push_back(stoi(temp));
        temp = "";
    }
    return vec;
}

bool partition(vector<int>buckets,vector<int>nums,int index) {
    if (index == nums.size()) {
        return true;
    }
    int select = nums[index];
    for (int i = 0; i < buckets.size(); i++) {
        if (i > 0 && buckets[i] == buckets[i - 1]) {
            continue;
        }
        if (buckets[i] + select <=500) {
            buckets[i] += select;
            if (partition(buckets, nums, index + 1)) {
                return true;
            }
            buckets[i] -=select;
        }
    }
    
    return false;
}

bool check(int mid,vector<int>nums) {
    vector<int> buckets(mid);
    return partition(buckets, nums, 0);
}

int getResult(vector<int> nums ) {
   
    sort(nums.begin(), nums.end());
    int min = 1;
    int max = (int)nums.size();
    
    int res = max;
    while (min <= max) {
        int mid = (min + max) >> 1;
        if (check(mid, nums)) {
            max = mid - 1;
            res = mid;
        } else {
            min = mid + 1;
        }
    }
    
    return res;
    
    return 0;
}

int main(int argc, const char * argv[]) {

    string s;
    getline(cin, s);
    vector<int> nums = sprtStringToVecInt(s, ',');
   cout << getResult(nums) << endl;
    return 0;
}
