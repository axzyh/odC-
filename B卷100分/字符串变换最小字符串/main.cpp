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

// 字符串变换最小字符串
// 给定一个字符串s，最多只能进行一次变换，返回变换后能得到的最小字符串（按照字典序进行比较）。


string getResult(string str) {
    char minSArr[str.length()];
    str.copy(minSArr, str.length());
    sort(minSArr,minSArr + sizeof(minSArr));
    string minS = string(minSArr);
    if (minS == str) {
        return str;
    }
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != minSArr[i]) {
            char tmp = str[i];
            str[i] = minSArr[i];
            
            int swapIndex = (int)str.find_last_of(minSArr[i]);
            str[swapIndex] = tmp;
            break;;
            
        }
    }
    
   
    return str;
}

int main(int argc, const char * argv[]) {
   
    string str;
    string subStr;
    getline(cin, str);
    cout << getResult(str) << endl;
    
    return 0;
}
