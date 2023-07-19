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

// 寻找相同子串
// 给你两个字符串t和p，要求从t中找到一个和p相同的连续子串，并输出该子串第一个字符的下标。


string getResult(string str, string subStr) {
    if (subStr.length() > str.length()) {
        return "No";
    }
    
    int pos = (int)str.find(subStr);
    if (pos == -1) {
        return "No";
    }
    int res = pos + 1;
    return to_string(res);
    
}

int main(int argc, const char * argv[]) {
   
    string str;
    string subStr;
    getline(cin, str);
    getline(cin, subStr);
   
    
    cout << getResult(str,subStr) << endl;
    
    return 0;
}
