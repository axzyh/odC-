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



// 需要打开多少监控器
// 某长方形停车场，每个车位上方都有对应监控器，当且仅当在当前车位或者前后左右四个方向任意一个车位范围停车时，监控器才需要打开；
int getResult(vector<vector<int>>vec) {
   
    
    int count = 0;
    int offsets[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    
    for (int i = 0; i < vec.size(); i++) {
        
        for (int j = 0; j < vec[i].size(); j++) {
            if (vec[i][j] == 1) {
                count++;
                continue;
            }
            for (auto offset:offsets) {
                int x = offset[0];
                int y = offset[1];
                int newX = x + i;
                int newY = y + j;
                
                if (newX >= 0 && newX < vec.size() && newY >= 0 && newY < vec[i].size() && vec[newX][newY] == 1) {
                    count++;
                    break;
                }
            }
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    int a,b, c;
    cin >> a >> b;
    vector<vector<int>> vec;
    for (int i = 0; i < a; i++) {
        vector<int> vec1;
        for (int j = 0; j < b; j++) {
            cin >> c;
            vec1.push_back(c);
        }
        vec.push_back(vec1);
    }
    
    cout << getResult(vec) << endl;
    
    return 0;
}
