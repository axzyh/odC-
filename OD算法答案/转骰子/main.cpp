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

using namespace std;



// 转骰子
// 骰子是一个立方体，每个面一个数字，初始为左1，右2，前3(观察者方向)，后4，上5，下6，用123456表示这个状态，放置在平面上，

vector<string> getArrForString(string s) {
    vector<string> sVec;
    
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            sVec.push_back(tmp);
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        sVec.push_back(tmp);
    }
    
    return sVec;
}


class Dice {
    int left = 1;
    int right = 2;
    int front = 3;
    int back = 4;
    int top = 5;
    int bottom = 6;
public:  void turnL() {
        // 前后不变，上变左，左变下，下变右，右变上
        int temp = right;
        right = bottom;
        bottom = left;
        left = top;
        top = temp;
    }
    void turnR() {
        // 前后不变，上变右，右变下，下变左，左变上
        int temp = left;
        left = bottom;
        bottom = right;
        right = top;
        top = temp;
    }
    void turnF() {
        // 左右不变，上变前，前变下，下变后，后变上
        int temp = back;
        back = bottom;
        bottom = front;
        front = top;
        top = temp;
    }
    void turnB() {
        // 左右不变，上变后，前变上，下变前，后变下
        int temp = bottom;
        bottom = back;
        back = top;
        top = front;
        front = temp;
    }
    void turnA() {
        // 上下不变，前变右，右变后，后变左，左变前
        int temp = front;
        front = left;
        left = back;
        back = right;
        right = temp;
    }
    void turnC() {
        // 上下不变，前变左，左变后，后变右，右变前
        int temp = front;
        front = right;
        right = back;
        back = left;
        left = temp;
    }
    
    void print() {
        string ans = to_string(left) + to_string(right) + to_string(front) + to_string(back) + to_string(top) + to_string(bottom);
        cout << ans << endl;
    }
};


void getResult(vector<string> vec) {
    Dice dice = Dice();
    for (string directive:vec) {
        if (directive == "L") {
            dice.turnL();
            
        }
       else if (directive == "R") {
            dice.turnR();
           
        }
       else if (directive == "F") {
            dice.turnF();
           
        }
       else if (directive == "B") {
            dice.turnB();
           
        }
       else  if (directive == "A") {
            dice.turnA();
           
        }
       else  if (directive == "C") {
            dice.turnC();
           
        }
    }
    dice.print();
   
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    vector<string> vec = getArrForString(str);
    
   getResult(vec) ;
    return 0;
}
