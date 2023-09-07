//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int mod=1e5;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end) return 0;
        queue<pair<int,int>> q;
        q.push({start,0});
        vector<bool> vis(100001,false);
        vis[start]=true;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(node==end) return steps;
            for(int x:arr){
                if(vis[(node*x)%mod]==false){
                    vis[(node*x)%mod]=true;
                    q.push({(node*x)%mod,steps+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends