class Solution {
  private: 
  
  void revArr(vector<int>& arr,int s,int e){
      while(s < e){
          swap(arr[s],arr[e]);
          s++;
          e--;
      }
  }
    
  public:
    void rotateArr(vector<int>& arr, int d) {
        
        int n = arr.size();
        
        d = d % n;
        revArr(arr,0,n-1);
        
        revArr(arr,0,n-d-1);
        
        revArr(arr,n-d,n-1);
        
        
    }
};