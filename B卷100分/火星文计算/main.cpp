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

// 火星文计算
// 已知火星人使用的运算符为#、$，其与地球人的等价公式如下：

bool isNumber(char c) {
    return c >= '0' && c <= '9';
}

void getRes(int pos, string &str, bool isFlag) {
    int l = pos - 1;
    int r = pos + 1;
    string tmp = str;
    
    string lStr;
    while (l >=0 && isnumber(str[l])) {
        lStr = str[l] +lStr;
        tmp.replace(l, 1, " ");
        l--;
    }
    
    string rStr;
    while (r < str.length() && isnumber(str[r])) {
        rStr += str[r];
        tmp.replace(r, 1, " ");
        r++;
        
    }
    
    int x = stoi(lStr);
    int y = stoi(rStr);
    int sum = 0;
    if (isFlag) {
        sum = 3 * x + y + 2;
    } else {
      sum = 2 * x + 3 * y + 4;
    }
//    tmp.insert(l+1, to_string(sum));
//    tmp.erase(tmp.begin() + l, tmp.begin() + r -l);
//    replace(tmp.begin(), tmp.end(), ' ', '');
    tmp.replace(l + 1, r - l - 1, to_string(sum));
    str = tmp;
    
//    return sum;
}


int getResult(string str) {
   
    while (true) {
        int pos = (int)str.find("$");
        if (pos == -1) {
            break;
        }
        getRes(pos, str, true);
        
    }
    
    while (true) {
        int pos = (int)str.find("#");
        if (pos == -1) {
            break;
        }
        getRes(pos, str, false);
        
    }
    
    
    return stoi(str);
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    
    cout << getResult(str) << endl;
    
    return 0;
}
