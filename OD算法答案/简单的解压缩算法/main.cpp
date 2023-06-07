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

// 简单的解压缩算法
// 现需要实现一种算法，能将一组压缩字符串还原成原始字符串，
void updateStack(stack<string>&stack,int left,int repeat,bool isRemove) {
    int count = (int)stack.size() - left;
    vector<string>frag(count);
    while (count-- > 0) {
        
        frag[count] = stack.top();
        stack.pop();
    }
    if (!stack.empty() &&isRemove && stack.top() == "{") {
        stack.pop();
    }
    
    string sb;
    for (string s : frag) {
        sb += s;
    }
    string fragment = sb;
    string ans;
    for (int i = 0; i < repeat; i++) {
        ans +=fragment;
    }
    stack.push(ans);
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    stack<string> stack;
    vector<int> idxs;
    string repeat;
    str += " ";
    for (int i = 0 ; i < str.length(); i++) {
        char c = str[i];
        if (c >= '0' && c <= '9') {
            repeat +=c;
            continue;
        }
        if (repeat.length() > 0) {
            int n = stoi(repeat);
            repeat = "";
            if (stack.top() == "}") {
                int left = idxs.back() + 1;
                idxs.pop_back();
                stack.pop();
                updateStack(stack, left, n,true);
            } else {
                updateStack(stack, (int)stack.size() - 1, n,false);
            }
        }
        if (c == '{') {
            idxs.push_back((int)stack.size());
        }
        
        stack.push(string(1,c));
    }
    string sb;
    while (stack.size()) {
        sb = stack.top() + sb;
        stack.pop();
    }
    cout << sb << endl;
    
    return 0;
}
