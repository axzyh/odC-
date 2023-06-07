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



// 最大数字
// 给定一个由纯数字组成以字符串表示的数值，现要求字符串中的每个数字最多只能出现2次，超过的需要进行删除；
// 删除某个重复的数字后，其它数字相对位置保持不变。

string getResult(string s) {
    //字符可用个数
    map<char, int> unused;
    // 字符保留个数
    map<char, int> reserve;
    for (int i = 0; i < s.length(); i++) {
        char c= s[i];
        unused[c]++;
        reserve[c] = 0;
    }
    
    stack<char> stack;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (reserve[c] == 2) {
            unused[c]--;
            continue;
        }
        while (stack.size() > 0) {
            char top = stack.top();
            if (top < c && unused[top] + reserve[top] - 1 >= 2) {
                stack.pop();
                reserve[top]--;
            } else {
                break;
            }
        }
        stack.push(c);
        unused[c]--;
        reserve[c]++;
    }
    
    string temp;
    while (stack.size() > 0) {
        temp = stack.top() + temp;
        stack.pop();
    }
    return temp;
}

int main(int argc, const char * argv[]) {
    
    string str;
    getline(cin, str);
    
    cout << getResult(str) << endl;
    
    return 0;
}
