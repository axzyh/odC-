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

// 数列描述
// 有一个数列a[N] (N=60)，从a[0]开始，每一项都是一个数字。数列中a[n+1]都是a[n]的描述。其中a[0]=1。规则如下：

string describe(string seq) {
    string res;
    int count = 1;
    char val = seq[0];
    for (int i = 1; i < seq.length(); i++) {
        if (seq[i] == seq[i - 1]) {
            count++;
        } else {
            res += to_string(count) + val;
            count = 1;
            val = seq[i];
        }
    }
    res += to_string(count) + val;
    return res;
}

string getResult(int n) {
    string base = "1";
    for (int i = 1; i <= n; i++) {
        base = describe(base);
    }
   
    return base;
    
}

int main(int argc, const char * argv[]) {
   
    int n;
    cin >> n;
    
    cout << getResult(n) << endl;
    
    return 0;
}
