class Solution {
  
    bool subsetSum(vector<int>& arr,int n,int sum){
        
        vector<vector<bool>> ans(n+1,vector<bool>(sum+1));
        
        for(int i = 0; i < n+1;i++){
            for(int j = 0; j < sum+1;j++){
                if(i == 0) ans[i][j] = false;
                
                if(j == 0) ans[i][j] = true;
            }
        }
        
        for(int i = 1; i < n+1;i++){
            for(int j = 1;j < sum+1;j++){
                if(arr[i-1] <= j){
                    ans[i][j] = ans[i-1][j - arr[i-1]] || ans[i-1][j];
                }
                else{
                    ans[i][j] = ans[i-1][j];
                }
            }
        }
        
        return ans[n][sum];
    }


  public:
    bool equalPartition(vector<int>& arr) {
       
        int maxSum = 0;
        int n = arr.size();
        
        for(int i = 0; i < n;i++){
            maxSum += arr[i];
        }
        
        if(maxSum % 2 == 0){
            return subsetSum(arr,n,maxSum/2);
        }
        else{
            return false;
        }
    }
};