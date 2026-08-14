class Solution {
	private:
	int maxWays(vector<int>& denominations, int n, int value) {
		vector<vector<int>> ans(n + 1, vector<int>(value + 1));
		
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < value + 1; j++) {
				if (i == 0)
					ans[i][j] = 0;
				
				if (j == 0)
					ans[i][j] = 1;
			}
		}
		
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < value + 1; j++) {
				if (denominations[i - 1] <= j) {
					ans[i][j] = ans[i - 1][j] + ans[i][j - denominations[i - 1]];
				}
				else {
					ans[i][j] = ans[i - 1][j];
				}
			}
		}
		
		return ans[n][value];
	}
	
	public:
	int count(vector<int>& coins, int sum) {
		int n = coins.size();
		
		return maxWays(coins,n,sum);
	}
};
