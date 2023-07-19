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

// 矩阵最大值
// 给定一个仅包含0和1的N*N二维矩阵，请计算二维矩阵的最大值，计算规则如下：


vector<int> getArrStrForString(string s) {
    vector<int> arr;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',' && tmp.length() > 0) {
            arr.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(stoi(tmp));
    }
    return arr;
}


int charInt(char target) {
    if (target >= '0' && target <= '9') {
        return target - '0';
    } else {
        return target - 'A' + 10;
    }
}

int getjinzhi(string str, int two) {
    int num = 0;
    for (int i = 0; i < str.length(); i++) {
        num *= two;
        num += charInt(str[i]);
        
    }
    return num;
}


int getVal(vector<int> dp) {
    string ans;
    for (int v : dp) {
        ans += to_string(v);
    }
    return getjinzhi(ans, 2);
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    cin.ignore();
    string str;
   
    int ans = 0;
    for (int i = 0; i < n; i++) {
        getline(cin, str);
        vector<int> dp = getArrStrForString(str);
        int maxVal = getVal(dp);
        for (int j = 1; j < n; j++) {
            dp.push_back(dp[0]);
            dp.erase(dp.begin());
            maxVal = max(maxVal,getVal(dp));
        }
        ans += maxVal;
    }
    
    cout << ans << endl;
    
    return 0;
}
