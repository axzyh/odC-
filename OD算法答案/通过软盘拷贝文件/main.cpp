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



// 通过软盘拷贝文件
//有一名科学家想要从一台古董电脑中拷贝文件到自己的电脑中加以研究。

// 字符串分割成整型数组
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

void findNextBig(vector<int> arr,stack<pair<int, int>>&stack,vector<int> &res) {
    for (int i = 0; i < arr.size(); i++) {
        int ele = arr[i];
        while (true) {
            if (stack.size() == 0) {
                stack.push(make_pair(ele, i));
                break;
            } else {
                pair<int, int> peek = stack.top();
                int peekEle = peek.first;
                int peekIndex = peek.second;
                if (ele > peekEle) {
                    res[peekIndex] = ele;
                    stack.pop();
                } else {
                    stack.push(make_pair(ele, i));
                    break;
                }
            }
        }
    }
    
}

int getResult(vector<int> bags, int n ) {
   
    int bag = ceil(1474560 / 512.0);
    vector<vector<int>>dp(n + 1,vector<int>(bag + 1));
    
    for (int i = 1; i <= n; i++) {
        int weight = ceil(bags[i - 1]/ 512.0);
        int worth = bags[i - 1];
        for (int j = 0; j <= bag; j++) {
            if (weight > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i - 1][j - weight] + worth);
            }
        }
    }
    return dp[n][bag];
    
    return 0;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int>bags(n);
    for (int i = 0; i < n; i++) {
        cin >> bags[i];
    }
   
    
   cout << getResult(bags,n) << endl;
    return 0;
}
