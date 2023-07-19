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

// 找出经过特定点的路径长度
// 无 ANTSEDXQOKPUVGIFWHJLYMCRZB



void dfs(int index, string must, unordered_map<char, vector<int>>mustCharIndex, vector<int> &path, vector<int> &ans) {
    if (path.size() == must.length()) {
        int dis = path[0];
        for (int i = 1; i < path.size(); i++) {
            dis += abs(path[i] - path[i - 1]);
        }
        ans[0] = min(ans[0], dis);
        return;
    }
    
    for (int i = index; i < must.length(); i++) {
        vector<int> idxs = mustCharIndex[must[i]];
        for (int idx: idxs) {
            path.push_back(idx);
            dfs(i + 1, must, mustCharIndex, path, ans);
            path.pop_back();
        }
    }
    
}


int getResult(string all,string must) {
    unordered_map<char, vector<int>> mustCharIdx;
    set<char> mustChar ;
    for (char c : must) {
        mustChar.insert(c);
    }
    
    for (int i = 0; i < all.length(); i++) {
        char c = all[i];
        if (mustChar.count(c)) {
            mustCharIdx[c].push_back(i);
        }
    }
    
    vector<int> ans = {INT_MAX};
    
    vector<int> path;
    dfs(0, must, mustCharIdx, path, ans);
    return ans[0];
}

int main(int argc, const char * argv[]) {
   
    string all, must;
    getline(cin, all);
    getline(cin, must);
    cout << getResult(all, must) << endl;
    
    return 0;
}
