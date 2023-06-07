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

// 最优高铁城市修建方案
// 高铁城市圈对人们的出行、经济的拉动效果明显。每年都会规划新的高铁城市圈建设。
// 在给定：城市数量，可建设高铁的两城市间的修建成本列表、以及结合城市商业价值会固定建设的两城市建高铁。
bool compareTest23(vector<int>a, vector<int>b) {
    if (a[2] < b[2]) {
        return true;
    }
    return false;
}

class UnionFindSet {
    vector<int> fa;
public:int count;
public: UnionFindSet(int n) {
        for (int i = 0; i <= n; i++) {
            fa.push_back(i);
            count = n;
        }
    }
    
    int find(int x) {
        if (x != fa[x]) {
            return fa[x] = find(fa[x]);
        }
        return x;
    }
    
   void uniond(int x , int y) {
        int x_fa = find(x);
        int y_fa = find(y);
        if (x_fa != y_fa) {
            fa[y_fa] = x_fa;
            count--;
        }
    }
};

//vector<int>father(4);
//
//int find(int x) {
//    if (x != father[x]) {
//        father[x] = find(father[x]);
//        return father[x];
//    } else {
//        return x;
//    }
//}
//
//void unionF(int i, int j ) {
//    int ifa = find(i);
//    int jfa = find(i);
//    if (ifa != jfa) {
//        father[jfa] = ifa;
//        // 合并了一次
//    }
//}

int getResut(int n, vector<vector<int>>cans,vector<vector<int>> musts) {
    UnionFindSet ufs = UnionFindSet(n);
    
    map<string, int> cansMap;
    for (auto can:cans) {
        int city1 = can[0], city2 = can[1], fee = can[2];
        string key = city1 < city2 ? to_string(city1) + "-" + to_string(city2) : to_string(city2) + "-" + to_string(city1);
        cansMap[key] = fee;
        
    }
    int minFee = 0;
    for (auto must: musts) {
        string key = must[0] < must[1] ? to_string(must[0]) + "-" + to_string(must[1]) : to_string(must[1]) + "-" + to_string(must[0]);
        minFee += cansMap[key];
        ufs.uniond(must[0], must[1]);
    }
    
    if (ufs.count == 1) {
        return minFee;
    }
    
    sort(cans.begin(), cans.end(), compareTest23);
    for (auto can:cans) {
        int city1 = can[0], city2 = can[1], fee = can[2];
        if (ufs.find(city1) != ufs.find(city2)) {
            ufs.uniond(city1, city2);
            minFee += fee;
        }
        if (ufs.count == 1) {
            break;
        }
    }
    
    if (ufs.count > 1) {
        return -1;
    }
    return minFee;
}

int main(int argc, const char * argv[]) {
    int n, can, must;
    cin >> n >> can >> must;
    vector<vector<int>>vec(can,vector<int>(3));
    
    for (int i = 0; i < can; i++) {
        cin >> vec[i][0];
        cin >> vec[i][1];
        cin >> vec[i][2];
    }
    vector<vector<int>> musts(must,vector<int>(2));
    for (int i = 0; i < must; i++) {
        cin >> musts[i][0] >> musts[i][1];
    }
    cout << getResut(n, vec, musts) << endl;
    
    return 0;
}
