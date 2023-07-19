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

// 找车位
// 停车场有一横排车位，0代表没有停车，1代表有车。至少停了一辆车在车位上，也至少有一个空位没有停车。

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
    vector<int> leftFree(n);
    for (int i = 1; i < n; i++) {
        if (arr[i] == 1) {
            continue;
        }
        if (arr[i - 1] == 0) {
            leftFree[i] = leftFree[i - 1] + 1;
        } else {
            leftFree[i] = 0;
        }
    }
    
    vector<int> rightFree(n);
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] == 1) {
            continue;
        }
        if (arr[i + 1] == 0) {
            rightFree[i] = rightFree[i + 1] + 1;
        } else {
            rightFree[i] = 0;
        }
    }
    
    int ans = max(rightFree[0], leftFree[n - 1]);
    for (int i = 1; i < n - 1; i++) {
        if (arr[i] == 1) {
            continue;
        }
        ans = max(ans, min(leftFree[i], rightFree[i]));
    }
    
    
    return ans + 1;
    
}

int main(int argc, const char * argv[]) {

    string str;
    getline(cin, str);
    vector<int> arr = getArrStrForString(str);
   
    cout << getResult(arr) << endl;
    
    return 0;
}
