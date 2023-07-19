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
#include <stack>
#include <queue>
#include <unordered_set>
//#include <iterator>

using namespace std;

// 目录删除
// 某文件系统中有 N 个目录，每个目录都有一个独一无二的 ID。。
//


void dfs(unordered_map<int, vector<int>> tree,int node, int del, vector<int> &res) {
 
    if (tree.count(node)) {
        vector<int>children = tree[node];
        for (int child : children) {
            if (child != del) {
                res.push_back(child);
                dfs(tree, child, del, res);
            }
        }
    }
    
}

string getResult(int m, vector<vector<int>> relatios, int del) {
    
    unordered_map<int, vector<int>> tree;
    for (vector<int> relation : relatios) {
        int child = relation[0];
        int father = relation[1];
        tree[father].push_back(child);
    }
    if (del == 0) {
        return "";
    }
    
    vector<int> res;
    dfs(tree, 0, del, res);
    sort(res.begin(), res.end());
    
    string ans;
    for (int re : res) {
        if (ans.length() > 0) {
            ans += " ";
        }
        ans += to_string(re);
    }
   
    return ans;
   
   
}

int main(int argc, const char * argv[]) {
    int m;
    cin >> m;
    vector<vector<int>> relations(m,vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> relations[i][0] >> relations[i][1];
    }
    
    int del;
    cin >> del;
    
   cout << getResult(m, relations, del) << endl;
    
    
    return 0;
}
