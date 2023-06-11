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

// 计算疫情扩散时间
// 在一个地图中(地图由n*n个区域组成），有部分区域被感染病菌。 感染区域每天都会把周围（上下左右）的4个区域感染。 请根据给定的地图计算，多少天以后，全部区域都会被感染。 如果初始地图上所有区域全部都被感染，或者没有被感染区域，返回-1

vector<int> getArrNumsForString(string s) {
    vector<int> nums;
    string tmp;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',' && tmp.length() > 0) {
            nums.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        nums.push_back(stoi(tmp));
    }
    
    return nums;
}


int getResult( vector<int> nums) {
    int n = sqrt(nums.size());
    
    vector<vector<int>> matrix(n,vector<int>(n));
    
    vector<vector<int>>q;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = nums[i * n + j];
            if (matrix[i][j] == 1) {
                q.push_back({i,j});
            }
        }
    }
    if (q.size() == 0 || q.size() == nums.size()) {
        return -1;
    }
    
    int healthy = (int)nums.size() - (int)q.size();
    
    int offsets[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int day = 0;
    while (q.size() > 0 && healthy > 0) {
        vector<vector<int>> newQue;
        for (vector<int> pos:q) {
            int x = pos[0], y = pos[1];
            for (auto offset : offsets) {
                int newX = x + offset[0];
                int newY = y + offset[1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && matrix[newX][newY] == 0) {
                    matrix[newX][newY] = 1;
                    healthy--;
                    newQue.push_back({newX,newY});
                }
            }
        }
        day++;
        q = newQue;
    }
    

    return day;
    
}

int main(int argc, const char * argv[]) {
   
    string str;
    getline(cin, str);
    
    cout << getResult(getArrNumsForString(str)) << endl;
    return 0;
}
