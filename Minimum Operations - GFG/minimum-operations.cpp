//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int countStep(int i,int n,vector<int>& dp){
        if(i>n) return 1e8;
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        //cout<<i<<endl;
        int sum = 1+countStep(i+1,n,dp);
        int mul = 1+countStep(i*2,n,dp);
        
        return dp[i]=min(sum,mul);
    }
    int minOperation(int n)
    {
        //if(n==1) return 1;
        // vector<int> dp(n+1,-1);
        // return 1+countStep(1,n,dp);
        int count=0;
        while(n!=1){
            if(n%2==0){
                n=n/2;
                count++;
            }else{
                n=n-1;
                count++;
            }
        }
        return count+1;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends