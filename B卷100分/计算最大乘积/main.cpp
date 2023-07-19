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

// 计算最大乘积
// 给定一个元素类型为小写字符串的数组，请计算两个没有相同字符的元素长度乘积的最大值，

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

int getResult(vector<string> sArr) {
  
    vector<set<char>> list;
    for (string s : sArr) {
        set<char> set;
        vector<char> cArr(s.begin(),s.end());
        for (char c : cArr) {
            set.insert(c);
        }
        list.push_back(set);
    }
    int ans = 0;
    for (int i = 0; i < list.size(); i++) {
        set<char> a = list[i];
        for (int j = i + 1; j < list.size(); j++) {
            set<char> b = list[j];
            set<char> result;
            set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(result, result.begin()));
            if (result.size() == 0) {
                ans = max(ans, (int)sArr[i].length() * (int)sArr[j].length());
            }
        }
    }
    return ans;
    
}

int main(int argc, const char * argv[]) {
   
    string s;
    getline(cin, s);
    vector<string> arr = getArrStrForString(s);
    
    cout << getResult(arr) << endl;
    
    return 0;
}
