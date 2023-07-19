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

// 单词重量
// 每个句子由多个单词组成，句子中的每个单词的长度都可能不一样，我们假设每个单词的长度Ni为该单词的重量，你需要做的就是给出整个句子的平均重量V。

vector<string> getArrStrForString(string str) {
    vector<string> vec;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' '&& tmp.length() > 0) {
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


double getResult(vector<string> words) {
    
    double sum = 0;
    for (string s : words) {
        sum += (int)s.length();
    }
    
    double p = sum/ (int)words.size();
//    cout.setf(ios::fixed);
    cout << fixed<< setprecision(2) << p << endl;
    return p;
}

int main(int argc, const char * argv[]) {

    string str;
    getline(cin, str);
    
    vector<string>words = getArrStrForString(str);
     getResult(words);
    
    return 0;
}
