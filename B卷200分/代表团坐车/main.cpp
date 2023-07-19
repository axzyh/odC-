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



// 代表团坐车
//某组织举行会议，来了多个代表团同时到达，接待处只有一辆汽车，可以同时接待多个代表团，为了提高车辆利用率，请帮接待员计算可以坐满车的接待方案，输出方案数量。

vector<int> sprtStringToVecInt(string str,char c) {
    vector<int> vec ;
    string temp;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c && temp.length() > 0) {
            vec.push_back(stoi(temp));
            temp = "";
        } else {
            temp += str[i];
        }
    }
    if (temp.length() > 0) {
        vec.push_back(stoi(temp));
        temp = "";
    }
    return vec;
}


int getResult(vector<int>vec,int b) {

    int n = (int)vec.size();
    // 声明dp数组
    vector<vector<int>>dp(n+1,vector<int>(b + 1));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        int num = vec[i - 1];
        for (int j = 0; j <= b; j++) {
            if (j < num) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num];
            }
        }
    }
    // 全部遍历,取出每个位置组合
    return dp[n][b];
   
}

int main(int argc, const char * argv[]) {
    string str;
    int b;
    getline(cin, str);
    cin >> b;
    vector<int> vec = sprtStringToVecInt(str, ',');
   cout << getResult(vec,b) << endl;
    
    return 0;
}
