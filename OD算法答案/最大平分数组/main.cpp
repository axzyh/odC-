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

// 最大平分数组
// 给定一个数组nums，可以将元素分为若干个组，使得每组和相等，求出满足条件的所有分组中，最大的平分组个数。


static bool compare(int a, int b) {
    if (a > b) {
        return true;
    } else {
        return false;
    }
}

bool partition(vector<int> link, int index, vector<int>vec,int subSum) {
    if (index == link.size()) {
        return true;
    }
    
    int select = link[index];
    for (int i = 0; i < vec.size(); i++) {
        if (i > 0 && vec[i] == vec[i - 1]) {
            continue;
        }
        if (select + vec[i] <= subSum) {
            vec[i] +=select;
            if (partition(link, index+1, vec,subSum)) {
                return true;
            }
            vec[i] -=select;
        }
    }
    
    return false;
    
}

bool canPartitionMsubsets(vector<int>link, int sum,int n) {
    
    if (sum % n != 0 ) {
        return false;
    }
    
    int subSum = sum / n;
    if (subSum < link[0]) {
        return false;
    }
    while (link.size() > 0 && link[0] == subSum) {
        link.erase(link.begin() + 0);
        n--;
    }
    
    vector<int>vec(n);
    return partition(link, 0, vec,subSum);
    
}

int getResult(vector<int>vec, int n) {
    sort(vec.begin(), vec.end(),compare);
    int sum = 0;
    for (int i = 0; i < vec.size(); i++) {
        sum +=vec[i];
    }
    while (n >= 1) {
        vector<int> link_cp = vec;
        if (canPartitionMsubsets(link_cp, sum, n)) {
            return n;
        }
        n--;
    }
    return 1;
    
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    vector<int>vec(n);
    for (int i = 0 ; i < n; i++) {
        cin >> vec[i];
    }
    
    cout << getResult(vec, n) << endl;
    
    return 0;
}
