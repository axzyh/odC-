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

// 任务调度
// 现有一个CPU和一些任务需要处理，已提前获知每个任务的任务ID、优先级、所需执行时间和到达时间。
/*
 1 3 5 1
 2 1 5 10
 3 2 7 12
 4 3 2 20
 5 4 9 21
 6 4 2 22
*/

vector<int> getArrStringForS(string str) {
    vector<int> arr;
    string temp;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (c == ' ' && temp.length() > 0) {
            arr.push_back(stoi(temp));
            temp = "";
        } else {
            temp += c;
        }
    }
    if (temp.length() > 0) {
        arr.push_back(stoi(temp));
    }
    return arr;
}

class Task {
public:  int id; // 任务id；
    int priority; // 任务优先级
    int need; // 任务执行时长
    int arrived; // 任务到达时间
public:  Task(int _id, int _priority,int _need, int _arrived) {
        id = _id;
        priority = _priority;
        need = _need;
        arrived = _arrived;
    }
};


bool compare(int a, int b) {
    if (a > b) {
        return true;
    }
    return false;
}

template <typename T>

struct comp {
  bool operator()(Task a, Task b){
      if (a.priority < b.priority) {
          return true;
      }
      if (a.priority == b.priority && a.arrived > b.arrived) {
          return true;
      }
        return false;
    }
};

void getResult(vector<Task> tasks) {
    priority_queue<Task,vector<Task>,comp<Task>> pq;
    pq.push(tasks[0]);
    tasks.erase(tasks.begin());
    int curTime = pq.top().arrived;
    while (tasks.size() > 0) {
        Task curTask = pq.top();
        Task nextTask = tasks[0];
        tasks.erase(tasks.begin());
        int curTask_endTime = curTime + curTask.need;
        
        if (curTask_endTime > nextTask.arrived) {
            curTask.need -= nextTask.arrived - curTime;
            pq.pop();
            pq.push(curTask);
            curTime = nextTask.arrived;
        } else {
            pq.pop();
            cout << curTask.id << " " << curTask_endTime << endl;
            curTime = curTask_endTime;
            
            if (nextTask.arrived > curTask_endTime) {
                while (pq.size() > 0) {
                    Task idleTask = pq.top();
                    int idleTask_endTime = curTime + idleTask.need;
                    if (idleTask_endTime > nextTask.arrived) {
                        idleTask.need -= nextTask.arrived - curTime;
                        pq.pop();
                        pq.push(idleTask);
                        break;
                    } else {
                        pq.pop();
                        cout << idleTask.id << " " << idleTask_endTime << endl;
                        curTime = idleTask_endTime;
                    }
                }
                curTime = nextTask.arrived;
            }
        }
        pq.push(nextTask);
    }
    
    // 所有任务都加入优先队列后，
    while (pq.size() > 0) {
        Task pollTask = pq.top();
        pq.pop();
        int pollTask_endTime = curTime + pollTask.need;
        cout << pollTask.id  << " " << pollTask_endTime << endl;
        curTime = pollTask_endTime;
    }
    
    
}



int main(int argc, const char * argv[]) {
  
    string str;
    vector<Task> list;
    while (true) {
        getline(cin, str);
        if (str == "") {
            break;
        }
        vector<int> arr = getArrStringForS(str);
        list.push_back(Task(arr[0], arr[1], arr[2], arr[3]));
    }

    getResult(list);
//
    return 0;
}




