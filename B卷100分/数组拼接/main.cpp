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

// 数组拼接
// 现在有多组整数数组，需要将它们合并成一个新的数组。

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

vector<int> removeRange(vector<int> &list, int start, int end) {
    if (end > list.size()) {
        end = (int)list.size();
    }
    vector<int> tmp(list.begin() + start, list.begin() + end);
    vector<int> ans = tmp;
    tmp.clear();
    for (int i = end - 1; i >= 0; i--) {
        list.erase(list.begin() + i);
    }
    return ans;
}


string getResult(int subLen, int n, vector<vector<int>> nums) {
    vector<int> ans;
    while (nums.size() > 0) {
        vector<int> list = nums[0];
        nums.erase(nums.begin() + 0);
        vector<int> tmp = removeRange(list, 0, subLen);
        ans.insert(ans.end(), tmp.begin(),tmp.end());
        if (list.size() > 0) {
            nums.push_back(list);
        }
    }
    string res;
    for (int an : ans) {
        if (res.length() > 0) {
            res += ",";
        }
        res += to_string(an);
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    int subLen, n;
    cin >> subLen >> n;
    cin.ignore();
    string s1;
    vector<vector<int>> nums(n);
    for (int i = 0; i < n; i++) {
        getline(cin, s1);
        nums[i] = getArrNumsForString(s1);
    }
    
    cout << getResult(subLen,n,nums) << endl;
    
    return 0;
}
