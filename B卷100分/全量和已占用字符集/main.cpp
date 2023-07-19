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

// 全量和已占用字符集
// 给定两个字符集合，一个是全量字符集，一个是已占用字符集，已占用字符集中的字符不能再使用。

vector<pair<string, string>> getArrStrForString(string str) {
    vector<pair<string, string>> vec;
    string tmp;
    string frist;
    string second;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ','&& tmp.length() > 0) {
            second = tmp;
            vec.push_back(make_pair(frist, second));
            tmp = "";
        } else if (str[i] == ':' && tmp.length() > 0) {
            frist = tmp;
            tmp = "";
        }
        
        else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        second = tmp;
        vec.push_back(make_pair(frist, second));
    }
    return vec;
}

string getResult(string str) {
  
    int pos = (int)str.find("@");
    string tmp1 = str.substr(0,pos);
    string tmp2 = str.substr(pos + 1, (int)str.length() - 1);
    
    vector<pair<string, string>> all = getArrStrForString(tmp1);
    vector<pair<string, string>> used = getArrStrForString(tmp2);
    
    unordered_map<string, int> allMap;
    for (auto a : all) {
        allMap[a.first] = stoi(a.second);
    }
    
    unordered_map<string, int> usedMap;
    for (auto a : used) {
        usedMap[a.first] = stoi(a.second);
    }
    
    for (auto i : usedMap) {
        if (allMap.count(i.first)) {
            int remain = allMap[i.first] - i.second;
            if (remain > 0) {
                allMap[i.first] = remain;
            } else {
                allMap.erase(i.first);
            }
        }
    }
    
    string res;
    for (auto i: allMap) {
        if (res.length() > 0) {
            res = "," + res;
        }
        res = i.first + ":" + to_string(i.second) + res;
    }
    
    
    return res;
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin,str);
    cout << getResult(str) << endl;
    
    return 0;
}
