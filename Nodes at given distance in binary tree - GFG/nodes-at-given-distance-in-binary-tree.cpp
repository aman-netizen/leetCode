//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    
    void findNum(Node* root,int x,int k,vector<int>& ans){
        if(root==NULL) return;
        if(x==k){
            ans.push_back(root->data);
        }
        
        findNum(root->left,x+1,k,ans);
        findNum(root->right,x+1,k,ans);
    }
    
    bool findTar(Node* root,int target,int& count,int k,vector<int>& ans){
        if(root==NULL){
            return false;
        }
        if(root->data==target){
            findNum(root,0,k,ans);
            return true;
        }
        
        bool left = findTar(root->left,target,count,k,ans);
        bool right = findTar(root->right,target,count,k,ans);
        
        if(left || right){
            count=count+1;
            if(count==k){
                ans.push_back(root->data);
            } 
            else if(left){
                findNum(root->right,count+1,k,ans);
            }else{
                findNum(root->left,count+1,k,ans);
            }
        }
        return left|right;
    }
    
    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // int count=0;
        // queue<Node*> q;
        // q.push(root);
        // Node* tar=NULL;
        // while(q.empty()==false){
        //     int n=q.size();
        //     bool isTarget = false;
        //     for(int i=0;i<n;i++){
        //         Node* curr = q.front();
        //         q.pop();
        //         if(curr->data==target){
        //             tar=curr;
        //             isTarget = true;
        //             break;
        //         }
        //         if(root->left)q.push(root->left);
        //         if(root->right)q.push(root->right);
        //     }
        //     if(isTarget) break;
        // }
        vector<int> ans;
        // if(tar==NULL) return ans;
        int count=0;
        findTar(root,target,count,k,ans);
        // findNum(tar,0,k,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends