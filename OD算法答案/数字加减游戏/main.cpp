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

// 数字加减游戏
// 小明在玩一个数字加减游戏，只使用加法或者减法，将一个数字s变成数字t。
//  每个回合，小明可以用当前的数字加上或减去一个数字。

int getResult(int s, int t, int a, int b) {
    int x = 0;
    int diff = t - s;
    while (true) {
        if ((diff - a*x) % b == 0 || (diff + a*x) % b == 0) {
            return abs(x);
        }
        x++;
    }
}
int main(int argc, const char * argv[]) {
    
    int s,t,a,b;
    cin >> s >> t >> a >> b;
    cout << getResult(s, t, a, b) << endl;
    
    return 0;
}
