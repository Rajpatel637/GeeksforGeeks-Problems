
int minNumCoins(vector<int> & coins,int sum){
    vector<int> dp(sum+1,INT_MAX);
    
    dp[0] = 0;
    
    for(int i = 1; i <= sum; i++){
        for(int j = 0; j < coins.size();j++){
            if(coins[j] <= i && dp[i-coins[j]] != INT_MAX){
                dp[i] = min(dp[i],dp[i-coins[j]] + 1);
            }
        }
    }
    
    if(dp[sum] == INT_MAX) return -1;
    
    return dp[sum];
}


class Solution {
  public:
    int minCoins(vector<int> &coins, int sum) {
        
        
        return minNumCoins(coins,sum);
        
    }
};