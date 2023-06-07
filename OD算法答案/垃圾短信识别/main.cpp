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

// 垃圾短信识别
// 大众对垃圾短信深恶痛绝，希望能对垃圾短信发送者进行识别，为此，很多软件增加了垃圾短信的识别机制。


string getResultTest21(vector<pair<int, int>>vec,int id) {
    vector<int> send;
    vector<int> receive;
    
    map<int, int> sendCount;
    map<int, int> receiveCount;
    
    for (auto ele:vec) {
        int sid = ele.first;
        int rid = ele.second;
        if (sid == id) {
            send.push_back(rid);
            sendCount[rid] ? sendCount[rid]++ : sendCount[rid] = 1;
        }
        
        if (rid == id) {
            receive.push_back(sid);
            receive[sid] ? receive[sid]++ : receive[sid] = 1;
        }
    }
    
    set<int> sendSet(send.begin(),send.end());
    set<int> receiveSet(receive.begin(),receive.end());
    set<int>connect;
    set_intersection(sendSet.begin(), sendSet.end(), receiveSet.begin(), receiveSet.end(),inserter(connect, connect.begin()));
    int l = (int)(sendSet.size() - connect.size());
    int m = (int)(send.size() - receive.size());
    
    bool isSpammers = l > 5 || m > 10;
    
    for (int i : sendSet) {
        if (!isSpammers) {
            int ss = receiveCount[i] ? receiveCount[i] : 0;
            if (sendCount[i] - ss > 5) {
                isSpammers = true;
                break;
            }
        }
    }
    string ans = isSpammers ? "true":"false";
    return ans + " " + to_string(l) + " " + to_string(m);
}


int main(int argc, const char * argv[]) {
    int m,id;
    cin >> m;
    vector<pair<int, int>>vec(m);
    for (int i = 0; i < m; i++) {
        cin >> vec[i].first;
        cin >> vec[i].second;
    }
    cin >> id;
    cout << getResultTest21(vec, id) << endl;
    
    return 0;
}
