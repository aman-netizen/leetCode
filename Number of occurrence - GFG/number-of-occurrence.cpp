//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int low_bound(int arr[],int n,int x){
	    int low=0;
	    int high=n-1;
	    int ans=-1;
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(arr[mid]==x){
	            high=mid-1;
	            ans=mid;
	        }
	        else if(arr[mid]<x){
	            low=mid+1;
	        }else{
	            high=mid-1;
	        }
	    }
	    return ans;
	}
	int high_bound(int arr[],int n,int x){
	    int low=0;
	    int high=n-1;
	    int ans=-1;
	    while(low<=high){
	        int mid=(low+high)/2;
	        if(arr[mid]==x){
	            low=mid+1;
	            ans=mid;
	        }
	        else if(arr[mid]<x){
	            low=mid+1;
	        }else{
	            high=mid-1;
	        }
	    }
	    return ans;
	}
	int count(int arr[], int n, int x) {
	    // code here
	    int high=high_bound(arr,n,x);
	    int low=low_bound(arr,n,x);
	    if(low==-1) return 0;
	    return high-low+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends