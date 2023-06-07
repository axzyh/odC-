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



// 农场施肥、不爱施肥的小布
// 某农场主管理了一大片果园，fields[i]表示不同果林的面积，单位：m^2，现在要为所有的果林施肥且必须在n天之内完成，否则影响收成。小布是果林的工作人员，他每次选择一片果林进行施肥，且一片果林施肥完后当天不再进行施肥作业。
int check(int k,int n, vector<int>fields) {
    int spend = 0;
    for (int field : fields) {
        if (k >= field) {
            spend++;
        } else {
            spend += ceil((field / (double)k));
        }
    }
    return spend - n;
}

int getResult(vector<int>fields, int n) {
    double min = 1;
    sort(fields.begin(), fields.end());
    double max = fields.back();
    int ans = -1;
    while (min <= max) {
        int k = ceil((min + max)/2);
        int res = check(k, n, fields);
        if (res > 0) {
            min = k+1;
        } else {
            ans = k;
            max = k - 1;
        }
    }
    return ans;
}

void test7() {
  
    
}

int main(int argc, const char * argv[]) {
    int n,m;
    cin >> n >> m;
    vector<int>vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    cout << getResult(vec, m) << endl;
    
    return 0;
}
