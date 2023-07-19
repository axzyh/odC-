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



// 选修课
//现有两门选修课，每门选修课都有一部分学生选修，每个学生都有选修课的成绩，需要你找出同时选修了两门选修课的学生，先按照班级进行划分，班级编号小的先输出，每个班级按照两门选修课成绩和的降序排序，成绩相同时按照学生的学号升序排序。

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



void getResult(string s1,string s2) {
    unordered_map<string, Student> students;
    divide(s1, 1, students);
    divide(s2, 2, students);
    
    vector<Student> vec;
    
    for (auto key:students) {
        Student stu = key.second;
        if (stu.score1 >= 0 && stu.score2 >= 0) {
            vec.push_back(stu);
        }
    }
  
    if (vec.size() == 0) {
        cout << "NULL" << endl;
        return;
    }
    sort(vec.begin(), vec.end(), compare);
    map<string, vector<Student>,less<string>> ans;
    for (auto stu: vec) {
        ans[stu.cid].push_back(stu);
    }
    
    for (auto stu:ans) {
        cout << stu.first << endl;
        vector<Student> vec = stu.second;
        string sb;
        for (auto i:vec) {
            if (sb.length() > 0) {
                sb += ";";
            }
            sb += i.sid;
        }
        cout << sb;
        cout << endl;
        
    }
   
}

int main(int argc, const char * argv[]) {
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    
    getResult(s1,s2);
    return 0;
}
