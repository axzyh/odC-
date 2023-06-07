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



// 矩阵稀疏扫描
//如果矩阵中的许多系数都为零，那么该矩阵就是稀疏的。对稀疏现象有兴趣是因为它的开发可以带来巨大的计算节省，并且在许多大的实践中都会出现矩阵稀疏的问题。
void getResult() {
    int m, n,num;
    cin >> m >> n;
    vector<int> rowZeroCount(m);
    vector<int> ColZeroCount(n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            if (num == 0) {
                rowZeroCount[i]++;
                ColZeroCount[j]++;
            }
        }
    }
    
    int rowMid = m / 2;
    int colMid = n / 2;
    
    int rowCount = 0;
    int colCount = 0;
    
    for (int i = 0; i < rowZeroCount.size(); i++) {
        if (rowZeroCount[i] >= colMid) {
            rowCount++;
        }
    }
    for (int i = 0; i < ColZeroCount.size(); i++) {
        if (ColZeroCount[i] >= rowMid) {
            colCount++;
        }
    }
    cout << rowCount <<" " << colCount << endl;
}

int main(int argc, const char * argv[]) {
    getResult();
    
    return 0;
}
