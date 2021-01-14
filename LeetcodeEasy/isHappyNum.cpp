class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int>seen;
       return getOutput(n,seen);
    }
    bool getOutput(int n,unordered_set<int> & seen){
        seen.insert(n);
         int newnum = 0;
        while(n>0){
            int newdigit = n%10;
            //cout<<"added to digits " << n%10 << endl;
            n = n/10; 
            newnum+= newdigit*newdigit;
            //cout<< "new n " << n << endl;
        }
        //cout << "new num " << newnum << endl;
        if(newnum == 1){
            return true;
        }
        else if(seen.find(newnum)!= seen.end()){
            return false;
        }
        else{
            return getOutput(newnum,seen);
        }
    }
};