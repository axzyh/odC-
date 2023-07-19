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

// 最大股票收益
// 假设知道某段连续时间内股票价格，计算通过买入卖出可获得的最大收益。

vector<int> getArrStrForString(string str) {
    vector<int> vec;
    string tmp;
    int price = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' '&& tmp.length() > 0) {
            vec.push_back(price);
            tmp = "";
        } else {
            if (c == 'Y') {
                price = stoi(tmp);
            } else if (c == 'S') {
                price = stoi(tmp) * 7;
            } else {
                tmp += c;
            }
            
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(price);
    }
    return vec;
}


int getResult(vector<int> prices) {
    
    int ans = 0;
    for (int i = 1; i < prices.size(); i++) {
        ans += max(0, prices[i] - prices[i - 1]);
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {

    string str;
    getline(cin, str);
    
    vector<int>prices = getArrStrForString(str);
    cout << getResult(prices) << endl;
    
    return 0;
}
