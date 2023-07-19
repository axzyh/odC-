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
#include <unordered_set>
#include <regex>

using namespace std;



// 组装最大可靠性设备
// 一个设备由N种类型元器件组成(每种类型元器件只需要一个，类型type编号从0~N-1)，


class Device {
public:  int reliability;
    int price;
public: Device(int re, int p) {
    reliability = re;
    price = p;
}
};



bool compare(Device a, Device b) {
    if (a.reliability < b.reliability) {
        return true;
    } else {
        return false;
    }
}

int binarySearch(vector<Device> kind, int target) {
    int low = 0;
    int high = (int)kind.size() - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        Device device = kind[mid];
        if (device.reliability > target) {
            high = mid - 1;
        } else if(device.reliability < target) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -low - 1;
}

bool check(vector<vector<Device>> kinds, int maxReliability, int s) {
    int sum = 0;
    for (vector<Device> kind: kinds) {
        int idx = binarySearch(kind, maxReliability);
        if (idx < 0) {
            idx = -idx - 1;
        }
        if (idx == kind.size()) {
            return false;
        }
        sum += kind[idx].price;
    }
    return sum <= s;
}

int getResult(int s, vector<vector<Device>> kinds, set<int> reliabilities) {
    int ans = -1;
    for (vector<Device> &kind :kinds) {
        sort(kind.begin(), kind.end(), compare);
    }
    vector<int> maybe(reliabilities.begin(),reliabilities.end());
    int low = 0;
    int high = (int)maybe.size() - 1;
    while (low <= high) {
        int mid = (low + high) >> 1;
        if (check(kinds, maybe[mid], s)) {
            ans = maybe[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
  
    return ans;
}



int main(int argc, const char * argv[]) {
    
    int s, m, total,type, reliability, price;
    cin >> s >> m;
    set<int> reliabilities;
    vector<vector<Device>> kinds(m);
    
    cin >> total;
    for (int i = 0; i < total; i++) {
        cin >> type;
        cin >> reliability;
        reliabilities.insert(reliability);
        cin >> price;
        kinds[type].push_back(Device(reliability,price));
    }
    
    cout << getResult(s,kinds,reliabilities) << endl;
    
    
    return 0;
}
