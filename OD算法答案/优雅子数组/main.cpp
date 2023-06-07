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



// 优雅子数组
// 如果一个数组中出现次数最多的元素出现大于等于K次，被称为 k-优雅数组 ，k也可以被称为优雅阈值。
// 现在给N个站点编号0、1、…n-1，用s[i][j]表示i-j是否可达，s[i][j]=1表示i-j可达，s[i][j]=0表示i-j不可达。

int getResult(vector<int>vec, int n, int k) {
    int ans = 0;
    int l = 0;
    int r = 0;
    map<int, int> map;
    while (l < n && r < n) {
        int c = vec[r];
        map[c]++;
        if (map[c] >= k) {
            ans += n - r;
            map[vec[l]]--;
            l++;
            map[c]--;
            r--;
        }
        r++;
    }
    return ans;
}

void test2() {
   
}

int main(int argc, const char * argv[]) {
    
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << getResult(arr, n, k);
    
    return 0;
}
