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



// 报文解压缩
// 为了提升数据传输的效率，会对传输的报文进行压缩处理。

bool isNumber(char c) {
    if (c >= '0' && c<= '9') {
        return true;
    }
    return false;
}

string repeat(int num, string str) {
    string temp;
    for (int i = 0; i < num; i++) {
        temp += str;
    }
    return temp;
}

string getResult(string s) {
    
    stack<char> st;
    
    string res;
    
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c != ']') {
            st.push(c);
        } else {
            string str;
            while (!st.empty() && (st.top() > '9' || st.top() < '9')) {
                if (st.top() == '[') {
                    st.pop();
                    break;
                }
                str += st.top();
                st.pop();
            }
            reverse(str.begin(), str.end());
           
            string temp;
            while (!st.empty() && isNumber(st.top())) {
                temp = st.top() + temp;
                st.pop();
            }
            int num = 0;
            if (temp.length() > 0) {
                num = stoi(temp);
                temp = "";
            }
            str = repeat(num, str);
            for (auto i : str) {
                st.push(i);
            }
        }
    }
    
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
  
    return res;
}



int main(int argc, const char * argv[]) {
    string s;
    getline(cin, s);
    
    
    cout << getResult(s) << endl;
    
    return 0;
}
