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

// 冗余覆盖
// 给定两个字符串s1和s2和正整数K，其中s1长度为n1，s2长度为n2，在s2中选一个子串，满足:
/*
 ab
 aabcd
 1
*/

int getResult(string s1, string s2, int k) {
  
    int n1 = (int)s1.length();
    int n2 = (int)s2.length();
    if (n2 < n1 + k) {
        return -1;
    }
    
    vector<int> count(128);
    
    for (int i = 0; i < n1; i++) {
        int c = s1[i];
        count[c]++;
    }
    
    int total = n1;
    int maxI = n2 - n1 - k;
    int len = n1 + k;
    for (int j = 0; j < len; j++) {
        int c = s2[j];
        if (count[c]-- > 0) {
            total--;
        }
        
        if (total == 0) {
            return 0;
        }
    }
    
    for (int i = 1; i <= maxI; i++) {
        int remove = s2[i - 1];
        int add = s2[i - 1 + len];
        if (count[remove]++>= 0) {
            total++;
        }
        if (count[add] -- > 0) {
            total--;
        }
        if (total == 0) {
            return i;
        }
    }
    
    
    return -1;
}



int main(int argc, const char * argv[]) {
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    int k;
    cin >> k;
    cout << getResult(s1,s2,k) << endl;
//
    return 0;
}




