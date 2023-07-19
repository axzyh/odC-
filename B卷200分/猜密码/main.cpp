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

// 猜密码
// 小杨申请了一个保密柜，但是他忘记了密码。只记得密码都是数字，而且所有数字都是不重复的。

vector<string> getArrForString(string s) {
    vector<string> vec;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            vec.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(tmp);
    }
    return vec;
}


void dfs(vector<string> arr, int index, int level,vector<string> &path,vector<string> &res) {
    if (path.size() >= level) {
        string ans;
        for (string v: path) {
            if (ans.length() > 0) {
                ans += ",";
            }
            ans += v;
        }
        res.push_back(ans);
    }
    for (int i = index; i < arr.size(); i++) {
        path.push_back(arr[i]);
        dfs(arr, i+1, level, path, res);
        path.pop_back();
    }
}

void getResult(vector<string> arr,int level) {
    sort(arr.begin(), arr.end());
    vector<string> res;
    vector<string> path;
    dfs(arr, 0, level, path, res);
    if (res.size() > 0) {
        for (auto i: res) {
            cout << i << endl;
        }
    } else {
        cout << "None" << endl;
    }
}



int main(int argc, const char * argv[]) {
    string s;
    getline(cin, s);
    int level;
    cin >> level;
    vector<string> vec = getArrForString(s);
    
    getResult(vec,level);
    return 0;
}
