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

// 寻找身高相近的小朋友
// 小明今年升学到了小学1年级来到新班级后，发现其他小朋友身高参差不齐，然后就想基于各小朋友和自己的身高差，对他们进行排序，请帮他实现排序。

int h,n;

bool compare(int a, int b) {
    int c1 = a - h;
    int c2 = b - h;
    if (abs(c1) < abs(c2)) {
        return true;
    } else if (abs(c1) == abs(c2)) {
        if (c1 < c2) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
    
}

string getResult(int n, vector<int> nums) {
    sort(nums.begin(), nums.end(), compare);
    string res;
    
    for (int num : nums) {
        if (res.length() > 0) {
            res += " ";
        }
        res += to_string(num);
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
   
    cin >> h >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
  cout << getResult(h,nums) << endl;
    
    return 0;
}
