class Solution {
public:
    //create dp vector of size amount
    // dp[i] = lowest number of coins to get amount i
    //either we use the biggest elemeent, subtract it from amount, recursively call func
    //or we dont use biggest elem, recursively call func without that coin 
    
    //loop over all coins and remove the current coin amount from amount and calculate the remaining optimal num of coins, return min of this
    //if subtracting coin amount makes amount neg, return -1
    //else if subtracting coin amount makes amount 0, return 0
    int coinChange(vector<int>& coins, int amount) {
                
     
        vector<int> dp;
        dp.resize(amount+1);
        return getOutput(coins,amount,dp);
        
    }
    int getOutput(vector<int>& coins, int amount, vector<int>& dp){
             int mincoins = INT_MAX;
        if(amount <0){
            return -1;
        }
        else if(amount ==0){
            return 0;
        }
        else if(dp[amount] !=0){
            return dp[amount];
        }
        else{
       
            for(int i = 0 ; i < coins.size();++i){
                int rem = amount - coins[i]; 
                int curr_numcoins = getOutput(coins,rem,dp);
                if(curr_numcoins>=0 && curr_numcoins < mincoins){
                    mincoins = curr_numcoins+1; 
                }
            }
        }
        dp[amount] = (mincoins == INT_MAX)?-1:mincoins;
        return dp[amount];
    }

};