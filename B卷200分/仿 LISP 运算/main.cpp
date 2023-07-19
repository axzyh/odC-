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

// 仿LISP运算
// LISP 语言唯一的语法就是括号要配对。
//

string operate(string op, int p1, int p2) {
    if (op == "add") {
        return to_string(p1 + p2);
    }
    if (op == "sub") {
        return to_string(p1 - p2);
    }
    if (op == "mul") {
        return to_string(p1 * p2);
    }
    if (op == "div") {
        return p2 == 0 ? "error": to_string((int)floor(p1/(p2 + 0.0)));
    }
    return "error";
}

vector<char> getArrForStack(vector<int> &leftIdx, stack<char> &st) {
    vector<char> arr;
    int idx = leftIdx.back();
    leftIdx.pop_back();
    while (st.size() > idx) {
        
        char c = st.top();
        st.pop();
        arr.insert(arr.begin(), c);
    }
    return arr;
}

vector<string> splitString(string s) {
    string tmp;
    vector<string> arr;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == ' ') {
            arr.push_back(tmp);
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(tmp);
    }
    return arr;
    
}

string getResult(string str) {
    stack<char> st;
    vector<int> leftIdx;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ')') {
            vector<char> fragment = getArrForStack(leftIdx, st);
            string tmp;
            for (int j = 1; j < fragment.size(); j++) {
                tmp += fragment[j];
            }
            vector<string> arr = splitString(tmp);
            string op = arr[0];
            int p1 = stoi(arr[1]);
            int p2 = stoi(arr[2]);
            string res = operate(op, p1, p2);
            if (res == "error") {
                return res;
            } else {
                for (int k = 0; k < res.length(); k++) {
                    st.push(res[k]);
                }
            }
            
        } else if (c == '(') {
            leftIdx.push_back((int)st.size());
            st.push(c);
        } else {
            st.push(c);
        }
    }
    
    string ans;
    while (st.size() > 0) {
        char c = st.top();
        st.pop();
        ans = c + ans;
    }
    return ans;
   
   
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    
   cout << getResult(str) << endl;
    
    
    return 0;
}
