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

// 完美走位
// 在第一人称射击游戏中，玩家通过键盘的A、S、D、W四个按键控制游戏人物分别向左、向后、向右、向前进行移动，从而完成走位。

int getResult(string str) {
    unordered_map<char, int> count;
    for (char c : str) {
        count[c]++;
    }
    int avg = (int)str.length() / 4;
    int total = 0;
    
    bool flag = true;
    
    for (auto key: count) {
        if (key.second > avg) {
            flag = false;
            count[key.first] -= avg;
            total += count[key.first];
        }
    }
   
    if (flag) {
        return 0;
    }
    
    int i = 0;
    int j = 0;
    int minLen = (int)str.length() - 1;
    while (j < str.length()) {
        char jc = str[j];
        if (count[jc] >0) {
            total--;
        }
        count[jc] -=1;
        while (total == 0) {
            minLen = min(minLen, j - i + 1);
            char ic = str[i];
            if (count[ic] >= 0) {
                total++;
            }
            count[ic]++;
            i++;
        }
        j++;
    }
    
    
  
    return minLen;
}



int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);

    cout << getResult(str) << endl;
//
    return 0;
}




