class Solution {
	public:
	bool isSubsetSum(vector<int>& arr, int sum) {
		vector<vector<bool>> ans(arr.size() + 1, vector<bool>(sum + 1));
		
		int n = arr.size()+1;
		
		for(int i = 0; i < n;i++){
		    for(int j = 0; j < sum+1;j++){
		        if(i == 0){
		            ans[i][j] = false;
		        }
		        
		        if(j == 0){
		            ans[i][j] = true;
		        }
		    }
		}
		
		for(int i = 1; i < n;i++){
		    for(int j = 1; j < sum+1;j++){
		        if(arr[i-1] <= j){
		            ans[i][j] = ans[i-1][j-arr[i-1]] || ans[i-1][j];
		        }
		        else{
		            ans[i][j] = ans[i-1][j];
		        }
		    }
		}
		
		return ans[n-1][sum];
		
	}
};
