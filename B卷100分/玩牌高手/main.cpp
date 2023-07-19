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

// 玩牌高手
// 给定一个长度为n的整型数组，表示一个选手在n轮内可选择的牌面分数。选手基于规则选牌，

vector<int> getArrStrForString(string str) {
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

int getResult(vector<int> arr) {
    int n = (int)arr.size();
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[0] = max(0, arr[i]);
        } else if (i < 3) {
            dp[i] = max(0, dp[i - 1] + arr[i]);
        } else {
            dp[i] = max(dp[i - 3], dp[i - 1] + arr[i]);
        }
    }
    return dp[n - 1];
}

int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    vector<int>vec = getArrStrForString(str);
    
    cout << getResult(vec) << endl;
    
    return 0;
}
