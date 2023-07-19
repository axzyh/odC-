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

// 字符统计及重排
// 给出一个仅包含字母的字符串，不包含空格，统计字符串中各个字母（区分大小写）出现的次数，


bool isLower(char letter) {
    return letter >= 'a' && letter <= 'z';
}

bool isUpper(char letter) {
    return letter >= 'A' && letter <= 'Z';
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second > b.second) {
        return true;
    } else if (a.second == b.second) {
        if (islower(a.first) == islower(b.first) ) {
            return a.first < b.first;
        } else if (isupper(b.first) == true) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
    
   
}


string getResult(string str) {
    unordered_map<char, int> count;
    
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        count[c]++;
    }
    
    vector<pair<char, int>> vec(count.begin(),count.end());
    sort(vec.begin(), vec.end(), compare);
    
    string res;
    for (auto pa : vec) {
        if (res.length() > 0) {
            res += ",";
        }
        res += pa.first;
        res += ":" + to_string(pa.second);
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    cout << getResult(str) << endl;
    
    return 0;
}
