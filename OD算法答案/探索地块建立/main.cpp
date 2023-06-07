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

using namespace std;

// 探索地块建立
//给一块n*m的地块，相当于n*m的二维数组，每个元素的值表示这个小地块的发电量；

int getResult(vector<vector<int>>vec,int n,int m, int c,int k){
    
    int ans = 0;
    for (int i = 0; i <= n - c; i ++) {
        for (int j = 0; j <= m - c; j++) {
            int sum = 0;
            
            for (int d = i;d < i + c; d++) {
                for (int e = j ; e <j + c; e++) {
                    sum += vec[d][e];
                }
            }
            if (sum >= k) {
                ans++;
            }
        }
    }
    return ans;
    
}

int main(int argc, const char * argv[]) {
    int n,m,c,k;
    cin >> n >> m >> c >> k;
    vector<vector<int>>vec(n,vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }
    
    cout << getResult(vec, n, m, c, k) << endl;
    
    return 0;
}
