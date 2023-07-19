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

// 第k个排列
// 给定参数n，从1到n会有n个整数：1,2,3,…,n,这n个数字共有n!种排列。

vector<int> fact;

string getResult(vector<int> arr, int n, int k) {
    if (n == 1) {
        return "1";
    }
    int f = fact[n - 1];
    int prefix = arr[(k - 1) / f];
    k %= f;
    k = k== 0? f: k;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == prefix) {
            arr.erase(arr.begin() + i);
            break;
        }
    }
    if (k == 1) {
        string res;
        for (int v: arr) {
            res+= to_string(v);
        }
        return to_string(prefix) + res;
    } else {
        return to_string(prefix) + getResult(arr, n - 1, k);
        
    }
    
}

int main(int argc, const char * argv[]) {
   
    int n, k;
    cin >> n >> k;
    
    fact = vector<int>(n + 1);
    fact[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    
    cout << getResult(arr,n,k) << endl;
    
    return 0;
}
