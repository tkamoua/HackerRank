
#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include<queue>
#include <unordered_map>
using namespace std;

//O(nlogn)
// string LabelingSystem(string originalLabel, int char_limit){
//     sort(originalLabel.begin(),originalLabel.end(),greater<char>());
//     char prev_char = '0';
//     int repeat_counter = 1;
//     for (int i = 0; i < originalLabel.length(); ++i){
//         if(originalLabel[i] == prev_char){

//O(n)
int find_next_char( unordered_map<int,int> &freq, int start){
    for(int j = start; j >= 0; --j){
        auto it = freq.find(j);
        if( it != freq.end() && it ->second > 0){
            return j;
        }
    }
    return -1;
}
string LabelingSystem(string originalLabel, int char_limit){
    unordered_map<int,int> freq; 
    for(int i = 0; i < originalLabel.length();++i){
        char cur = originalLabel[i];
        int cur_i = cur - 'a';
        auto it = freq.find(cur_i);
        if(it == freq.end()){
            freq[cur_i] = 1;
        }
        else{
            it->second++;
        }
    }
    string output = "";


    for(int j = 25; j >= 0; --j){
        int repeat_count = 0;
        auto it = freq.find(j);
        if (it != freq.end() && it->second > 0){
            while (repeat_count < char_limit && it->second > 0){
                output += char('a'+j);
                it->second--;
                repeat_count++;

            }
            if(it->second > 0){
                int next_char = find_next_char(freq,j-1);
                auto it = freq.find(next_char);
                it->second--;
                output += char('a'+next_char);
                j++;
                continue;
            }
        }
    }
    return output;
    
}

      
//             if (repeat_counter == char_limit){
//                 int j = i+1; 
//                 while(originalLabel[j] == prev_char){
//                     ++j;
//                 }
//                 if(j >= originalLabel.length()){
//                     cout <<"not my fault"<<endl;
//                     return "not my fault";
//                 }
//                 swap(originalLabel[i],originalLabel[j]);
//             }
//             repeat_counter++;
            
//         }
//         else{
//             repeat_counter = 1;
//             prev_char = originalLabel[i];
//         }
//     }
//     return originalLabel;
// }

int main(){
    string originalLabel = "baccc";
    int charLimit = 2;
    cout << LabelingSystem(originalLabel,charLimit) << endl;
}