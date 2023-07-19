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

// 非严格递增连续数字序列
// 输入一个字符串仅包含大小写字母和数字，求字符串中包含的最长的非严格递增连续数字序列的长度，（比如12234属于非严格递增连续数字序列）。

int getResult(string str) {
    
    int l = 0;
    int r = 0;
    int maxLen = 0;
    while (r < str.length()) {
        char c = str[r];
        if (c >= '0' && c <= '9') {
            if (l != r) {
                if (c >= str[r-1]) {
                    maxLen = max(maxLen, r - l + 1);
                } else {
                    maxLen = max(maxLen, r - l);
                    l = r;
                }
                r++;
            } else {
                maxLen = max(maxLen, 1);
                r++;
            }
        } else {
            maxLen = max(maxLen, r - l);
            r++;
            l = r;
        }
    }
    return maxLen;

}

int main(int argc, const char * argv[]) {

    string str;
    getline(cin, str);
    cout << getResult(str) << endl;
    
    return 0;
}
