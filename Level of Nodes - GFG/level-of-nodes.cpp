//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<int> q;
	    q.push(0);
	    vector<int> vis(V,0);
	    vis[0]=1;
	    int level = 0;
	    if(X==0) return 0;
	    while(!q.empty()){
	        int n=q.size();
	        for(int i=0;i<n;i++){
	            int curr = q.front();
	            q.pop();
	            for(auto it: adj[curr]){
	                if(vis[it]==0){
	                if(it==X) return level+1;
	                q.push(it);
	                vis[it]=1;
	                }
	            }
	        }
	        level++;
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends