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

// 模拟商场优惠打折
// 模拟商场优惠打折，有三种优惠券可以用，满减券、打折券和无门槛券。
/*
3 2 5
3
100
200
400
*/


vector<int> M(int price, int m) {
    while (price >= 100 && m > 0) {
        price -= price/100 * 10;
        m--;
    }
    return {price,m};
}
vector<int> N(int price, int n) {
    if(n >= 1) {
        price = (int) floor(price * 0.92);
        n--;
    }
    return {price,n};
}

vector<int> K(int price, int k) {
    while (price > 0 && k > 0) {
        price -= 5;
        price = max(price, 0);
        k--;
    }
    return {price,k};
}

bool compare(vector<int> a, vector<int> b) {
    if (a[0] < b[0]) {
        return true;
    }
    if (a[0] == b[0] && a[1] < b[1]) {
        return true;
    }
    return false;
}

void getResult(int m,int n, int k, int x, vector<int> arr) {
    for (int i = 0; i < x; i++) {
        vector<vector<int>> ans(4,vector<int>(2));
        int price = arr[i];
        vector<int> resM = M(price,m);
        vector<int> resN = N(price, n);
        vector<int> resMN_N = N(resM[0], m);
        ans[0] = {resMN_N[0], m + n - resM[1] - resMN_N[1]};
        
        vector<int> resNM_M=M(resN[0], n);
        ans[1] = {resNM_M[0], n + m - resN[1] - resNM_M[1]};
        
        //MK
        vector<int> resMK_K = K(resM[0], k);
        ans[2] = {resMK_K[0], m + k - resMK_K[1] - resM[1]};
        
        vector<int> resNK_K = K(resN[0], k);
        ans[3] = {resNK_K[0], n + k - resNK_K[1] - resN[1]};
        
        stable_sort(ans.begin(), ans.end());
        cout << ans[0][0] << " " << ans[0][1] << endl;
    }
   
}



int main(int argc, const char * argv[]) {
    int m,n,k,x;
    cin >> m >> n >> k >> x;
    
    vector<int> arr(x);
    for (int i = 0; i < x; i++) {
        cin >> arr[i];
    }
  
    getResult(m,n,k,x,arr);
//
    return 0;
}




