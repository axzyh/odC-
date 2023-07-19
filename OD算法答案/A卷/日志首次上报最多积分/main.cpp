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

// 日志首次上报最多积分
// 日志采集是运维系统的的核心组件。日志是按行生成，每行记做一条，由采集系统分批上报。
/*
 3 7 40 10 60
*/

vector<int> getArrStringForS(string str) {
    vector<int> arr;
    string temp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && temp.length() > 0) {
            arr.push_back(stoi(temp));
            temp = "";
        } else {
            temp += c;
        }
    }
    if (temp.length() > 0) {
        arr.push_back(stoi(temp));
    }
    return arr;
}


bool compare(int a, int b) {
    if (a > b) {
        return true;
    }
    return false;
}

int getResult(vector<int> arr) {
    int n = (int)arr.size();
    vector<int> dp(n);
    dp[0] = arr[0];
    vector<int> delay(n);
    vector<int> score(n);
    score[0] = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = min(100, dp[i-1] + arr[i]);
        delay[i] = delay[i - 1] + dp[i - 1];
        score[i] = dp[i] - delay[i];
        if (dp[i] >= 100) {
            break;
        }
    }
    
    sort(score.begin(), score.end(), compare);
    
    return score[0];
}



int main(int argc, const char * argv[]) {
  
    string str;
    getline(cin, str);
    
    vector<int> arr = getArrStringForS(str);

  
   cout << getResult(arr) << endl;
//
    return 0;
}




