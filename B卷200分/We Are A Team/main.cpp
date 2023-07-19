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


using namespace std;

// We Are A Team
// 总共有 n 个人在机房，每个人有一个标号（1<=标号<=n），他们分成了多个团队，需要你根据收到的 m 条消息判定指定的两个人是否在一个团队中，具体的：


class UnionFindSet {
public: vector<int> fa;
public: UnionFindSet(int n) {
        fa = vector<int>(n);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
    }
    int find(int x) {
        if (x != fa[x] ) {
            return fa[x] = find(fa[x]);
        }
        return x;
    }
    
    void unionn(int x, int y) {
        int fa_x = find(x);
        int fa_y = find(y);
        if (fa_x != fa_y) {
            fa[fa_y] = fa_x;
        }
    }
    
};

bool compare(vector<int>a, vector<int> b) {
    if (a[2] < b[2]) {
        return true;
    } else {
        return false;
    }
}

void getResult(int n,int m, vector<vector<int>> nums) {
    if (n < 1 || n > 1000000 || m < 1 || m > 1000000) {
        cout << "Null" << endl;
        return;
    }
    
    UnionFindSet ufs = UnionFindSet(n + 1);
    sort(nums.begin(), nums.end(), compare);
    
    for (vector<int> num : nums) {
        int a = num[0], b = num[1], c = num[2];
        if (a < 1 || a > n || b < 1 || b > n) {
            cout << "da pian zi" << endl;
            continue;
        }
        if (c == 0) {
            ufs.unionn(a, b);
        } else if (c == 1) {
            if (ufs.find(a) == ufs.find(b)) {
                cout <<  "We are team"  << endl;
            } else {
                cout <<  "We are not a team"  << endl;
            }
        } else {
            cout << "da pian zi" << endl;
        }
    }

}

int main(int argc, const char * argv[]) {
   
    int n,m;
    cin >> n >> m;
    vector<vector<int>> nums(m, vector<int>(3));
    
    for (int i = 0; i < m; i++) {
        cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
    }
    
    getResult(n, m, nums);
    
    return 0;
}
