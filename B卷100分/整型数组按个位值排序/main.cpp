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

// 整型数组按个位值排序
// 给定一个非空数组（列表），其元素数据类型为整型，请按照数组元素十进制最低位从小到大进行排序，十进制最低位相同的元素，相对位置保持不变。

vector<string> getArrStrForString(string str) {
    vector<string> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ','&& tmp.length() > 0) {
            vec.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        vec.push_back(tmp);
    }
    return vec;
}

bool compare(string a, string b) {
    char c = a.back();
    char d = b.back();
    if (c < d) {
        return true;
    } else if (c == d) {
        return false;
    } else {
        return false;
    }
   
}


string getResult(vector<string> strs) {
    
    stable_sort(strs.begin(), strs.end(), compare);
    string res;
    for (string tm: strs) {
        if (res.length() > 0) {
            res += ",";
        }
        res += tm;
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    vector<string> strs = getArrStrForString(str);
   cout << getResult(strs) << endl;
    
    return 0;
}
