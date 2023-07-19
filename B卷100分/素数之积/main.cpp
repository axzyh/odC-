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

// 素数之积
// RSA加密算法在网络安全世界中无处不在，它利用了极大整数因数分解的困难度，数据越大，安全系数越高，给定一个 32 位正整数，请对其进行因数分解，找出是哪两个素数的乘积。

bool isPrime(int n) {
    if (n <= 3) {
        return n >= 1;
    }
    
    if (n % 6 != 1 && (n % 6 != 5) ) {
        return false;
    }
    
    for (int i = 5; i < sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    
    return true;
}


string getResult(int n) {
    if (isPrime(n)) {
        return "-1 -1";
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            int j = n / i;
            if (isPrime(i) && isPrime(j)) {
                return i < j ? to_string(i) + " " + to_string(j) : to_string(j) + " " + to_string(i);
            } else {
                break;
            }
        }
    }
    return "-1 -1";
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin >> n;
  cout << getResult(n) << endl;
    
    return 0;
}
