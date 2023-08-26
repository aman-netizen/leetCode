//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int K) {
        unordered_map<char,int> mp;
        int ans=-1;
        int st=0;
        int end=0;
        int n=s.length();
        while(mp.size()<K && end<n){
            mp[s[end]]++;
            end++;
        }
        if(mp.size()==K) ans=max(ans,end-st);
        while(end<n){
            while(mp.size()>K && st<end){
                mp[s[st]]--;
                if(mp[s[st]]==0){
                    mp.erase(s[st]);
                }
                st++;
            }
            if(mp.size()==K) ans=max(ans,end-st);
            mp[s[end]]++;
            end++;
        }
        if(mp.size()==K) ans=max(ans,end-st);
        // if(ans==0)
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends