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
#include <regex>

using namespace std;



// 增强的strstr
// C 语言有一个库函数： char *strstr(const char *haystack, const char *needle) ，实现在字符串 haystack 中查找第一次出现字符串 needle 的位置，如果未找到则返回 null。

int getResult(string src, string tar) {
    regex regex(tar);
    smatch matcherResult;
//    regex_search(<#_BidirectionalIterator __first#>, <#_BidirectionalIterator __last#>, <#match_results<_BidirectionalIterator, _Allocator> &__m#>, <#const basic_regex<_CharT, _Traits> &__e#>)
    if (regex_search(src, matcherResult, regex)) {
        int pos = (int)src.find(tar[0]);
        return pos;
    } else {
        return -1;
    }
}

int main(int argc, const char * argv[]) {
  
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    
   
    
    cout << getResult(s1,s2) << endl;
   
    
    return 0;
}
