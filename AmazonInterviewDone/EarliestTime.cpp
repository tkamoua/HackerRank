#include<iostream>
#include <algorithm>
#include <vector>
using namespace std;
int EarliestTime(int numOfBuildings, vector<int> buildingOpenTime, vector<int> offloadTime){
    int maxLoadingTime = 0;
    sort(buildingOpenTime.begin(),buildingOpenTime.end());
    sort(offloadTime.begin(),offloadTime.end(),greater<int>());
    
    for (int i = 0; i < buildingOpenTime.size();++i){
        // vector<int> loadtimes;
        // loadtimes.resize(4);
        // loadtimes[0] = offloadTime[i*4] + buildingOpenTime[i];
        // loadtimes[1] = offloadTime[i*4+1] + buildingOpenTime[i];
        // loadtimes[2] = offloadTime[i*4+2]+ buildingOpenTime[i];;
        // loadtimes[3] = offloadTime[i*4+3]+ buildingOpenTime[i];;
        // if(loadtimes[0] > maxLoadingTime){
        //     maxLoadingTime = loadtimes[0];
        // }
        // if (loadtimes[1] > maxLoadingTime){
        //     maxLoadingTime = loadtimes[1];
        // }
        // if (loadtimes[2] > maxLoadingTime){
        //     maxLoadingTime = loadtimes[2];
        // }
        // if (loadtimes[3] > maxLoadingTime){
        //     maxLoadingTime = loadtimes[3];
        // }
        int current_max_load_time = offloadTime[i*4+3]+buildingOpenTime[i];
        if (current_max_load_time > maxLoadingTime){
            maxLoadingTime = current_max_load_time;
        }
    }
    return maxLoadingTime;
}
int main(){
    int numOfBuildings = 2;
    vector<int> buildingOpenTime = {7,9};
    vector<int> offloadTime = {7,6,3,4,1,1,2,0};
    cout << EarliestTime(numOfBuildings,buildingOpenTime,offloadTime) << endl;
}

int EarliestTime(int numOfBuildings, vector<int> buildingOpenTime, vector<int> offloadTime){
    int maxLoadingTime = 0;
    sort(buildingOpenTime.begin(),buildingOpenTime.end());
     sort(offloadTime.begin(),offloadTime.end(),greater<int>());
     for (int i = 0; i < buildingOpenTime.size();++i){

     }
}