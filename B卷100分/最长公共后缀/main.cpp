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

using namespace std;



// 最长公共后缀
// 编写一个函数来查找字符串数组中的最长公共后缀；

vector<string> getNumsArrForString(string str) {
    vector<string> arr;
    string tmp;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (c == '"'  && tmp.length() > 0) {
            arr.push_back(tmp);
            tmp = "";
        } else if (c == '"' || c == '[' || c == ']' || c == ',') {
            continue;
        }
        
        else {
            tmp += c;
        }
    }
    
    return arr;
}

char charAt(string s, int negativeIndex) {
    return s[s.length() + negativeIndex];
}

string getLCS(string s1, string s2) {
    if (charAt(s1, -1) != charAt(s2, -1)) {
        return "";
    }
    int maxLen = min(s1.length(), s2.length());
    for (int i = -2; i >= -maxLen; i--) {
        if (charAt(s1, i) != charAt(s2, i)) {
            return s1.substr(s1.length() + i + 1, s1.length());
        }
    }
    return s1.substr(s1.length() - maxLen, s1.length());
}


string getResult(vector<string> arr) {
    string suffix = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        suffix = getLCS(suffix, arr[i]);
        if (suffix == "") {
            return "@Zero";
        }
    }
  
    return suffix;
}

int main(int argc, const char * argv[]) {
  
    string str;
    getline(cin, str);
    
    vector<string> nums = getNumsArrForString(str);
    
    cout << getResult(nums) << endl;
   
    
    return 0;
}
