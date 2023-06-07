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



// 模拟消息队列
// 让我们来模拟一个消息队列的运作，有一个发布者和若干消费者，发布者会在给定的时刻向消息队列发送消息，


vector<pair<int, int>> getNumsForString(string s) {
    vector<pair<int, int>>nums;
    string temp;
    int left = 0;
    int right = 0;
    for (int i = 0; i < s.length(); i++) {
       
        if (temp.length() >0 && s[i] == ' '  ) {
            if (left > 0) {
                right =  stoi(temp);
                nums.push_back(make_pair(left,right));
                left = right = 0;
            } else  {
                left = stoi(temp);
            }
            temp = "";
        } else {
            temp += s[i];
        }
    }
    if (temp.length() > 0 && left > 0 ) {
        right =  stoi(temp);
        nums.push_back(make_pair(left,right));
    }
    return nums;
}

bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.first <= b.first) {
        return true;
    } else {
        return false;
    }
}

void getResult(vector<pair<int, int>>nums,vector<pair<int, int>>subArr) {
    
    sort(nums.begin(), nums.end(), compare);
 
    vector<vector<int>>vec;
    for (int i = 0; i < subArr.size(); i++) {
        vec.push_back(vector<int>());
    }
        
        for (auto pub:nums) {
            int pubTime = pub.first;
            int pubContent = pub.second;
            
            for (int j = subArr.size() - 1; j >= 0; j--) {
                int subTime = subArr[j].first;
                int endTime = subArr[j].second;
                if (pubTime < endTime && pubTime >= subTime) {
                    vec[j].push_back(pubContent);
                    break;
                }
            }
            
        }
        
    // 打印
    for (auto contents:vec ) {
        if (contents.size() == 0) {
            cout << -1 << endl;
        }  else {
            string sb;
            for (int content:contents) {
                if (sb.length() > 0) {
                    sb += " ";
                
                }
                sb += to_string(content);
            }
            
            cout << sb << endl;
        }
    }
    
}

int main(int argc, const char * argv[]) {
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
   

    getResult(getNumsForString(s1),getNumsForString(s2));
    
    return 0;
}
