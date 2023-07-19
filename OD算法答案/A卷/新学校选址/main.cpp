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

// 新学校选址
// 为了解新学期学生暴涨的问题,小乐村要建立所新学校，
/*
 5
 0 20 40 10 30
*/

int getResult(int n, vector<int> arr) {
    sort(arr.begin(), arr.end());
    int len = (int)arr.size();
    int mid = len / 2;
    if (len % 2 == 0) {
        return arr[mid - 1];
    } else {
        return arr[mid] ;
    }
}



int main(int argc, const char * argv[]) {
  
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
  
   cout << getResult(n,arr) << endl;
//
    return 0;
}




