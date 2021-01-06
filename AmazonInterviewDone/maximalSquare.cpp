class Solution {
public:
   int maximalSquare(vector<vector<char>>& matrix) {
       //dp matrix: same size as matrix
       vector<vector<int>> dp; 
       int s = matrix.size();
       dp.resize(s);
       
       int max = 0;
       dp[0].resize(matrix[0].size());
       if(matrix.size() >= 1){
           dp[0][0] = matrix[0][0]-'0';
           for(int i = 0 ; i < matrix[0].size();++i){
               if(matrix[0][i] == '1'){
                   max = 1;
               }
           }
       }
       
       for(int i = 1; i < s; ++i){
           int l = matrix[i].size(); 
            
           dp[i].resize(l);
           dp[i][0] = matrix[i][0]-'0';
           if(dp[i][0]>max){
                       max = dp[i][0];
                   }
           for(int j = 1; j < l; ++j ){
            
               dp[0][j] = matrix[0][j]-'0';
                if(dp[0][j]>max){
                       max = dp[0][j];
                   }
               if(matrix[i][j] == '1'){
                
                   dp[i][j] = 1 + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                   if(dp[i][j]>max){
                       max = dp[i][j];
                   }
               }
           }
       }
       return max*max;
       
    
    }
};