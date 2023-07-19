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

// 绘图机器
// 绘图机器的绘图笔初始位置在原点(0,0)机器启动后按照以下规则来进行绘制直线。

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

long getResult(int n,int e,vector<int> offsets) {
    if (e == 0) {
        return 0;
    }
    
    vector<int> dp(e);
    
    int ans = dp[0] = offsets[0];
    for (int i = 1; i < offsets.size(); i++) {
        dp[i] = dp[i - 1] + offsets[i];
        ans += abs(dp[i]);
    }
   
    return ans;
}

int main(int argc, const char * argv[]) {
   
    int n,e;
    cin >> n >> e;
    vector<int> offsets(e);
    int x, offsetY;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cin >> offsetY;
        offsets[x] = offsetY;
    }
   
  cout << getResult(n,e,offsets) << endl;
    
    return 0;
}
