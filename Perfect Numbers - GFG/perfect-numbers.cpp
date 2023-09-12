//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        long long ans=0;
        int sq = sqrt(N);
        for(int i=1;i<=sq;i++){
            if(N%i==0 && N!=1){
                ans+=i;
                if(i!=1) ans+=N/i;
            }
        }
        return (ans==N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends