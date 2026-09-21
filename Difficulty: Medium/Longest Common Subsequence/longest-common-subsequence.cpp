class Solution {
  public:
    int lcs(string &s1, string &s2) {
        int size1 = s1.length();
        int size2 = s2.length();
        vector<vector<int>> ans(size1+1,vector<int>(size2+1));
        
        
        for(int i = 0 ; i < size1+1;i++){
            for(int j = 0; j < size2+1;j++){
                if(i == 0 || j == 0){
                    ans[i][j] = 0;
                }
            }
        }
        
        
        for(int i = 1; i < size1+1;i++){
            for(int j = 1;j < size2+1;j++){
                if(s1[i-1] == s2[j-1]){
                    ans[i][j] = 1 + ans[i-1][j-1]; 
                }
                else{
                    ans[i][j] = max(ans[i-1][j],ans[i][j-1]);
                }
            }
        }
        
        return ans[size1][size2];
        
    }
};
