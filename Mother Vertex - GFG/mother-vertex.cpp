//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void findAns(vector<int> adj[],vector<bool>& vis,int node){
        vis[node]=true;
        // count++;
        for(int x:adj[node]){
            if(vis[x]==false) findAns(adj,vis,x);
        }
        return;
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    int ans=0;
	    vector<bool> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	        findAns(adj,vis,i);
	        ans=i;
	        }
	    }
	    vector<bool> visi(V,0);
	    findAns(adj,visi,ans);
	    for(int i=0;i<V;i++){
	        if(visi[i]==0) return -1;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends