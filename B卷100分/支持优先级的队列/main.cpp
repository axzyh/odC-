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
#include <unordered_set>

using namespace std;



// 支持优先级的队列
// 实现一个支持优先级的队列，高优先级先出队列；同优先级时先进先出。

vector<vector<int>> getNumsArrForString(string str) {
    vector<vector<int>> arr;
    string tmp;
    vector<int> tmpArr;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == '(' || (tmp.length() == 0 && c == ',')) {
            continue;
        }
        if (c == ','  && tmp.length() > 0) {
            tmpArr.push_back(stoi(tmp));
            tmp = "";
        } else if (c == ')' && tmp.length() > 0) {
            tmpArr.push_back(stoi(tmp));
            tmp = "";
            arr.push_back(tmpArr);
            tmpArr.clear();
        } else {
            tmp += c;
        }
    }
    
    return arr;
}

bool check(int m, int add,vector<int>nums) {
    m -= nums[0];
    for (int i = 1; i <nums.size(); i++) {
        m += add;
        if (m > nums[i]) {
            m -= nums[i];
        } else {
            return false;
        }
    }
    return true;
}

string getResult(string str) {
    
    vector<vector<int>> arr = getNumsArrForString(str);
    
    map<int, unordered_set<int>> map;
    for (vector<int> ar : arr) {
        int num = ar[0];
        int priority = ar[1];
        map[priority].insert(map[priority].end(),num);
    }
    
    string res;
    for (auto key:map) {
        string ans;
        for (int num : key.second) {
            if (ans.length() > 0) {
                ans += ",";
            }
            ans += to_string(num);
        }
        if (res.length() > 0) {
            res = ans + "," + res;
        } else {
            res = ans;
        }
       
        
    }
    
  
    return res;
}

int main(int argc, const char * argv[]) {
  
    string str;
    getline(cin, str);
    
    cout << getResult(str) << endl;
    
    return 0;
}
