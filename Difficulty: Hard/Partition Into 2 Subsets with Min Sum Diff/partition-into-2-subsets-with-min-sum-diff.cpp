class Solution {
	private:
	
	vector<int> subsetVec(vector<int>& arr, int n, int sum) {
		vector<vector<bool>> ans(n + 1, vector<bool>(sum + 1));
		
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < sum + 1; j++) {
				if (i == 0)
					ans[i][j] = false;
				
				if (j == 0)
					ans[i][j] = true;
			}
		}
		
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < sum + 1; j++) {
				if (arr[i - 1] <= j) {
					ans[i][j] = ans[i - 1][j - arr[i - 1]] || ans[i - 1][j];
				}
				else {
					ans[i][j] = ans[i - 1][j];
				}
			}
		}
		
		vector<int> temp;
		
		for(int i = 0; i <= sum/2;i++){
		    if(ans[n][i]){
		        temp.push_back(i);
		    }
		}
		
		return temp;
	}
	
	public:
	int minDifference(vector<int>& arr) {
		
		int maxSum = 0;
		
		int n = arr.size();
		
		for(int i = 0; i < n; i++){
		    maxSum += arr[i];
		}
		
		vector<int> ans = subsetVec(arr,n,maxSum);
		
		int minDiff = INT_MAX;
		
		for(int i = 0; i < ans.size();i++){
		    int diff = abs(maxSum - 2*ans[i]);
		    minDiff = min(diff,minDiff);
		}
		return minDiff;
	}
};
