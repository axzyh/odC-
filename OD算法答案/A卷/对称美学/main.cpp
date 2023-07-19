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
#include <iomanip>


using namespace std;

// 对称美学
// 对称就是最大的美学，现有一道关于对称字符串的美学。已知：
/*
 1
 64 73709551616
*/


string getNK(double n, double k) {
    if (n == 1) {
        return "red";
    }
    if (n == 2) {
        if (k == 0) {
            return "blue";
        } else {
            return "red";
        }
    }
    
    double half = pow(2, n - 2);
    if (k > half) {
        return getNK(n - 1, k - half);
    } else {
        if ((getNK(n - 1, k)).find("red") != string::npos ) {
            return "bule";
        } else {
            return "red";
        }
    }
    
    
}


void getResult(vector<vector<double>> arr) {
    for (vector<double> nk: arr) {
        cout << getNK(nk[0], nk[1]) << endl;
    }

}



int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    
    vector<vector<double>> arr(n,vector<double>(2));
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }
  
    getResult(arr);
//
    return 0;
}




