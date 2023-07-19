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

// 数组组成的最小数字
// 给定一个整型数组，请从该数组中选择3个元素组成最小数字并输出

vector<string> getArrStrForString(string str) {
    vector<string> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ','&& tmp.length() > 0) {
            vec.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(tmp);
    }
    return vec;
}

bool compare(string a, string b) {
    if (a.length() < b.length()) {
        return true;
    }  else if (a.length() == b.length()) {
        if (stoi(a) <stoi(b)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
    
}

bool compare2(string a, string b) {
    if (a + b < b + a) {
        return true;
    } else {
        return false;
    }
}


string getResult(vector<string> strs) {
    
    sort(strs.begin(), strs.end(), compare);
    vector<string> tmp(strs.begin(), strs.begin() + 3);
    sort(tmp.begin(), tmp.end(), compare2);
    
    string res;
    for (string tm: tmp) {
        res += tm;
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    vector<string> strs = getArrStrForString(str);
  cout << getResult(strs) << endl;
    
    return 0;
}
