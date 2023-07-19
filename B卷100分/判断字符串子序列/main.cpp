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

// 判断字符串子序列
// 给定字符串 target和 source，判断 target是否为 source 的子序列

int getResult(string target, string source) {
    int cur = (int)target.length() - 1;
    for (int i = (int)source.length() - 1; i >= 0; i--) {
        if (source[i] == target[cur]) {
            cur--;
            if (cur < 0) {
                return i;
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {

    string target, source;
    getline(cin, target);
    getline(cin, source);
   
    cout << getResult(target, source) << endl;
    
    return 0;
}
