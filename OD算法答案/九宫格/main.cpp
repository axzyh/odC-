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



// 九宫格
// 九宫格是一款广为流传的游戏，起源于河图洛书。
// 游戏规则是：1到9九个数字放在3×3的格子中，要求每行、每列以及两个对角线上的三数之和都等于15.
vector<int> getStringForTest(string s) {
    string tmp;
    vector<int> ans;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            
        } else if (s[i] == ',' || s[i] == ']') {
            ans.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    return ans;
}

vector<int> getArrForString(string s) {
    vector<int> res;
    string temp;
    for (int i = 0; i < s.length(); i++) {
        if (temp.length() > 0 && s[i] == ' ') {
            res.push_back(stoi(temp));
            temp = "";
        } else {
            temp += s[i];
        }
    }
    if (temp.length() > 0) {
        res.push_back(stoi(temp));
    }
    return res;
}

bool check(vector<int>path) {
    vector<int>a = path;
    int r1 = a[0] * a[1] * a[2];
    int r2 = a[3] * a[4] * a[5];
    if (r1 != r2) {
        return false;
    }
    int r3 = a[6] * a[7] * a[8];
    if (r1 != r3) {
        return false;
    }
    int c1 = a[0] * a[3] * a[6];
    if (r1 != c1) {
        return false;
    }
    int c2 = a[1] * a[4] * a[7];
    if (r1 != c2) {
        return false;
    }
    int c3 = a[2] * a[5] * a[8];
    if (r1 != c3 ) {
        return false;
    }
    
    int s1 = a[0] * a[4] * a[8];
    if (r1 != s1 ) {
        return false;
    }
    
    int s2 = a[2] * a[4] * a[6];
    if (r1 != s2 ) {
        return false;
    }
    return true;
}

void dfs(vector<int> arr, vector<bool> used,vector<int>path,vector<vector<int>> &res) {
    if (path.size() == arr.size()) {
        if (check(path)) {
            vector<int> a = path;
            res.push_back(a);
        }
        return;
    }
    
    for (int i = 0; i < arr.size(); i++) {
        if (!used[i]) {
            path.push_back(arr[i]);
            used[i] = true;
            dfs(arr, used, path, res);
            used[i] = false;
            path.pop_back();
        }
    }
    
}

bool compare(vector<int>a, vector<int>b) {
    for (int i = 0; i < 9; i++) {
        if (a[i] < b[i]) {
            return true;
        } else if (a[i] > b[i]) {
            return false;
        } else {
            return false;
        }
    }
    return false;
}

void getResult(vector<int> arr) {
    vector<bool>used(arr.size());
    vector<int> path;
    vector<vector<int>> res;
    dfs(arr, used, path, res);
    sort(res.begin(), res.end(),compare);
    
    for (auto re:res) {
        string sj;
        for (auto i : re) {
            sj += to_string(i);
            sj += " ";
        }
        cout << sj << endl;
        
    }
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    vector<int>vec = getArrForString(str);
     getResult(vec);
    
    return 0;
}
