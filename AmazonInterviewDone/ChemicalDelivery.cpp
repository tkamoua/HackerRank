#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;


//Calculate loss for each flask type
// Loop over flask types
// loop over each requirement
// loop over each mark, find lowest error for each requirement 
// add lowest error to running total, get minimum running total

int ChemicalDelivery(int numOrders, vector<int> requirements, int flaskTypes, int totalMarks, vector<pair<int,int>> markings){
    unordered_map<int,vector<int>> markings_map; 
    for (int i = 0; i < markings.size();++i){
        auto it = markings_map.find(markings[i].first);
        if( it == markings_map.end()){
            vector<int> vals {markings[i].second};
            markings_map[markings[i].first] =vals; 
        }
        else{
            it->second.push_back(markings[i].second);
        }
    }
    int min_cost = INT_MAX;
    int min_flask = 0; 
    for (int i = 0; i < flaskTypes; ++ i){
        int total_cost_flask_i = 0;
        vector<int> flaskMarks = markings_map[i];
        for(int j = 0; j < numOrders;++j){
            int order_val = requirements[j];
            auto lower = lower_bound(flaskMarks.begin(),flaskMarks.end(),order_val);
            int cost = 0; 
            //cout <<"lower val " << *lower << endl;
            cost = *lower - order_val; 
            if (lower == flaskMarks.end()){
                //cout <<"lower bound not found" << endl;
                total_cost_flask_i = INT_MAX;
                break;
            }
            
            else{
                 total_cost_flask_i += cost; 
            }
            
           

        }
        //cout << "total cost" << total_cost_flask_i << endl;
        if(total_cost_flask_i < min_cost){
            min_flask = i;
            min_cost = total_cost_flask_i;
        }
    }
    return min_flask;
}
int main(){
    int numOrders = 4;
    vector<int> requirements {4,6,6,7};
    int flaskTypes = 3;
    int totalmarks = 9;
    vector<pair<int,int>> markings = {make_pair(0,3),make_pair(0,5),make_pair(0,7),
    make_pair(1,6),make_pair(1,8),make_pair(1,9),make_pair(2,3),make_pair(2,5),make_pair(2,6)};
    cout << ChemicalDelivery(numOrders,requirements,flaskTypes,totalmarks,markings) << endl;
}