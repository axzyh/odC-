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



// 找最小数
// 给一个正整数NUM1，计算出新正整数NUM2，NUM2为NUM1中移除N位数字后的结果，需要使得NUM2的值最小。

vector<string> getArrForString(string s) {
    vector<string> sVec;
    
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            sVec.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        sVec.push_back(tmp);
    }
    
    return sVec;
}




string getResult(string num, int removeCount) {
    if (num.length() == removeCount) {
        return "0";
    }
    
    int remainCount = num.length() - removeCount;
    stack<char> st;
    for (int i = 0; i < num.length(); i++) {
        while (st.size() > 0 && removeCount > 0 && st.top() > num[i]) {
            st.pop();
            removeCount--;
        }
        st.push(num[i]);
    }
    
    while (st.size() > remainCount) {
        st.pop();
    }
    string ans;
    while (st.size() > 0) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main(int argc, const char * argv[]) {
    string num;
    int count;
    getline(cin, num);
    cin >> count;
    
   cout << getResult(num,count) << endl;
    return 0;
}
