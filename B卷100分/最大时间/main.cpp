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

// 最大时间
// 给定一个数组，里面有 6 个整数，求这个数组能够表示的最大 24 进制的时间是多少，输出这个时间，无法表示输出 invalid。

vector<int> getArrStrForString(string str) {
    vector<int> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ','&& tmp.length() > 0) {
            vec.push_back(stoi(tmp));
            tmp = "";
        } else if(isnumber(str[i])) {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(stoi(tmp));
    }
    return vec;
}

regex c("(([01][0-9])||([2][0-3])):([0-5][0-9]):([0-5][0-9])");


void dfs(vector<int> &arr, vector<bool> used, vector<int> &path, vector<string> &res) {
    if (path.size() == arr.size()) {
        string time = to_string(path[0]) + to_string(path[1]) + ":" + to_string(path[2]) + to_string(path[3]) + ":" + to_string(path[4]) + to_string(path[5]);
        smatch matchR;
        if (regex_match(time, matchR, c)) {// 满足，添加
            res.push_back(time);
        }
        return;
    }
    for (int i = 0; i < arr.size(); i++) {
        if (used[i]) {
            continue;
        }
        path.push_back(arr[i]);
        used[i] = true;
        dfs(arr, used, path, res);
        used[i] = false;
        path.pop_back();
    }
    
}

string getResult(vector<int> arr) {
    vector<string> res;
    vector<bool> used(arr.size());
    vector<int> path;
    dfs(arr, used, path, res);
    if (res.size() == 0) {
        return "invalid";
    }
    sort(res.begin(), res.end());
    return res[res.size() - 1];
    
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    vector<int> arr = getArrStrForString(str);
   
    cout << getResult(arr) << endl;
    
    return 0;
}
