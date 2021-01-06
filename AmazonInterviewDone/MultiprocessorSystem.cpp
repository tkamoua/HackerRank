#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include<queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;
//2,5,5,7 
//10 
//dp array: num process
int MPSystem(int num, vector<int> ability, long int processes){
    priority_queue<int> ab;
    for(int i = 0; i < ability.size(); ++i){
        ab.push(ability[i]);
    }
    int steps = 0;
    while(processes > 0){
        int topval = ab.top();
        if(processes < topval){
            ab.pop();
        }
        else{
            processes -= topval; 
            ab.pop();
            ab.push(topval/2);
            steps++;
        }
    }
    return steps;
}
int main(){
    int num = 5;
    vector<int> ability {3,1,7,2,4};
    long int processes = 15;
    cout << MPSystem(num,ability,processes)<<endl;
}