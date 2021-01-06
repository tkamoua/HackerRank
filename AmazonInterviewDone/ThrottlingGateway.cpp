

// num transactions per second <=3
// num transactions per 10 seconds <= 20
// num transactions per 60 seconds <= 60

//arrival times are sorted
// output = set containing dropped element index
// count = num elements in output

#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include<queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//creat hashtable containg key = int = time, value = int = count
// loop through request time and update hashtable
//
int countDropped = 0;
void checkLastTenSeconds(vector<int> & requestTime, unordered_map<int,int> & requests, unordered_set<int>& dropped, int t, int index){
    int begin = t - 10;
    int count = 0;
    for(int i = begin; i < t; ++i){
        auto it = requests.find(i);
        if(it == requests.end()){
            continue;
        }
        else{
            count+= it->second; 
        }
    }
    while(count > 20){
        int t = requestTime[index];
        dropped.insert(t);
        countDropped++;
        // auto it = requests.find(t);
        // it->second--;
        --index;
        --count;
    }
}
void checkLastSixtySeconds(vector<int> & requestTime, unordered_map<int,int> & requests, unordered_set<int>& dropped, int t, int index){
    int begin = t - 60;
    int count = 0;
    for(int i = begin; i < t; ++i){
        auto it = requests.find(i);
        if(it == requests.end()){
            continue;
        }
        else{
            count+= it->second; 
        }
    }
    while(count > 60){
        int t = requestTime[index];
        dropped.insert(t);
        countDropped++;
        // auto it = requests.find(t);
        // it->second--;
        --index;
        --count;
    }
}
int throttlingGateway(vector<int> requestTime){
    unordered_map<int,int> requests;
    unordered_set<int> dropped; 
  
    for(int i = 0; i < requestTime.size();++i){
        int t = requestTime[i];
        auto it = requests.find(t);
        if(it != requests.end()){
            it->second++;
            if(it->second > 3){
                dropped.insert(t);
                countDropped++;
            }
        }
        else{
            requests[t] = 1; 
        }
        checkLastTenSeconds(requestTime,requests,dropped,t,i);
        checkLastSixtySeconds(requestTime,requests,dropped,t,i);
    }
    return countDropped;
    
}

int main(){
    vector<int> t1 {1,1,1,1,2};
    cout << throttlingGateway(t1)<<endl;
    vector<int> t2 {1,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7};
    cout << throttlingGateway(t2)<<endl;
}