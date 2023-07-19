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

// 单词接龙
// 单词接龙的规则是：


bool compare(string a, string b) {
    if (a.length() > b.length()) {
        return true;
    } else if (a.length() == b.length()) {
        return b > a;
    } else {
        return false;
    }
}

string getResult(int n, int m, vector<string>arr) {
    string frist = arr[n];
    arr.erase(arr.begin() + n);
    
    unordered_map<char, vector<string>> map;
    
    for (string str : arr) {
        char c = str[0];
        map[c].push_back(str);
    }
    
    for (auto &c: map) {
        vector<string> vec = c.second;
        sort(vec.begin(), vec.end(),compare);
        c.second = vec;
    }
    
    string res = frist;
    char c = frist[frist.length() - 1];
    while (map.count(c)) {
        vector<string> vec = map[c];
        frist = vec.front();
        res += frist;
        vec.erase(vec.begin() + 0);
        map[c] = vec;
        c = frist[frist.length() - 1];
        
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n >> m;
    string str;

    vector<string> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    
    
    cout << getResult(n, m, arr) << endl;
    
    return 0;
}
