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

// 羊、狼、农夫过河
// 羊、狼、农夫都在岸边，当羊的数量小于狼的数量时，狼会攻击羊，农夫则会损失羊。农夫有一艘容量固定的船，能够承载固定数量的动物。
/*
5 4 3
*/

void dfs(int sheep, int wolf,int boat,int oppo_sheep,int oppo_wolf,int count, vector<int> &ans) {
    if (sheep == 0 && wolf == 0) {
        ans.push_back(count);
        return;
    }
    if (sheep + wolf <= boat) {
        ans.push_back(count + 1);
        return;
    }
    for (int i = 0; i < min(boat, sheep); i++) {
        for (int j = 0; j <= min(boat, wolf); j++) {
            if (i+j == 0) continue;
            if (i + j > boat) break;
            
            if (sheep - i <= wolf - j && sheep - i != 0) continue;
            if (oppo_sheep + i <= oppo_wolf +j && oppo_sheep + i != 0) break;
            if (oppo_sheep + i == 0 && oppo_wolf + j >= wolf) break;
            dfs(sheep - i, wolf - j, boat, oppo_sheep + i, oppo_wolf + j, count + 1, ans);
        }
        
    }
    
    
}

int getResult(int m,int n, int x) {

    vector<int> ans;
    dfs(m, n, x, 0, 0, 0, ans);
    if (ans.size() > 0) {
        sort(ans.begin(), ans.end());
        return ans[0];
    }
    
    return 0;
}



int main(int argc, const char * argv[]) {
    int m,n,x;
    cin >> m >> n >> x;
  
    cout << getResult(m,n,x) << endl;
//
    return 0;
}




