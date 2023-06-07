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

// 二进制差异数
// 对于任意两个正整数A和B，定义它们之间的差异值和相似值差异值：
string getTwoString(int a) {
    string temp;
    while (a > 0) {
        temp = to_string(a % 2) + temp;
        a = a / 2;
    }
    return temp;
}

int getResult(vector<int>vec) {
  
    vector<int>highBit(60);

    for (int i : vec) {
        string bin = getTwoString(i);
        int len = (int)bin.length();
        
        if (bin == "0") {
            highBit[0]++;
        } else {
            highBit[len]++;
        }
    }
    int res = 0;
    for (int i = 0; i < highBit.size(); i++) {
        for (int j = i + 1; j < highBit.size(); j++) {
            res += highBit[i] *highBit[j];
        }
    }
    
    
    return res;
}

void test26() {
   
    
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int>vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    cout << getResult(vec) << endl;
    
    return 0;
}
