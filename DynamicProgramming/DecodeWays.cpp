class Solution {
public:
    //dp bottom up, vector<int> dp of size s.length()+1
    //each position of dp vector contains the number of ways to map with that number of letters
    //base case: 0, dp[0] = 0
    //base case: 1, dp[1] = 1
  
    //loop over rest of string
    //for each position, if (s[i-1] is 1 ), dp[i] = 1+dp[i-1]
    //                      if(s[i-1] is 2 and s[i] is 0<=s[i]<=6) return 1+dp[i-1]
    //                      else, return dp[i-1]
    int numDecodings(string s) {
        
           bool foundZero = false;
        vector<int> dp;
        dp.resize(s.length()+1);
        
        dp[0] = 1;
        if(s[0] == '0'){
            dp[1] = 0;
            foundZero = true;
        }
        else{
            dp[1] = 1;
        }
     
        for(int i = 1; i < s.length();++i){
            if(s[i] !='0'){
                dp[i+1] = dp[i];
            }
            if(s[i-1] == '1'){
                dp[i+1] += dp[i-1];
            }
            else if(s[i-1] == '2' && (s[i]>='0' && s[i]<='6')){
                dp[i+1] += dp[i-1];

            }
           
     
            cout<<dp[i+1]<<endl;
  
        }
        return dp[s.length()];
    }
};