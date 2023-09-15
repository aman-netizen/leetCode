//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPartition(int sum1,int sum2,int i,int arr[],vector<vector<int>>& dp){
        if(sum1==sum2) return 1;
        if(i<0){
            if(sum1==sum2) return 1;
            else return 0;
        }
        // if(sum1==)
        if(dp[i][sum1]!=-1) return dp[i][sum1];
        
        int not_take=isPartition(sum1,sum2,i-1,arr,dp);
        int take=0;
        if(arr[i]+sum1<=sum2){
            take=isPartition(sum1+arr[i],sum2,i-1,arr,dp);
        }
        
        return dp[i][sum1]=take|not_take;
        
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }
        if(sum%2!=0){
            return 0;
        }
        vector<vector<int>> dp(N,vector<int>(sum/2 +1, -1));
        return isPartition(0,sum/2,N-1,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends