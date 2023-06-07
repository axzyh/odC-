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

// 士兵过河
// 一支N个士兵的军队正在趁夜色逃亡，途中遇到一条湍急的大河。
int getMinCrossRiverTime(int n, vector<int>t) {
    int cost = 0;
    while (n > 0) {
        if (n == 1) {
            cost += t[0];
            break;
        } else if (n == 2) {
            cost +=t[1];
            break;
        } else if (n == 3) {
            cost += t[1] + t[0] + t[2];
            break;
        } else {
            cost += min(t[0] + t[n-1] + t[0] +t[n - 2], t[1] + t[0] + t[n- 1] + t[1]);
            n -= 2;
        }
    }
    return cost;
}

string getResult(int n,int t, vector<int>times){
    
    sort(times.begin(), times.end());
    int min = 0;
    int max = n;
    string res;
    
    while (min <= max) {
        int mid = (min + max)/2;
        vector<int>midV;
        for (int i =0; i < mid; i++) {
            midV.push_back(times[i]);
        }
        int need = getMinCrossRiverTime(mid, midV);
        if (need > t) {
            max = mid - 1;
        } else if (need < t){
            res = to_string(mid) + " " + to_string(need);
            min = mid + 1;
        } else {
            res = to_string(mid) + " " + to_string(need);
        }
    }
    return res;
}


int main(int argc, const char * argv[]) {
    int n,t;
    cin >> n >> t;
    vector<int> times(n);
    for (int i = 0; i < n; i++) {
        cin >> times[i];
    }
    cout << getResult(n, t, times) << endl;
    
    return 0;
}
