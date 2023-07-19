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

// 查找接口成功率最优时间段
// 服务之间交换的接口成功率作为服务调用关键质量特性，某个时间段内的接口失败率使用一个数组表示，

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

string getResult(int minAverageLost,string str) {
    vector<int> arr = getArrStrForString(str);
    int n = (int)arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + arr[i];
    }
    
    vector<vector<int>> ans;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = i == 0 ? dp[j] : dp[j] - dp[i - 1];
            int len = j - i + 1;
            int lost = len * minAverageLost;
            if (sum <= lost) {
                if (len > maxLen) {
                    ans = vector<vector<int>>();
                    ans.push_back({i,j});
                    maxLen = len;
                } else if (len == maxLen) {
                    ans.push_back({i,j});
                }
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    string res;
    for (int i = 0; i < ans.size(); i++) {
        if (res.length() > 0) {
            res += " ";
        }
        res += to_string(ans[i][0]) + "-" + to_string(ans[i][1]);
    }
    
    
    return res;
}

int main(int argc, const char * argv[]) {
    int minAverageLost;
    cin >> minAverageLost;
    cin.ignore();
    string str;
    getline(cin,str);
    cout << getResult(minAverageLost, str) << endl;
    
    return 0;
}
