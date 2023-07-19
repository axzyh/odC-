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

// 树状结构查询
// 通常使用多行的节点、父节点表示一棵树，比如
//

void getResult(int n, unordered_map<string, set<string>>tree, string target) {
    
    if (!tree.count(target)) {
        cout << "" << endl;
        return;
    }
    
    queue<string> q;
    for (string s: tree[target]) {
        q.push(s);
    }
    vector<string> ans;
    
    while (q.size() > 0) {
        string node = q.front();
        q.pop();
        ans.push_back(node);
        if (tree.count(node)) {
            for (string s : tree[node]) {
                q.push(s);
            }
        }
    }
    sort(ans.begin(), ans.end());
    
    for (string an : ans) {
        cout << an << endl;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    string target;
    unordered_map<string, set<string>> tree;
    string ch, fa;
    for (int i = 0; i < n; i++) {
        cin >> ch >> fa;
        tree[fa].insert(ch);
    }
    cin >> target;
    getResult(n,tree,target);
    
    
    return 0;
}
