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



// 信道分配
// 算法工程师小明面对着这样一个问题 ，需要将通信用的信道分配给尽量多的用户:

bool dfs(int cx, int cy,int x,int y, vector<vector<int>> &matrix) {
    if (cx >= x || cy >= y) {
        return false;
    }
    if (matrix[cx][cy] == 1) {
        return false;
    }
    if (matrix[cx][cy] == -1) {
        return false;
    }
    if (matrix[cx][cy] == 2) {
        return true;
    }
    if (matrix[cx][cy] == 0) {
        bool east = dfs(cx + 1, cy, x, y, matrix);
        bool north = dfs(cx, cy + 1, x, y, matrix);
        if (east || north) {
            matrix[cx][cy] = 2;
        } else {
            matrix[cx][cy] = -1;
        }
    }
    return matrix[cx][cy] == 2;
}

vector<int> binaryVector(int n) {
    vector<int> nums;
    while (n > 0) {
        nums.push_back(n % 2);
        n = n >> 1;
    }
    return nums;
}

int getResult(int r,vector<int> nums, int d) {

    vector<int> arr = binaryVector(d);
    
    int count = 0;
    int Nlen = (int)nums.size();
    int DLen = (int)arr.size();
    
    if (Nlen > DLen) {
        for (int i = DLen; i < Nlen; i++) {
            count += nums[i];
        }
    }
    
    while (true) {
        vector<int> D2(DLen);
        for (int i = 0; i < DLen; i++) {
            D2[i] = arr[i];
        }
        for (int i = DLen - 1; i >= 1; i--) {
            if (nums[i] > 0) {
                int diff = nums[i] - D2[i];
                if (diff >= 0) {
                    nums[i] = diff;
                    D2[i] = 0;
                } else {
                    D2[i] = 0;
                    D2[i - 1] += abs(diff) * 2;
                    nums[i] = 0;
                }
            } else {
                D2[i - 1] += D2[i] * 2;
                D2[i] = 0;
            }
        }
        bool flag = false;
        if (nums[0] >= D2[0]) {
            nums[0] -= D2[0];
            count++;
        } else {
            nums[0] -= D2[0];
            D2[0] = 0;
            for (int i = 0; i < DLen; i++) {
                if (nums[i] < 0) {
                    if (i != DLen - 1) {
                        nums[i+1] +=nums[i] >> 1;
                        nums[i] = 0;
                    } else {
                        flag = true;
                    }
                } else {
                    count++;
                    break;
                }
            }
        }
        if (flag) {
            break;
        }
    }
    return count;
}



int main(int argc, const char * argv[]) {

    int r, d;
    cin >> r;
    vector<int> nums(r+1);
    for (int i = 0; i < r + 1; i++) {
        cin >> nums[i];
    }
    cin >> d;

    cout << getResult(r,nums,d) << endl;
    return 0;
}
