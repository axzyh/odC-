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



// 阿里巴巴找黄金宝箱(III)
// 一贫如洗的樵夫阿里巴巴在去砍柴的路上，无意中发现了强盗集团的藏宝地，藏宝地有编号从0-N的箱子，每个箱子上面贴有一个数字。

vector<int> getArrForString(string str) {
    vector<int> arr;
    string tmp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ',' && tmp.length() > 0) {
            arr.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += c;
        }
    }
    if (tmp.length() > 0) {
        arr.push_back(stoi(tmp));
    }
    return arr;
}

int getResult(vector<int> boxs, int len) {
    map<int, int> lastIdx;
    set<int> find;
    int ans = -1;
    for (int i = 0; i < boxs.size(); i++) {
        int num = boxs[i];
        if (find.count(num) == 1) {
            continue;
        }
        if (lastIdx.count(num) && i - lastIdx[num] <= len) {
            find.insert(num);
            ans = ans== -1 ? lastIdx[num] : min(ans, lastIdx[num]);
        } else {
            lastIdx[num] = i;
        }
    }
    return ans;
}



int main(int argc, const char * argv[]) {
  
    string str;
    getline(cin, str);
    int len;
    cin >> len;
    vector<int> boxs = getArrForString(str);
  cout << getResult(boxs,len) << endl;
   
    
    return 0;
}
