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

// 求最小步数
// 求从坐标零点到坐标点n的最小步数，一次只能沿横坐标轴向左或向右移动 2 或 3。


int getResult(int n) {

    if (n == 1) {
        return 2;
    }
    if (n == 2 || n == 3) {
        return 1;
    }
    

    return (n - 4) / 3  + 2;
    
}

int main(int argc, const char * argv[]) {
   
    int n;
    cin >> n;
    
    cout << getResult(n) << endl;
    return 0;
}
