#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include<queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

bool isDivisible(string s, string t){
    int og_len = t.length();
    while(s.substr(0,t.length()) == t){

        t = t + t.substr(t.length()-og_len);
        
    }
    t = t.substr(0,t.length()-og_len);

    if (s == t){
        return true;
    }
    else{
        return false;
    }
}
int divisibilityString(string s, string t){
    int min_count = t.length();
    if(isDivisible(s,t)){
        for(int i = t.length()-1; i >0; --i){
            string new_t = t.substr(0,t.length()-i);
            if(isDivisible(s,new_t)){
               return new_t.length();
            }
        }
        return min_count;
    }
    return -1;
}
int main(){
    string s1 = "bcdbcdbcd";
    string t1 = "bcdbcd";
    cout << divisibilityString(s1,t1)<<endl;

    string s2 = "bcdbcdbcdbcd";
    string t2 = "bcdbcd";
    cout << divisibilityString(s2,t2) << endl;

    string s3 = "aaaaaa";
    string t3 = "a";
    cout << divisibilityString(s3,t3) << endl;

    string s4 = "wqzpuogsqcxpqizenbrhcbijieufuxgqpfijuobkqacjkdnzggijhqurwqyrnejckrnghqsyswhczwdicltjdndaebrtgcysulydcsbupkzogewkqpwtfzvjameircaloaqstsoiepynuvxmmthrsdcvrhdijgvzgmtzeijkzixtfxhrqpllspijwnsitnjazdwqzpuogsqcxpqizenbrhcbijieufuxgqpfijuobkqacjkdnzggijhqurwqyrnejckrnghqsyswhczwdicltjdndaebrtgcysulydcsbupkzogewkqpwtfzvjameircaloaqstsoiepynuvxmmthrsdcvrhdijgvzgmtzeijkzixtfxhrqpllspijwnsitnjazdwqzpuogsqcxpqizenbrhcbijieufuxgqpfijuobkqacjkdnzggijhqurwqyrnejckrnghqsyswhczwdicltjdndaebrtgcysulydcsbupkzogewkqpwtfzvjameircaloaqstsoiepynuvxmmthrsdcvrhdijgvzgmtzeijkzixtfxhrqpllspijwnsitnjazdwqzpuogsqcxpqizenbrhcbijieufuxgqpfijuobkqacjkdnzggijhqurwqyrnejckrnghqsyswhczwdicltjdndaebrtgcysulydcsbupkzogewkqpwtfzvjameircaloaqstsoiepynuvxmmthrsdcvrhdijgvzgmtzeijkzixtfxhrqpllspijwnsitnjazd";
    string t4 = "wqzpuogsqcxpqizenbrhcbijieufuxgqpfijuobkqacjkdnzggijhqurwqyrnejckrnghqsyswhczwdicltjdndaebrtgcysulydcsbupkzogewkqpwtfzvjameircaloaqstsoiepynuvxmmthrsdcvrhdijgvzgmtzeijkzixtfxhrqpllspijwnsitnjazdwqzpuogsqcxpqizenbrhcbijieufuxgqpfijuobkqacjkdnzggijhqurwqyrnejckrnghqsyswhczwdicltjdndaebrtgcysulydcsbupkzogewkqpwtfzvjameircaloaqstsoiepynuvxmmthrsdcvrhdijgvzgmtzeijkzixtfxhrqpllspijwnsitnjazd";
    cout << divisibilityString(s4,t4) << endl;

}