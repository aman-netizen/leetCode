//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int findVal(int i,int W,int val[],int wt[],vector<vector<int>>& dp){
        if(W==0) return 0;
        // if(i==0) {
        //     if(wt[i]<=W) return val[i];
        //     else return 0;
        // }
        
        if(i<0) return 0;
        
        if(dp[i][W]!=-1) return dp[i][W];
        
        int not_take = findVal(i-1,W,val,wt,dp);
        int take = 0;
        if(wt[i]<=W){
            take = val[i]+findVal(i,W-wt[i],val,wt,dp);
        }
        
        return dp[i][W]=max(take,not_take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return findVal(N-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends