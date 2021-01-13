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

int uniquePairs(vector<int> nums, int target){
    unordered_map<int,int> pairs; 
    for(int i = 0; i < nums.size();++i){
        auto it = pairs.find(nums[i]);
        if(it == pairs.end()){
            pairs[nums[i]] = 1;
        }
        else{
            it->second++;
        }
        

    }
    int count = 0;
    for(int i = 0; i < nums.size();++i){
    
        auto it1 = pairs.find(nums[i]);
        auto it = pairs.find(target-nums[i]);
       
        if(it != pairs.end() && it1 != pairs.end()){
         
            if(it == it1){
              
                it->second--;
                if(it->second>0){
                    count+=1;
                
                    pairs.erase(it);
                }
            }
            else{
                count+=1;

                pairs.erase(it);
         
                pairs.erase(it1);
            }
            
            
        
        }
        
    }
    return count;
}

int main(){
    vector<int> nums {1,1,2,45,46,46};
    int target = 47;
    cout << uniquePairs(nums,target) << endl;

    vector<int> nums2 = {1,1};
    target = 2;
    cout << uniquePairs(nums2,target) << endl;

    vector<int> nums3 = {1,5,1,5};
    target = 6;
    cout << uniquePairs(nums3,target) << endl;
}