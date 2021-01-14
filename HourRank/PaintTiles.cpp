#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void paint(int N, string C);
int main(){
    int N;
    cin >> N;
    string C;
    cin >> C;
    paint(N,C);
    return 0;
}
void paint(int N, string C){
    char curr_color = C[0]; 
    int count = 1;
    for(int i = 1; i < C.length();++i){
        if(C[i] != curr_color){
            curr_color = C[i];
            count++;
        }
    }
    cout<<count<<endl;
}