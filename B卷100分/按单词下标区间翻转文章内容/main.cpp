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

// 按单词下标区间翻转文章内容
// 给定一段英文文章片段，由若干单词组成，单词间以空格间隔，单词下标从0开始。

bool isCharStr(char c) {
    
    return (c >= 'a' && c <= 'z') || ( c >= 'A' && c <= 'Z');
}

vector<string> getArrStrForString(string str) {
    vector<string> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' && tmp.length() > 0) {
            arr.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(tmp);
    }
    return arr;
}


string getResult(string str,int startIndex, int endIndex) {
   
    vector<string> sArr = getArrStrForString(str);
    startIndex = min(max(0, startIndex), (int)sArr.size() - 1);
    endIndex = min(max(0, endIndex), (int)sArr.size() - 1);
    if (startIndex > endIndex) {
        return str;
    }
    
    int l = startIndex;
    int r = endIndex;
    while (l < r) {
        string tmp = sArr[l];
        sArr[l] = sArr[r];
        sArr[r] = tmp;
        l++;
        r--;
    }
    
    string ans;
    for (string s: sArr) {
        if (ans.length() > 0) {
            ans += " ";
        }
        ans += s;
    }
    return ans;
}

int main(int argc, const char * argv[]) {

    string str;
    getline(cin, str);
    int startIndex;
    int endIndex;
    cin >> startIndex >> endIndex;
    
   
    cout << getResult(str, startIndex, endIndex) << endl;
    
    return 0;
}
