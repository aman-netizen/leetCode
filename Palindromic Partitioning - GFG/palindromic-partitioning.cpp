//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(int i,int j,string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int findMinCuts(int i,int n,string s,vector<int>& dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        int count=INT_MAX;
        for(int k=i;k<n;k++){
            if(isPalindrome(i,k,s)){
                int cost=1+findMinCuts(k+1,n,s,dp);
                count=min(count,cost);
            }
        }
        return dp[i]=count;
    }
    int palindromicPartition(string str)
    {
        int n=str.size();
        vector<int> dp(n,-1);
        return findMinCuts(0,n,str,dp)-1;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends