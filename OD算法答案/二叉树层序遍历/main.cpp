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

// 二叉树层序遍历
// 有一棵二叉树，每个节点由一个大写字母标识(最多26个节点）。


void devideLR(string post, string mid, queue<vector<string>> &queue,vector<char> &ans) {
    char rootEle = post[post.length() - 1];
    ans.push_back(rootEle);
    int rootIdx = (int)mid.find(rootEle);
    int leftLen = rootIdx;
    if (leftLen > 0) {
        string leftPost = post.substr(0,leftLen);
        string leftMid = mid.substr(0,rootIdx);
        queue.push({leftPost,leftMid});
    }
    if (post.length() - 1 - leftLen > 0) {
        string rightPost = post.substr(leftLen,post.length() - 1 - leftLen);
        string rightMid = mid.substr(rootIdx + 1);
        queue.push({rightPost,rightMid});
    }
    
}

string getResult(string post, string mid) {
    queue<vector<string>> queue;
    vector<char> ans;
    devideLR(post, mid, queue, ans);
    while (queue.size() > 0) {
        vector<string> temp = queue.front();
        queue.pop();
        devideLR(temp[0], temp[1], queue, ans);
    }
    string res;
    for (char c : ans) {
        res += c;
    }
    return res;
    
}

int main(int argc, const char * argv[]) {
    string post, mid;
    
//    getline(cin, post);
//    getline(cin, mid);
    cin >> post;
    cin >> mid;
    
    cout << getResult(post, mid) << endl;
    return 0;
}
