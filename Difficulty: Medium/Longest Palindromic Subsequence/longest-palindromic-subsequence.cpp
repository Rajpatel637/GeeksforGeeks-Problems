class Solution {
	private:
	
	int lcs(string &s1, string &s2) {
		int l1 = s1.length();
		int l2 = s2.length();
		
		vector<vector<int>> ans(l1 + 1, vector<int>(l2 + 1));
		
		for (int i = 0; i < l1 + 1; i++) {
			for (int j = 0; j < l2 + 1; j++) {
				if (i == 0 || j == 0) {
					ans[i][j] = 0;
				}
			}
		}
		
		for (int i = 1; i < l1 + 1; i++) {
			for (int j = 1; j < l2 + 1; j++) {
				if (s1[i - 1] == s2[j - 1]) {
					ans[i][j] = 1 + ans[i - 1][j - 1];
				}
				else {
					ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
				}
			}
		}
		
		return ans[l1][l2];
	}
	
	public:
	int longestPalinSubseq(string &s) {
	     string revStr = s;
	     
	     reverse(revStr.begin(),revStr.end());
	     
	     return lcs(s,revStr);
	}
};
