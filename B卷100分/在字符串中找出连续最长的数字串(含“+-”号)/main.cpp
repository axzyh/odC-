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

// 在字符串中找出连续最长的数字串(含“+-”号)
// 请在一个字符串中找出连续最长的数字串，并返回这个数字串。

string getResult(string str) {
    regex matcher("([+-]?\\d+\\.?\\d+)");
    
    string ans = "";
    int maxlen = 0;
    auto words_begin = sregex_iterator(str.begin(),str.end(),matcher);
    auto words_end = sregex_iterator();
    for (sregex_iterator i = words_begin; i != words_end; i++) {
        smatch mathcResult = *i;
        string tmp = mathcResult.str(0);
        if (tmp.length() >= maxlen) {
            ans = tmp;
        }
    }

    
    return ans;
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin,str);
    cout << getResult(str) << endl;
    
    return 0;
}
