class Solution {
  public:
    int longestRepSubseq(string &s) {
        string s2 = s;
        
        int l = s.length();
        
        vector<vector<int>> ans(l+1,vector<int>(l+1));
        
        for(int i = 0; i < l+1;i++){
            for(int j = 0; j < l+1;j++){
                if(i == 0|| j == 0){
                    ans[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < l+1;i++){
            for(int j = 1; j < l+1;j++){
                if(s[i-1] == s2[j-1] && i != j){
                    ans[i][j] = 1 + ans[i-1][j-1];
                }
                else{
                    ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
                }
            }
        }
        
        return ans[l][l];
        
        
    }
};