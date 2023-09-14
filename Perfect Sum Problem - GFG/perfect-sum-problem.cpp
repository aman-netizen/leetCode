//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod=1e9+7;
	int findElements(int arr[],int sum,int i,vector<vector<int>> &dp){
	   // if(sum==0) return 1;
	   // if(sum<0) return 0;
	    if(i==0){
	        if(sum==0 && arr[i]==0) return 2;
	        if(sum==arr[i]||sum==0) return 1;
	        else return 0;
	    }
	    if(dp[i][sum]!=-1) return dp[i][sum];
	    int not_take = findElements(arr,sum,i-1,dp);
	    int take=0;
	    if(sum>=arr[i]){
	        take=findElements(arr,sum-arr[i],i-1,dp);
	    }
	    
	    return dp[i][sum]=(not_take+take)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return findElements(arr,sum,n-1,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends