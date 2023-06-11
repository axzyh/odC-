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



// 服务失效判断
// 回文串的定义：正读和反读都一样的字符串。

map<string, int> first;

vector<vector<string>> getArrForString(string s){
    vector<vector<string>> vec;
    string tmp;
    vector<string> tmpVec;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            tmpVec.push_back(tmp);
            vec.push_back(tmpVec);
            tmp = "";
            tmpVec.clear();
        } else if (s[i] == '-') {
            tmpVec.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        tmpVec.push_back(tmp);
        vec.push_back(tmpVec);
    }
    
    return vec;;
}

vector<string> getResArrForString(string s){
    vector<string> vec;
    string tmp;
    
    for (int i = 0; i < s.length(); i++) {
         if (s[i] == ',') {
             vec.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(tmp);
    }
    return vec;;
}



void removeMap(map<string, set<string>> &next, string s) {
    if (next.count(s)) {
        set<string> need_remove = next[s];
//        rem
        next.erase(s);
        for (string ss : need_remove) {
            removeMap(next, ss);
        }
    }
}

bool compare(string a, string b) {
    int f = first[a];
    int s = first[b];
    if (f < s) {
        return true;
    } else {
        return false;
    }
}


string getResult(vector<vector<string>>relations, vector<string> breakdowns) {
    map<string, set<string>> next;
//    map<string, int> first;
    int i = 0;
    for (auto relation: relations) {
        string c = relation[0];
        string f = relation[1];
        next[f].insert(c);
        first[c] = i++;
        first[f] = i++;
    }
    for (string s: breakdowns) {
        removeMap(next, s);
    }
    
    vector<string> ans;
    for (auto key: next) {
        ans.push_back(key.first);
    }
    if (ans.size() == 0) {
        return ",";
    }
    sort(ans.begin(), ans.end(),compare);
    string str;
    for (string an : ans) {
        if (str.length() > 0) {
            str += ",";
        }
        str += an;
    }
    
   
    return str;
}



int main(int argc, const char * argv[]) {

    string str,s1;
    
    getline(cin, str);
    getline(cin, s1);
    
    vector<vector<string>> vec = getArrForString(str);
    vector<string> sVec = getResArrForString(s1);

    cout << getResult(vec,sVec) << endl;
    return 0;
}
