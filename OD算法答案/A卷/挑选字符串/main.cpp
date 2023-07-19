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

// 挑选字符串
// 给定a-z，26个英文字母小写字符串组成的字符串A和B，其中A可能存在重复字母，B不会存在重复字母，现从字符串A中按规则挑选一些字母可以组成字符串B。
/*
 3
 3
 4 5 6
 1 2 3
 4 3 2
 1 5 2
*/

int getResult(string a, string b) {
  
    unordered_map<char, int> idxs;
    for (int i = 0; i < b.length(); i++) {
        char c = b[i];
        idxs[c] = i;
    }
    vector<int> count((int)b.length());
    for (int i = 0; i< a.length(); i++) {
        char c = a[i];
        if (idxs.count(c)) {
            int idx = idxs[c];
            if (idx == 0 || count[idx] < count[idx - 1]) {
                count[idx]++;
            }
        }
    }
    
    return count[count.size() - 1];
}



int main(int argc, const char * argv[]) {
   
    string a,b;
    getline(cin, a);
    getline(cin, b);
  // 确定前面需要的字符有没有，没有不添加，有添加
    
  
    cout << getResult(a,b) << endl;
//
    return 0;
}




