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

// 二叉树中序遍历
// 根据给定的二叉树结构描述字符串，输出该二叉树按照中序遍历结果字符串。中序遍历顺序为：左子树，根结点，右子树。


string removeStackEles(stack<string> &stack, int start) {
    string ans ;
    while (start < stack.size()) {
        ans = stack.top() + ans;
        stack.pop();
    }
    return ans;
}

string getResult(string str) {
   
    vector<int> idxs;
    stack<string> stack;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '}') {
            int idx = idxs.back();
            idxs.pop_back();
            string subTree = removeStackEles(stack, idx + 1);
            stack.pop();
            string root = stack.top();
            stack.pop();
            int pos = (int)subTree.find(',');
            vector<string> split;
            if (pos == -1) {
                split.push_back(subTree);
            } else {
                split.push_back(subTree.substr(0,pos));
            }
            string left = split[0];
            string right = pos != -1 ? subTree.substr(pos + 1,subTree.length() - pos) : "";
            stack.push(left + root + right);
            continue;
        }
        if (c == '{') {
            idxs.push_back(stack.size());
        }
        string tmp;
        tmp += c;
        stack.push(tmp);
        
    }
    return stack.top();
    
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    cout << getResult(str) << endl;
    return 0;
}
