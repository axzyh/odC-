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

// 评论转换输出
// 在一个博客网站上，每篇博客都有评论。
//



vector<string> getArrNumsForString(string s) {
    vector<string> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',' && tmp.length() > 0) {
            nums.push_back(tmp);
            tmp = "";
        }
        else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(tmp);
    }
    return nums;
}

void recusive(queue<string> &q, int level, int childCount, vector<vector<string>> &tree) {
    for (int i = 0; i < childCount; i++) {
        string comment = q.front();
        q.pop();
        if (tree.size() < level) {
            tree.push_back(vector<string>());
        }
        tree[level- 1].push_back(comment);
        int count = stoi(q.front());
        q.pop();
        if (count > 0) {
            recusive(q, level + 1, count, tree);
        }
    }
}

void getResult(vector<string> nums) {
    vector<vector<string>> tree;
    queue<string> q;
    for (string num : nums) {
        q.push(num);
    }
    int level = 1;
    while (q.size() > 0) {
        string comment = q.front();
        q.pop();
        if (tree.size() < level) {
            tree.push_back(vector<string>());
        }
        tree[0].push_back(comment);
        
        int childCount = stoi(q.front());
        q.pop();
        recusive(q, level + 1, childCount, tree);
    }
    cout << tree.size() << endl;
    for (vector<string> levelNods : tree) {
        string res;
        for (string nodes : levelNods) {
            if (res.length() > 0) {
                res += " ";
            }
            res += nodes;
        }
        
        cout << res;
        cout << endl;
    }
    
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    vector<string> nums = getArrNumsForString(str);
    getResult(nums);
    return 0;
}
