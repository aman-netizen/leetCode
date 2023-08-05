//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void findPermutations(int i,vector<string>& ans,int n,string S){
        if(i==n-1){
            ans.push_back(S);
            return;
        }
        
        for(int j=i;j<n;j++){
            swap(S[i],S[j]);
            findPermutations(i+1,ans,n,S);
            swap(S[i],S[j]);
        }
    }
    
    vector<string> permutation(string S)
    {
        vector<string> ans;
        findPermutations(0,ans,S.size(),S);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends