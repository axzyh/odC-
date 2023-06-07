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



// 叠积木
// 有一堆长方体积木，它们的高度和宽度都相同，但长度不一。

vector<int> getNumsForString(string s) {
    string tmp;
    vector<int> tVec;
    
    for (int i = 0; i < s.length(); i++) {
        if (tmp.length() > 0 && s[i] == ' ') {
            tVec.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        tVec.push_back(stoi(tmp));
    }
    return tVec;
}


bool partition(vector<int>link, int index, vector<int> &buckets, int subSum) {
    if (index == link.size()) {
        return true;
    }
    int select = link[index];
    for (int i = 0; i < buckets.size(); i++) {
        if (i > 0 && buckets[i] == buckets[i - 1]) {
            continue;
        }
        if (select + buckets[i] <= subSum) {
            buckets[i] += select;
            if (partition(link, index + 1, buckets,subSum)) {
                return true;
            }
            buckets[i] -=select;
        }
    }
    return false;
}

bool canPartitionMsubsets(vector<int> &link, int sum,int m) {
    if (sum % m != 0 ) {
        return false;
    }
    int subSum = sum / m;
    if (sum < link[0]) {
        return false;
    }
    
    while (link.size() > 0 && link[0] == subSum) {
        link.erase(link.begin() + 0);
        m--;
    }
    vector<int> buckets(m);
    
    return partition(link, 0, buckets,subSum);
}

bool compare(int a, int b) {
    if (b >= a) {
        return false;
    } else {
        return true;
    }
}

int getResult(vector<int> nums) {
    sort(nums.begin(), nums.end(),compare);
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum +=nums[i];
    }
    
    int m = (int)nums.size();
    while (m > 1) {
        vector<int> link = nums;
        if (canPartitionMsubsets(link, sum, m)) {
            return m;
        }
        m--;
    }
    return -1;
}



int main(int argc, const char * argv[]) {
    string s;
    getline(cin, s);
    vector<int> nums = getNumsForString(s);
    
    cout << getResult(nums) << endl;
    
    return 0;
}
