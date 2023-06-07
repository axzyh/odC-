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



// 阿里巴巴找黄金宝箱(II)
//一贫如洗的樵夫阿里巴巴在去砍柴的路上，无意中发现了强盗集团的藏宝地，藏宝地有编号从0-N的箱子，每个箱子上面贴有箱子中藏有金币数量

class Student {
public: string sid;
    string cid;
    int score1 = -1;
    int score2 = -1;
    int getSumScore() {
        return score1 + score2;
}
};


vector<int> getNumsForString(string s) {
    string tmp;
    vector<int> tVec;
    
    for (int i = 0; i < s.length(); i++) {
        if (tmp.length() > 0 && s[i] == ',') {
            tVec.push_back(stoi(tmp));
            tmp = "";
        } else {
            tmp += s[i];
        }
    }
    if (tmp.length() > 0) {
        tVec.push_back(stoi(tmp));
    }
    
    
    return tVec;
}

void divide(string s1,int courseId,unordered_map<string, Student> &students) {
    string tmp;
    vector<string> sVec;
    for (int i = 0; i < s1.length(); i++) {
        if (tmp.length() > 0 && s1[i] == ';') {
            sVec.push_back(tmp);
            tmp = "";
        } else if (s1[i] == ' ' ) {
            continue;
        } else {
            tmp += s1[i];
        }
    }
    sVec.push_back(tmp);
    
    for (string sub: sVec) {
        int pos = (int)sub.find(',');
        string sid = sub.substr(0,pos);
        string cid = sid.substr(0,5);
        int score = stoi(sub.substr(pos+1,sub.length() - 1));
//        students[sid] = Student();
        Student &stu = students[sid];
        stu.sid = sid;
        stu.cid = cid;
        if (courseId == 1) {
            stu.score1 = score;
        } else {
            stu.score2 = score;
        }
        
    }
    
    
}

bool compare(Student a, Student b) {
    if (a.getSumScore() > b.getSumScore()) {
        return true;
    } else if (a.getSumScore() == b.getSumScore() && a.sid <= b.sid)
        return true;
    else {
        return false;
    }
}

bool cmp(pair<int, int> a,pair<int, int> b) {
    return a.second >= b.second;
}

int getResult(vector<int> nums) {
    unordered_map<int, int> count;
    for (int num:nums) {
        count[num]++;
    }
    int half = ceil(nums.size() / 2.0);
    
    vector<pair<int, int>>vec(count.begin(),count.end());
    sort(vec.begin(), vec.end(), cmp);
    
    int remove = 0;
    int numCount = 0;
    
    for (auto i : vec) {
        remove += i.second;
        numCount++;
        if (remove >= half) {
            return numCount;
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    string str;
    getline(cin, str);
    vector<int> nums = getNumsForString(str);
    cout << getResult(nums) << endl;
    
    return 0;
}
