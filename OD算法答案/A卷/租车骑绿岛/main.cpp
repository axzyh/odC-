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

// 租车骑绿岛
// 部门组织绿岛骑行团建活动。租用公共双人自行车，每辆自行车最多坐两人，最大载重M。



int getResult(int m,int n, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int count = 0;
    int l = 0;
    int r = (int)arr.size() - 1;
    while (l < r) {
        if (arr[l] + arr[r] <= m) {
            l++;
        }
        r--;
        count++;
    }
    if (l == r) {
        count++;
    }
    
    return count;
}



int main(int argc, const char * argv[]) {
    int m, n;
    cin >> m >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    
    cout << getResult(m,n,arr) << endl;
//
    return 0;
}




