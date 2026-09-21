class Solution {
	public:
	int longCommSubstr(string& s1, string& s2) {
		int len1 = s1.length();
		int len2 = s2.length();
		int maxValue = 0;
		
		vector<vector<int>> ans(len1 + 1, vector<int>(len2 + 1));
		
		for (int i = 0; i < len1 + 1; i++) {
			for (int j = 0; j < len2 + 1; j++) {
				if (i == 0 || j == 0) {
					ans[i][j] = 0;
				}
			}
		}
		
		for (int i = 1; i < len1 + 1; i++) {
			for (int j = 1; j < len2 + 1; j++) {
				if (s1[i - 1] == s2[j - 1]) {
					ans[i][j] = 1 + ans[i - 1][j - 1];
				}
				else {
					ans[i][j] = 0;
				}
				maxValue = max(ans[i][j],maxValue);
			}
		}
		
		return maxValue;
		
	}
};
