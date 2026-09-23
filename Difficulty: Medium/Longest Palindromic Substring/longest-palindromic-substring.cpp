class Solution {
    
    private:
    
    bool isPalindrome(string s){
        int st = 0;
        int e = s.length()-1;
        
        while(st < e){
            if(s[st] != s[e]) return false;
            
            st++;
            e--;
        }
        
        return true;
    }
	
	public:
	string getLongestPal(string &s) {
		
		string revStr = s;
		reverse(revStr.begin(), revStr.end());
		
		int l = s.length();
		
		int maxLength = 0;
		int st = 0;
		
		vector<vector<int>> ans(l + 1, vector<int>(l + 1));
		
		for (int i = 0; i < l + 1; i++) {
			for (int j = 0; j < l + 1; j++) {
				if (i == 0 || j == 0) {
					ans[i][j] = 0;
				}
			}
		}
		
		for (int i = 1; i < l + 1; i++) {
			for (int j = 1; j < l + 1; j++) {
				if (s[i - 1] == revStr[j - 1]) {
					ans[i][j] = 1 + ans[i - 1][j - 1];
					
					if (ans[i][j] > maxLength) {
						
						if (isPalindrome(s.substr(i-ans[i][j], ans[i][j]))) {
							maxLength = ans[i][j];
							st = i-ans[i][j];
						}
					}
				}
				else {
					ans[i][j] = 0;
				}
			}
		}
		
		return s.substr(st, maxLength);
		
	}
};
