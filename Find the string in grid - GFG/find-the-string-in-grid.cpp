//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int dx[8]={0,-1,0,1,-1,1,-1,1};
    int dy[8]={-1,0,1,0,-1,1,1,-1};
    bool findWord(string word,int i,int j,vector<vector<char>>grid,int pos,int n,int m){
        if(pos>=word.size()) return true;
        // int k=0;
        for(int k=0;k<8;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==word[pos]){
                int g=pos+1;
                while(g!=word.size()){
                    int xx = x+dx[k];
                    int yy = y+dy[k];
                    if(xx>=0 && yy>=0 && xx<n && yy<m && grid[xx][yy]==word[g]){
                        g++;
                        x=xx;
                        y=yy;
                    }else{
                        break;
                    }
                }
                if(g>=word.size()) return true;
            }
        }
        return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    vector<vector<int>> ans;
	    int n=grid.size();
	    int m=grid[0].size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==word[0]){
	                if(findWord(word,i,j,grid,1,n,m)){
	                    ans.push_back({i,j});
	                }
	            }
	        }
	    }
	    sort(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends