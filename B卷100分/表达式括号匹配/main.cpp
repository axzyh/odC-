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

// 表达式括号匹配
// (1+(2+3)*(3+(8+0))+1-2)这是一个简单的数学表达式,今天不是计算它的值,而是比较它的

int getResult(string str) {
    int count = 0;
    stack<char> st;
    string ans;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '(' || c == ')') {
            ans += c;
        }
    }
    
    for (int i = 0; i < ans.length(); i++) {
        char c = ans[i];
        if (st.size() > 0 && c == ')') {
            if (st.top() == '(') {
                st.pop();
                count++;
                continue;
            }
            return -1;
        }
        st.push(c);
    }
    
    if (st.size() > 0) {
        return -1;
    }
    
    return count;
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    
    cout << getResult(str) << endl;
    
    return 0;
}
