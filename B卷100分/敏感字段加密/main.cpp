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

// 敏感字段加密
// 给定一个由多个命令字组成的命令字符串：

string getString(queue<char>s) {
    string temp;
    while (!s.empty()) {
        temp += s.front();
        s.pop();
    }
    
    return temp;
}
void getResult() {
    int a;
    string str;
    cin >> a;
    cin.ignore();
    getline(cin, str);
    stack<char> sck;
    queue<char>q;
    vector<string> vec;
    for (auto i : str) {
        if (i == '_' && (q.size() == 0 || q.front() != '"')) {
            vec.push_back(getString(q));
            q =  queue<char>();
        } else if (i == '"'&& q.size() != 0 ) {
            q.push(i);
            vec.push_back(getString(q));
            q =  queue<char>();
        } else {
            q.push(i);
        }
    }
    
    if (q.size() > 0) {
        vec.push_back(getString(q));
    }
    
    for (auto it = vec.begin();it != vec.end(); it++) {
        if (*it == "") {
            it = vec.erase(it);
            it--;
        }
    }
    
    if (a > vec.size()) {
        cout << "ERROR" << endl;
    } else {
        vec[a] = "******";
    }
    
    string sds;
    for (int i = 0; i < vec.size(); i++) {
        if (i > 0  ) {
            sds +="_";
            
        }
            sds += vec[i];
    }
    cout << sds <<endl;
}

int main(int argc, const char * argv[]) {
    getResult();
    return 0;
}
