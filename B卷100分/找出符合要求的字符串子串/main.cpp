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


using namespace std;

// 找出符合要求的字符串子串
// 给定两个字符串，从字符串2中找出字符串1中的所有字符，去重并按照ASCII值从小到大排序。


string getResult(string s1, string s2) {
    set<char> set1;
    for (int i = 0; i < s1.length(); i++) {
        if (set1.count(s1[i]) != 1) {
            set1.insert(s1[i]);
        }
    }
    
    set<char> set2;
    for (int i = 0; i < s2.length(); i++) {
        if (set2.count(s2[i]) != 1) {
            set2.insert(s2[i]);
        }
    }
    set<char> set3;
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(set3, set3.begin()));
    
    string res;
    
    for (char c : set3) {
        res += c;
    }
    return res;
}

int main(int argc, const char * argv[]) {

    string s1,s2;

    getline(cin, s1);
    getline(cin, s2);
    
    
    cout << getResult(s1, s2) << endl;
    
    return 0;
}
