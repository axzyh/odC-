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

// 最远足迹
// 某探险队负责对地下洞穴进行探险。探险队成员在进行探险任务时，随身携带的记录器会不定期地记录自身的坐标，但在记录的间隙中也会记录其他数据。探索工作结束后，探险队需要获取到某成员在探险过程中相对于探险队总部的最远的足迹位置。

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

string getResult(string str) {
    int maxFar = 0;
    string ans = "(0,0)";
    int l = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == '(') {
            l = i + 1;
        } else if (c == ')') {
            vector<string> pos = getArrStrForString(str.substr(l,i));
            if (pos[0][0] == '0' || pos[1][0] == '0') {
                continue;
            }
            int x = stoi(pos[0]);
            int y = stoi(pos[1]);
            if (x <= 0 || x >= 1000 || y <= 0 || y >= 1000) {
                continue;
            }
            int far = x * x + y * y;
            if (far > maxFar) {
                maxFar = far;
                ans = "(" + to_string(x) + "," + to_string(y) + ")";
            }
        }
    }
    return ans;

}

int main(int argc, const char * argv[]) {

    string str;
    getline(cin, str);
    
    cout << getResult(str) << endl;
    
    return 0;
}
