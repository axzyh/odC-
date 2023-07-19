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

// 符合要求的元组的个数
// 给定一个整数数组 nums、一个数字k，一个整数目标值 target，请问nums中是否存在k个元素使得其相加结果为target，请输出所有符合条件且不重复的k元组的个数

vector<int> getArrNumsForString(string s) {
    vector<int> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ' && tmp.length() > 0) {
            nums.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(stoi(tmp));
    }
    return nums;
}

int twoSum(vector<int> nums,int target,int start,int count, long preSum) {
    int l = start;
    int r = (int)nums.size() - 1;
    while (l < r) {
        long sum = preSum + nums[l] + nums[r];
        if (target < sum) {
            r--;
        } else if (target > sum) {
            l++;
        } else {
            count++;
            while (l + 1 < r &&nums[l] == nums[l+1]) {
                l++;
            }
            while (r - 1 > r && nums[r] == nums[r - 1]) {
                r--;
            }
            l++;
            r--;
        }
    }
    return count;
}
 // k树之和
int kSum(vector<int> nums,int k, int target, int start,int count, long sum) {
    if (k < 2) {
        return count;
    }
    if (k == 2) {
        return twoSum(nums, target, start, count, sum);
    }
    for (int i = start; i <= nums.size() - k; i++) {
        if (nums[i] > 0 && sum + nums[i] > target) {
            break;
        }
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }
        
        count = kSum(nums, k - 1, target, i + 1, count, sum + nums[i]);
    }
    
    return count;
    
}

int getResult(vector<int> nums, int k, int taraget) {
    if (k > nums.size()) {
        return 0;
    }
    sort(nums.begin(), nums.end());
    
   
    return kSum(nums, k, taraget, 0, 0, 0);
    
}

int main(int argc, const char * argv[]) {
    string str;
    int k,target;
    getline(cin, str);
    vector<int> nums = getArrNumsForString(str);
    cin >> k >> target;
    
    cout << getResult(nums, k, target) << endl;
    return 0;
}
