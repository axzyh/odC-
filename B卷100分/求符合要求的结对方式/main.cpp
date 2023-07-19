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

// 求符合要求的结对方式
// 用一个数组A代表程序员的工作能力，公司想通过结对编程的方式提高员工的能力，假设结对后的能力为两个员工的能力之和，求一共有多少种结对方式使结对后能力为N。

int getResult(int n,vector<int> arr) {
    
    sort(arr.begin(), arr.end());
    int ans = 0 ;
    for (int i = 0; i < arr.size(); i++) {
       
        for (int j = (int)arr.size() - 1; j > i; j--) {
            int sum = arr[i] + arr[j];
            if (sum == n) {
                ans++;
            } else if (sum < n) {
                break;
            }
        }
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {

    int total,n;
    cin >> total;
    vector<int>arr(total);
    for (int i = 0; i < total; i++) {
        cin >> arr[i];
    }
    cin >> n;
    
    cout << getResult(n,arr) << endl;
    
    return 0;
}
