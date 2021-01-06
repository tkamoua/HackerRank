#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include<queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;


vector<string> uniqueDeviceNames(int num, vector<string> device_names){
    unordered_map<string,int> names_count; 
    for(int i = 0; i < device_names.size();++i){
        string name = device_names[i];
        auto it = names_count.find(name);
        if(it == names_count.end()){
            names_count[name] = 0;
        }
        else{
            it->second++;
            device_names[i] = device_names[i]+to_string(it->second);
        }
    }
    return device_names;
}

int main(){
    int num = 6;
    vector<string> devicenames {"switch","tv","switch","tv","switch","tv"};
    vector<string> output = uniqueDeviceNames(num,devicenames);
    for(int i = 0; i < output.size();++i){
        cout << output[i] << " ";
    }
    cout << endl; 
}