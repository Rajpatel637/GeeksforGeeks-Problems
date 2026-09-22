class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int maxElement = arr[0];
        int secElement = -1;
        
        for(int i = 1;i < arr.size();i++){
            if(maxElement < arr[i]){
                secElement = maxElement;
                maxElement = arr[i];
            }
            else if(secElement < arr[i] && maxElement != arr[i]){
                secElement = arr[i];
            }
        }
        
        return secElement;
        
    }
};