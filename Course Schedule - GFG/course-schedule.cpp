//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int numCourses, int m, vector<vector<int>> prerequisites) 
    {
                vector<int> ans;
        // if(prerequisites.size()==0) return true;
        vector<int> adj[numCourses];
        vector<int> in(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            in[prerequisites[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0){
                q.push(i);
                // ans.push()
            }
        }
        // if(q.size()==0) return false;
        vector<int> vis(numCourses,0);
        while(!q.empty()){
            int x=q.front();
            vis[x]=1;
            ans.push_back(x);
            q.pop();
            for(int it:adj[x]){
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]) return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends