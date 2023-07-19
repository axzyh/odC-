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

// 密室逃生游戏
// 小强正在参加《密室逃生》游戏，当前关卡要求找到符合给定 密码K（升序的不重复小写字母组成） 的箱子，并给出箱子编号，箱子编号为 1~N 。
/*
abc
s,sdf134 A2c4b
*/

vector<string> getArrStringForS(string str) {
    vector<string> arr;
    string temp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && temp.length() > 0) {
            arr.push_back(temp);
            temp = "";
        } else {
            temp += c;
        }
    }
    if (temp.length() > 0) {
        arr.push_back(temp);
    }
    return arr;
}

bool isCharStr(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int getResult(string key, vector<string> boxs) {
    
    for (int i = 0; i < boxs.size(); i++) {
        string box = boxs[i];
        string tmp;
        for (char c : box) {
            if (isCharStr(c)) {
                tmp += towlower(c);
            }
        }
        sort(tmp.begin(), tmp.end());
        if (key == tmp) {
            return i + 1;
        }
        
    }
   
  
    return -1;
}



int main(int argc, const char * argv[]) {
  
    string key, boxs;
    
    getline(cin, key);
    getline(cin, boxs);
    
    vector<string> arr = getArrStringForS(boxs);

    cout << getResult(key, arr) << endl;
//
    return 0;
}




