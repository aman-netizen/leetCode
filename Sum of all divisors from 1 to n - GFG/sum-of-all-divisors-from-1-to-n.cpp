//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        //vector<long long> divisors(N,0);
        // vector<int> isPrime(N+1,0);
        // for(int i=2;i*i<=N;i++){
        //     if(isPrime[i]==0){
        //     for(int j=i*i;j<=N;j=j+i){
        //         isPrime[j]=1;
        //     }
        //     }
        // }
        long long ans=0;
        for(int i=1;i<=N;i++){
            ans+=(N/i)*i;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends