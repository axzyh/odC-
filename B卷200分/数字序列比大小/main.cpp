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

// 数字序列比大小
// A，B两个人玩一个数字比大小的游戏，在游戏前，两个人会拿到相同长度的两个数字序列，两个数字序列不相同的，且其中的数字是随机的。
//



int getResult(int n, vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int la = 0;
    int ra = n - 1;
    int lb = 0;
    int rb = n - 1;
    int ans = 0;
    while (la <= ra) {
        if (a[ra] > b[rb]) {
            ans += 1;
            ra--;
            rb--;
        } else if (a[ra] < b[rb]) {
            ans -=1;
            la++;
            rb--;
        } else {
            if (a[la] > b[lb]) {
                ans += 1;
                la++;
                lb++;
            } else {
                if (b[rb] > a[la]) {
                    ans -= 1;
                }
                la++;
                rb--;
            }
        }
    }
   
    return ans;
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
   cout << getResult(n, a, b) << endl;
    
    
    return 0;
}
