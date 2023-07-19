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

// 金字塔，BOSS的收入
// 微商模式比较典型，下级每赚 100 元就要上交 15 元，给出每个级别的收入，求出金字塔尖上的人收入。

vector<string> getArrStrForString(string str) {
    vector<string> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' '&& tmp.length() > 0) {
            vec.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(tmp);
    }
    return vec;
}

bool compare(vector<int> a, vector<int> b) {
    if (a[1] > b[1]) {
        return true;
    } else {
        return false;
    }
}


string getResult(int n,vector<vector<int>> arr) {
    
    unordered_map<int, int> agent;
    sort(arr.begin(), arr.end(),compare);
    int first = arr[arr.size() - 1][1];
    for (vector<int> ele : arr) {
        int id = ele[0];
        int preId = ele[1];
        int money = ele[2];
        if (agent.count(id)) {
            money += agent[id];
        }
        agent[preId] += money/ 100 * 15;
    }
    
    return to_string(first) + " " + to_string(agent[first]);
}

int main(int argc, const char * argv[]) {

    int n;
    cin >> n;
    vector<vector<int>>arr (n,vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    
    cout << getResult(n,arr) << endl;
    
    return 0;
}
