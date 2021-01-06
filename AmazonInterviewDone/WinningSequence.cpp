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

vector<int> winningSequence(int num, int lowerEnd, int upperEnd){
    vector<int> output;
    
    if (upperEnd-lowerEnd < 2){
        return vector<int>{-1};
    }
    int max = 2*(upperEnd-lowerEnd) + 1;
    if(num > max){
        return vector<int>{-1};
    }

    
    int start = upperEnd-1; 
    int seqlength = upperEnd-start+1+(upperEnd-lowerEnd);
    while(num > seqlength){
        start--;
        seqlength = upperEnd-start+1+(upperEnd-lowerEnd);
    }
    output.reserve(num);
    for(int i = start; i < upperEnd+1;++i){
        output.push_back(i);
    }
    for(int i = upperEnd-1; output.size() < num;--i){
        output.push_back(i);
    }
   
   return output;
}

int main(){
    int num = 5;
    int lowerEnd = 3;
    int upperEnd = 10;
    vector<int> output = winningSequence(num,lowerEnd,upperEnd);
    for(int i = 0; i < output.size(); ++i){
        cout << output[i] << ", ";
    }
    cout << endl;
    output = winningSequence(7,3,10);
    for(int i = 0; i < output.size(); ++i){
        cout << output[i] << ", ";
    }
    cout << endl;

    output = winningSequence(10,3,10);
    for(int i = 0; i < output.size(); ++i){
        cout << output[i] << ", ";
    }
    cout << endl;

    output = winningSequence(15,3,10);
    for(int i = 0; i < output.size(); ++i){
        cout << output[i] << ", ";
    }
    cout << endl;
    
    output = winningSequence(16,3,10);
    for(int i = 0; i < output.size(); ++i){
        cout << output[i] << ", ";
    }
    cout << endl;

    output = winningSequence(5,1,3);
    for(int i = 0; i < output.size(); ++i){
        cout << output[i] << ", ";
    }
    cout << endl;

    output = winningSequence(3,1,3);
    for(int i = 0; i < output.size(); ++i){
        cout << output[i] << ", ";
    }
    cout << endl;

    output = winningSequence(5,9,10);
    for(int i = 0; i < output.size(); ++i){
        cout << output[i] << ", ";
    }
    cout << endl;

    output = winningSequence(5,10,10);
    for(int i = 0; i < output.size(); ++i){
        cout << output[i] << ", ";
    }
    cout << endl;
}