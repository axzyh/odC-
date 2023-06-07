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



// 学生方阵
// 学校组织活动，将学生排成一个矩形方阵。


int getResult(int n,int m, vector<vector<string>>matrix) {
    int ans = 0;
    int offsets[4][2] = {{0,1},{1,0},{1,1},{1,-1}};
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == "M") {
                for (auto offset:offsets) {
                    int oldI = i - offset[0];
                    int oldJ = j - offset[1];
                    if (oldI >= 0 && oldI < n && oldJ >= 0 && oldJ < m && matrix[oldI][oldJ] == "M") {
                        continue;
                    }
                    int len = 1;
                    int newI = i + offset[0];
                    int newJ = j + offset[1];
                    while (newI >= 0 && newI < n && newJ >= 0 && newJ < m && matrix[newI][newJ] == "M") {
                        len++;
                        newI += offset[0];
                        newJ += offset[1];
                    }
                    ans = max(ans, len);
                }
            }
        }
    }
    
    return ans;
}



int main(int argc, const char * argv[]) {
    
    int n,m;
    cin >> n >> m;
    vector<vector<string>>matrix(n,vector<string>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    
   
    
  cout << getResult(n,m,matrix) << endl;
    
    return 0;
}
