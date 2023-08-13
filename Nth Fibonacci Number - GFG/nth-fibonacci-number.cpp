//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        int mod=1e9+7;
        if(n<=2){
            return 1;
        }
        int s1=1;
        int s2=1;
        // return s1;
        for(int i=3;i<=n;i++){
            int temp=s2;
            s2=(s2+s1)%mod;
            s1=temp;
        }
        return s2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends