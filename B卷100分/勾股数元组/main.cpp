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

// 勾股数元组
// 如果3个正整数(a,b,c)满足a^2 + b^2 = c^2的关系，则称(a,b,c)为勾股数（著名的勾三股四弦五），

bool isRelativePrime(int x, int y) {
    while (y > 0) {
        int mod = x % y;
        x = y;
        y = mod;
    }
    return x == 1;
}

bool compare(vector<int> a, vector<int> b) {
    if (a[0] != b[0]) {
        if (a[0] < b[0]) {
            return true;
        }
    } else {
        if (a[1] != b[1]) {
            if (a[1] < b[1]) {
                return true;
            }
        } else {
            if (a[2] < b[2]) {
                return true;
            }
        }
    }
    return false;
}

// 最优解法，勾股定理求解
void getResult2(int n, int m) {
    vector<vector<int>> ans;
    int k = ceil(sqrt(m));
    
    for (int y = 1; y < k; y++) {
        for (int x = y + 1; x < k; x++) {
            if (isRelativePrime(x, y) && (x + y) % 2 == 1) {
                int a = x * x - y * y;
                int b = 2 * x * y;
                int c = x * x + y * y;
                
                if (a >= n && b >= n && c <= m) {
                    if (a < b) {
                        ans.push_back({a,b,c});
                    } else {
                        ans.push_back({b,a, c});
                    }
                }
            }
        }
    }
    
    if (ans.size() > 0) {
        sort(ans.begin(), ans.end(), compare);
        for (vector<int> res: ans) {
            cout << to_string(res[0]) + " " + to_string(res[1]) + " " + to_string(res[2]) << endl;
        }
    } else {
        cout << "NA" << endl;
    }
}


void getResult(int n,int m) {
    vector<int> arr;
    for (int i = n; i <= m; i++) {
        arr.push_back(i * i);
    }
    set<int> set(arr.begin(),arr.end());
    vector<vector<int>> res;
    
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            int sum = arr[i] + arr[j];
            
            if (set.count(sum)) {
                res.push_back({(int)sqrt(arr[i]),(int)sqrt(arr[j]),(int)sqrt(sum)});
            }
        }
    }
    
    vector<vector<int>> collect;
    for (int i = 0; i < res.size(); i++) {
        vector<int> ans = res[i];
        for (int i = 0; i < ans.size(); i++) {
            if (isRelativePrime(ans[0], ans[1]) || isRelativePrime(ans[0], ans[2]) || isRelativePrime(ans[1], ans[2])) {
                collect.push_back(ans);
                break;
            }
        }
    }
    
    if (collect.size() == 0) {
        cout << "NA" << endl;
    } else {
        for (vector<int> res: collect) {
            cout << to_string(res[0]) + " " + to_string(res[1]) + " " + to_string(res[2]) << endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int n,m;
    cin >> n >> m;
    getResult2(n,m);
    
    return 0;
}
