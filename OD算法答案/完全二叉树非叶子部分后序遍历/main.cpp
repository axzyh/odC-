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



// 完全二叉树非叶子部分后序遍历
// 给定一个以顺序储存结构存储整数值的完全二叉树序列（最多1000个整数），请找出此完全二叉树的所有非叶子节点部分，然后采用后序遍历方式将此部分树（不包含叶子）输出。


vector<int> getArrForString(string s) {
    vector<int> sVec;
    
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            sVec.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        sVec.push_back(stoi(tmp));
    }
    
    return sVec;
}

void dfs(vector<int> nums, int root, vector<int> &res) {
    int left = root * 2+ 1;
    int right = root * 2 + 2;
    if (nums.size() > left) {
        dfs(nums, left, res);
        if (nums.size() > right) {
            dfs(nums, right, res);
        }
        res.push_back(nums[root]);
    }
}

string getResult(vector<int>nums) {
    if (nums.size() == 1) {
        return to_string(nums[0]);
    }
    vector<int> res;
    dfs(nums, 0, res);
    
    string ans;
    for (int re: res) {
        if (ans.length() > 0) {
            ans += " ";
        }
        ans += to_string(re);
    }
    
    return ans;
    
    
   
    return "";
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    vector<int> nums = getArrForString(str);
   cout << getResult(nums) << endl;
    return 0;
}
