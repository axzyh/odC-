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

// 真正的密码
// 在一行中输入一个字符串数组，如果其中一个字符串的所有以索引0开头的子串在数组中都有，那么这个字符串就是潜在密码，

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


bool compare(string a, string b) {
    if (a.length() > b.length()) {
        return true;
    }
    if (a.length() == b.length()) {
        return a > b;
    }
    
    return false;
}

string getResult(vector<string> arr) {
    set<string> set(arr.begin(),arr.end());
    sort(arr.begin(), arr.end(),compare);
    bool isFlag = true;
    for (int i = 0; i < arr.size(); i++) {
        isFlag = true;
        string str = arr[i];
        for (int j = (int)str.length() - 1; j >= 1; j--) {
            if (!set.count(str.substr(0,j))) {
                isFlag = false;
                break;
            }
        }
        if (isFlag) {
            return str;
        }
    }
    
    return "";
}



int main(int argc, const char * argv[]) {
    string str;
    
    getline(cin, str);
    vector<string> arr = getArrStringForS(str);
  
    cout << getResult(arr) << endl;
//
    return 0;
}




