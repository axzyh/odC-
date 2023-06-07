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



// 模拟消息队列
// 让我们来模拟一个消息队列的运作，有一个发布者和若干消费者，发布者会在给定的时刻向消息队列发送消息，


vector<int> getNumsForString(string s) {
    string tmp;
    vector<int> tVec;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            continue;
        }
        if (s[i] == ',' || s[i] == ')') {
            tVec.push_back(stoi(tmp));
            tmp = "";
            continue;
        }
        tmp +=s[i];
    }
    
    
    return tVec;
}

int getResult(unordered_map<int, vector<int>> children,unordered_map<int, int>cap,int target) {
    int ans = 0;
    stack<int> st;
    st.push(target);
    
    while (st.size() > 0) {
        int id = st.top();
        st.pop();
        if (!cap.count(id)) {
            continue;
        }
        ans +=cap[id];
        if (children.count(id)) {
            for (int i = 0; i < children[id].size(); i++) {
                st.push(children[id][i]);
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    int m,n;
    string str;
    cin >> m >> n;
    unordered_map<int, vector<int>> children;
    unordered_map<int, int> cap;
    
    for (int i = 0; i < m; i++) {
        int fa_id;
        int fa_cap;
        cin >> fa_id >> fa_cap;
        children[fa_id] = vector<int>();
        cap[fa_id] = fa_cap;
        cin.ignore();
        getline(cin, str);
        if (str.length() > 2) {
            vector<int> vec1 = getNumsForString(str);
            vector<int> vec = children[fa_id];
            vec.insert(vec.end(),vec1.begin(),vec1.end());
            children[fa_id] = vec;
        }
    }
    
    cout << getResult(children, cap, n) << endl;
    return 0;
}
