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



// 报文回路
//  ICMP协议中响应报文和查询报文，是维系组播通路的两个重要报文，在一条已经建立的组播通路中两个相邻的 HOST 和 ROUTER，ROUTER 会给 HOST 发送查询报文，HOST 收到查询报文后给 ROUTER 回复一个响应报文，以维持相之间的关系，一旦这关系断裂，那么这条组播通路就异常”了。现通过某种手段，抓取到了 HOST 和 ROUTER 两者通讯的所有响应报文和查询报文，请分析该组播通路是否“正常”
void getResult() {
    int n, a, b;
    cin >> n;
    map<int, set<int>> map;
    
    for (int i = 0 ; i < n; i++) {
        set<int>s;
        cin >> a >> b;
        if (map.count(a)) {
            s = map[a];
        }
        s.insert(b);
        map[a] = s;
    }
   
    for (auto &t:map) {
        set<int> receive = t.second;
        set<int> receive1;
        
        for (auto i: receive) {
            
            if (!(map[i].count(t.first))) {
                cout << "False" << endl;
                return;
            }
        }
    }
    cout << "True" << endl;
}

int main(int argc, const char * argv[]) {
    getResult();
    
    return 0;
}
