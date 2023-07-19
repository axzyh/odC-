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
#include <unordered_set>
#include <regex>

using namespace std;



// 字符串摘要
// 给定一个字符串的摘要算法，请输出给定字符串的摘要值

vector<int> getArrForString(string str) {
    vector<int> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ',' && tmp.length() > 0) {
            arr.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(stoi(tmp));
    }
    return arr;
}

bool compare(pair<char, int> a, pair<char, int> b) {
    if (a.second > b.second) {
        return true;
    } else if (a.second == b.second) {
        if (a.first < b.first) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

string getLowerString(string &s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

string getResult(string str) {
    str = getLowerString(str);
//    vector<int> count(128);
    map<char, int> count;
    
    string res;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            count[c]++;
            res+= c;
        }
    }
    
    str = res + " ";
    vector<pair<char, int>> ans;
    char pre = str[0];
    int repeat = 1;
    count[pre]--;
    for (int i = 1; i < str.length(); i++) {
        char cur = str[i];
        count[cur]--;
        if (cur == pre) {
            repeat++;
        } else {
            ans.push_back(make_pair(pre, repeat > 1 ? repeat : count[pre]));
            pre = cur;
            repeat = 1;
        }
    }
    sort(ans.begin(), ans.end(), compare);
    
    string sj;
    
    for (pair<char, int> an : ans) {
        sj += an.first;
        sj += to_string(an.second);
    }
    
    
    
    
    return sj;
}



int main(int argc, const char * argv[]) {
  
    string str;
    getline(cin, str);
   cout << getResult(str) << endl;
   
    
    return 0;
}
