class Solution {
    
    int subsetSumToK(int n, int k, vector<int> &arr) {
    
    vector<vector<int>> ans(n+1,vector<int>(k+1));

    for(int i = 0; i < n+1;i++){
        for(int j = 0; j < k+1;j++){
            if(i == 0){
                ans[i][j] = 0;
            }

            if(j == 0){
                ans[i][j] = 1;
            }
        }
    }
    

    for(int i = 1; i < n+1;i++){
        for(int j = 0; j < k+1;j++){
            if(arr[i-1] <= j){
                ans[i][j] = (ans[i-1][j-arr[i-1]] + ans[i-1][j]);
            }
            else{
                ans[i][j] = ans[i-1][j];
            }
        }
    }

    return ans[n][k];
}
    
  public:
    int perfectSum(vector<int>& arr, int target) {
        
        return subsetSumToK(arr.size(),target,arr);
        
    }
};