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
#include <iomanip>


using namespace std;

// 字符串重新排列、字符串重新排序
// 给定一个字符串s，s包括以空格分隔的若干个单词，请对s进行如下处理后输出：

vector<string> getArrStringForS(string str) {
    vector<string> arr;
    string temp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && temp.length() > 0) {
            arr.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }
    if (temp.length() > 0) {
        arr.push_back(temp);
    }
    return arr;
}

bool compare(pair<string, int> a, pair<string, int> b) {
    if (a.second > b.second) {
        return true;
    }
    if (a.second == b.second && a.first.length() < b.first.length()) {
        return true;
    }
    if (a.second == b.second && a.first.length() == b.first.length()) {
        if (a.first < b.first) {
            return true;
        }
    }
    
    return false;
}

string getResult(vector<string> arr) {
    unordered_map<string, int> count;
    for (string &ar : arr) {
        sort(ar.begin(), ar.end());
        count[ar]++;
    }
    
    vector<pair<string, int>>vec(count.begin(),count.end());
    
    sort(vec.begin(), vec.end(), compare);
   
    string res;
    for (auto v: vec) {
        int dd = v.second;
       
        if (res.length() > 0) {
            res += " ";
        }
        while (dd > 1) {
           
            res += v.first;
            res += " ";
            dd--;
        }
        res += v.first;
    }
    
  
    return res;
}



int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    
    vector<string> arr = getArrStringForS(str);

    cout << getResult(arr) << endl;
//
    return 0;
}




