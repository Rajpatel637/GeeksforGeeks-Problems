bool isSafe(vector < vector < int >> & arr,vector<vector<int>>& visited,int x,int y,int n){
    if((x >= 0 && x <= n-1 ) && (y >= 0 && y <= n-1) && (visited[x][y] == 0) && (arr[x][y] == 1)){
        return true;
    }
    else{
        return false;
    }
}

void getDir(vector < vector < int >> & arr,vector<string>& ans,vector<vector<int>>& visited,string& path,int n,int x,int y){

    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // down

    int newx = x+1;
    int newy = y;
    if(isSafe(arr,visited,newx,newy,n)){
        path.push_back('D');
        getDir(arr,ans,visited,path,n,newx,newy);
        path.pop_back();
    }

    // right 
    newx = x;
    newy = y+1;
    if(isSafe(arr,visited,newx,newy,n)){
        path.push_back('R');
        getDir(arr,ans,visited,path,n,newx,newy);
        path.pop_back();
    }
    
    // left

    newx = x;
    newy = y-1;

    if(isSafe(arr,visited,newx,newy,n)){
        path.push_back('L');
        getDir(arr,ans,visited,path,n,newx,newy);
        path.pop_back();
    }

    // up

    newx = x-1;
    newy = y;

    if(isSafe(arr,visited,newx,newy,n)){
        path.push_back('U');
        getDir(arr,ans,visited,path,n,newx,newy);
        path.pop_back();
    } 

    visited[x][y] = 0;
}


class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
    vector<string> ans;
    int n = maze.size();

    if(maze[0][0] == 0) return ans;
    

    vector<vector<int>> visited = maze;
    int srcx = 0;
    int srcy = 0;

    for(int i = 0; i < n;i++){
        for(int j = 0; j < n;j++){
            visited[i][j] = 0;
        }
    }

    string path = "";
    getDir(maze,ans,visited,path,n,srcx,srcy);
    sort(ans.begin(),ans.end());
    
    return ans;

        
    }
};