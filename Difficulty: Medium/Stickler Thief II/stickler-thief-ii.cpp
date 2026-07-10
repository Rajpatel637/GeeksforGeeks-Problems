
int spaceOpti(vector<int>& arr){
    int n = arr.size();
        
        int prev1 = arr[0];
        int prev2 = 0;
        
        for(int i = 1 ; i < n;i++){
            int inc = prev2 + arr[i];
            int exc = prev1 ;
            
            int ans = max(inc,exc);
            
            prev2 = prev1 ;
            prev1 = ans;
        }
        
        return prev1;
}


class Solution {
  public:
    int maxValue(vector<int>& arr) {
        
        int n = arr.size();
        if(n == 1) return arr[0];
        
        vector<int> first,last;
        
        for(int i = 0; i < n;i++){
            if(i != 0) last.push_back(arr[i]);
            
            if(i != n-1) first.push_back(arr[i]);

        }
        
        return max(spaceOpti(first),spaceOpti(last));
    }
};
