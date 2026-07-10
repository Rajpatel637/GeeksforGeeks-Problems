class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n = arr.size();
        
        int prev1 = arr[0];
        int prev2 = 0;
        
        for(int i = 1 ; i < n;i++){
            int inc = prev2 + arr[i];
            int exc = prev1 ;
            
            int ans = max(inc,exc);
            
            prev2 = prev1 ;
            prev1 = ans;
        }
        
        return prev1;
        
    }
};