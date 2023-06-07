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



// 数组二叉树
// 二叉树也可以用数组来存储，给定一个数组，树的根节点的值存储在下标1，对于存储在下标N的节点，它的左子节点和右子节点分别存储在下标2*N和2*N+1，并且我们用值-1代表一个节点为空。


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


string getResult(vector<int>nums) {
    int n = (int)nums.size() - 1;
    int min = INT_MAX;
    int minIdx = -1;
    
    for (int i = n; i > 0; i--) {
        if (nums[i] != -1) {
            if (i * 2 + 1 <= n && nums[i*2 + 1] != -1 ) {
                continue;
            }
            if (i * 2 + 2 <= n && nums[i*2 + 2] != -1 ) {
                continue;;
            }
            if (min > nums[i]) {
                min = nums[i];
                minIdx = i;
            }
        }
    }
    
    vector<int>path;
    path.push_back(min);
    
    while (minIdx != 0) {
        int f = (minIdx - 1) /2;
        path.push_back(nums[f]);
        minIdx = f;
    }
    
    string ans;
    for (int re: path) {
        if (ans.length() > 0) {
            ans += " ";
        }
        ans += to_string(re);
    }
    reverse(ans.begin(), ans.end());
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
