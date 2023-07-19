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
#include <iomanip>


using namespace std;

// 最多获得的短信条数、云短信平台优惠活动
// 某云短信厂商，为庆祝国庆，推出充值优惠活动。
/*
6
10 20 30 40 60
*/

vector<int> getArrStringForS(string str) {
    vector<int> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && tmp.length() > 0) {
            arr.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(stoi(tmp));
    }
    return arr;
}

int getResult(int m, vector<int> prices) {
    
    vector<int> dp(m + 1);
    for (int i = 1; i <= prices.size(); i++) {
        for (int j = 1; j <= m; j++) {
            if (j < i) continue;
            dp[j] = max(dp[j], dp[j - i] + prices[i - 1]);
        }
    }
    return dp[m];
}



int main(int argc, const char * argv[]) {
  
    int m;
    string price;
    cin >> m;
    cin.ignore();
    getline(cin, price);
  
    
    vector<int> prices = getArrStringForS(price);

    cout << getResult(m, prices) << endl;
//
    return 0;
}




