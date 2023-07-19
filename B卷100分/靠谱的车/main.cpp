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

// 靠谱的车
// 程序员小明打了一辆出租车去上班。出于职业敏感，他注意到这辆出租车的计费表有点问题，总是偏大。

vector<int> getArrNumsForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        tmp += str[i];
        vec.push_back(stoi(tmp));
        tmp = "";
    }
    if (tmp.length() > 0) {
        vec.push_back(stoi(tmp));
    }
    return vec;
}

int getResult(vector<int> nums) {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        int fault = nums[i];
        if (fault > 4) {
            fault--;
        }
        for (int j = (int)nums.size() - i - 1; j > 0; j--) {
            fault *=9;
        }
        ans += fault;
    }
   
   
    return ans;
}

int main(int argc, const char * argv[]) {
    
    int m;
    cin >> m;
    vector<int> nums = getArrNumsForString(to_string(m));
    
    cout << getResult(nums) << endl;
    
    return 0;
}
