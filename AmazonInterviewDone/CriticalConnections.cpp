
#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include<queue>
#include <unordered_map>
using namespace std;

//critical if removing it results in disconnected network of servers
//find minimum spanning tree of graph
//remove an edge. if mst still exists, continue
//if mst doesnt exist, add edge to output 
class Solution {
public:
    
  
   int dfs(vector<vector<int>> &connections,int start,vector<int>& ranks,int startRank){
    
    // for(int i = 0; i < connections.size();++i){
    //     for(int j = 0; j < connections[i].size();  j++){
    //         cout << connections[i][j] << " ";
    //     }
    //     cout << endl;
    // }
     
    vector<int> adj = connections[start];
    // while(adj.size() == 0){
    //     adj = connections[start+1];
    // }
    if(ranks[start] >= 0){
        return ranks[start];
    }
    
    ranks[start] = startRank;
    int min_rank = startRank;
    for(int i = 0; i < adj.size();++i){
      
        if(ranks[adj[i]] == startRank -1 || ranks[adj[i]] > startRank){
            continue;
        }
        int nextRank = dfs(connections,adj[i],ranks,startRank+1);
        if (nextRank <= startRank){

            auto it2 = find(connections[start].begin(),connections[start].end(),adj[i]);
            connections[start].erase(it2);
            
        }
        auto it3 = find(connections[adj[i]].begin(),connections[adj[i]].end(),start);
        connections[adj[i]].erase(it3);
        min_rank = min(min_rank,nextRank);

       
    }
    return min_rank;


}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> connections ){
    vector<vector<int>> conn_map; 
    conn_map.resize(n);
    for(int i = 0; i < connections.size();++i){
        int f = connections[i][0];
        int s = connections[i][1];
        conn_map[f].push_back(s);
        conn_map[s].push_back(f);
      
    }
    

    vector<int> ranks; 
    int startRank = 0;
    ranks.resize(n,-2);
    
    dfs(conn_map,0,ranks,0);
    vector<vector<int>> result; 
    result.reserve(n);
     for(int i = 0; i < conn_map.size();++i){
        int f = i;
        for(int j = 0; j < conn_map[i].size();++j){
            vector<int> temp {f,conn_map[i][j]};
            result.push_back(temp); 
        }
       
      
    }
    return result;

}
};