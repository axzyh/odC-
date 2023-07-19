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

// 最大利润
// 商人经营一家店铺，有number种商品，
/*
 3
 3
 4 5 6
 1 2 3
 4 3 2
 1 5 2
*/

int getResult(int number, int days, vector<int> maxCount, vector<vector<int>> prices) {
  
    int ans = 0;
    for (int i = 0; i < number; i++) {
        vector<int> price = prices[i];
        for (int j = 0; j < days - 1; j++) {
            if (price[j] < price[j + 1]) {
                ans += (price[j + 1] - price[j]) * maxCount[i];
            }
        }
    }
    
    return ans;
}



int main(int argc, const char * argv[]) {
    // 此题答案80%，尝试接受类型改变，用double或职责long long
    int number,days;
    cin >> number >> days;
    
    vector<int> maxCount(number);
    for (int i = 0; i < number; i++) {
        cin >> maxCount[i];
    }
    vector<vector<int>> prices(number,vector<int>(days));
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < days; j++) {
            cin >> prices[i][j];
        }
    }
    
  
    cout << getResult(number,days,maxCount,prices) << endl;
//
    return 0;
}




