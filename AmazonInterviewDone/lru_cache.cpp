
// #given max size of cache and list of page requests
// #calculate number of cache misses
// #
// #cache miss occurs when page is requested and isn't found in the cache

// #create page queue where front of the queue is the least recently used, back is the most recently used
// #create cache set which is a set of size maxCacheSize that contains all the pages in the cache
// #Loop over pages list
// #for each page, check if in "cache" set
// #   if not, increment miss counter and 
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include<bits/stdc++.h> 
using namespace std;
int lruCacheMisses(int num, vector<int> pages, int maxCacheSize){
    int miss_count = 0;
    vector<int> cache; 
    cache.reserve(maxCacheSize);
    for(int i = 0; i < num; ++i){
        int value = pages[i];
        vector<int>::iterator it;
        it = find(cache.begin(),cache.end(),value);
        if (it != cache.end()){
       
            cache.erase(it);
            cache.push_back(value);
        }
        else{
            miss_count++;
            if(cache.size()>=maxCacheSize){
                cache.erase(cache.begin());
            }
            
            cache.push_back(value);

        }
    }
    return miss_count;
}
   

int main(){
    int num = 6;
    vector<int> pages {1,2,1,3,1,2};
    int maxCacheSize = 2;
    cout << lruCacheMisses(num,pages,maxCacheSize) << endl;
}