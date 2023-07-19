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

// 字符串分割
// 给定非空字符串s，将该字符串分割成一些子串，使每个子串的ASCII码值的和均为水仙花数

vector<int> getArrStrForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' '&& tmp.length() > 0) {
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

bool isSxh(int num) {
    if (num <= 99 || num >= 1000) {
        return false;
    }
    string nums = to_string(num);
    vector<char> tmp(nums.begin(), nums.end());
    
    int x = tmp[0] - '0';
    int y = tmp[1] - '0';
    int z = tmp[2] - '0';
    
    return num == pow(x, 3) + pow(y, 3) + pow(z, 3);
    
    
}

void recursive(vector<int> &preSum, int n, int start, int count, vector<int> &res) {
    
    cout << start << " " << count << endl;
    if (start == n) {
        res.push_back(count);
        return;
    }
    
    for (int end = start + 1; end <= n; end++) {
        if (isSxh(preSum[end] - preSum[start])) {
            recursive(preSum, n, end, count+1, res);
        }
    }
    
}


int getResult(string s) {

    vector<char> cArr(s.begin(),s.end());
    
    int n = (int)cArr.size();
    
    vector<int> preSum(n + 1);
    for (int i = 1; i <= n; i++) {
        preSum[i] = preSum[i - 1] + cArr[i - 1];
    }
    
    vector<int> res;
    recursive(preSum, n, 0, 0, res);
    if (res.size() == 0) {
        return 0;
    } else if (res.size() == 1) {
        return res[0];
    } else {
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);

    cout << getResult(str) << endl;
    
    return 0;
}
