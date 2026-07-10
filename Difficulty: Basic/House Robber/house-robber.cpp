class Solution {
  public:
    int maximizeMoney(int N, int K) {
        
        int prev1 = K;
        int prev2 = 0;
        
        for(int i = 1;i < N;i++){
            int inc = prev2 + K;
            int exc = prev1;
            
            int ans = max(inc,exc);
            
            prev2 = prev1;
            prev1 = ans;
        }
        
        return prev1;
        
        
    }
};