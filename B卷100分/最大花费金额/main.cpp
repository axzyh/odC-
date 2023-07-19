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

// 最大花费金额
// 双十一众多商品进行打折销售，小明想购买自己心仪的一些物品，但由于受购买资金限制，所以他决定从众多心仪商品中购买三件，而且想尽可能的花完资金。

vector<int> getArrNumForString(string str) {
    vector<int> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',' && tmp.length() > 0) {
            arr.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(stoi(tmp));
    }
    return arr;
}

bool compare(vector<int> a, vector<int> b) {
    if (a[0] > b[0]) {
        return true;
    } else {
        return false;
    }
}

int getResult(vector<int> nums, int target) {
    if (nums.size() < 3) {
        return -1;
    }
    sort(nums.begin(), nums.end());
    int ans = -1;
    for (int i = 0; i < nums.size(); i++) {
        int l = i + 1;
        int r = (int)nums.size() - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum == target) {
                return sum;
            } else if (sum < target) {
                ans = max(ans, sum);
                l++;
            } else {
                r--;
            }
        }
    }
    return ans;
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    vector<int> nums = getArrNumForString(str);
    int target;
    cin >> target;
    
    cout << getResult(nums, target) << endl;
    
    return 0;
}
