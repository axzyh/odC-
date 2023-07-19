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

// 工号不够用了怎么办？
// 3020年，空间通信集团的员工人数突破20亿人，即将遇到现有工号不够用的窘境。

int main(int argc, const char * argv[]) {
    int x, y;
    cin >> x >> y;
    max(1, 2);
    long tmp = ceil(log10(x / pow(26,y)));
    long dd = 1;
    long ans = max(dd, tmp);
    cout << ans << endl;
    
    return 0;
}
