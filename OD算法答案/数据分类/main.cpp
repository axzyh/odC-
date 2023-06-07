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



// 数据分类
// 对一个数据a进行分类，分类方法为：

int getBFor(int num,int b) {
    
    
    int n = sizeof(num);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += num >> (i * 8);
    }
    int a = sum - 255;
    return a % b;
}

bool compare(pair<int, int>a,pair<int, int>b){
    if (a.second > b.second) {
        return true;
    } else {
        return false;
    }
}

int getResult(int c, int b, vector<int>arr) {
   
    map<int, int> count;
    for (int i = 0; i < arr.size(); i++) {
        int num = getBFor(arr[i], b);
        if (num < c) {
            count[num]++;
        }
    }
    vector<pair<int, int>>v(count.begin(),count.end());
    sort(v.begin(), v.end(), compare);
    return v[0].second;
}

int main(int argc, const char * argv[]) {
    int c,b;
    cin >> c >> b;
    vector<int>arr(10);
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
    cout << getResult(c, b, arr) << endl;
//
    
    
    return 0;
}
