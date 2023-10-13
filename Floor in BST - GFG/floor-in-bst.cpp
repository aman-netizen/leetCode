//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};


// } Driver Code Ends
// Function to search a node in BST.
class Solution{

public:
    int helper(Node* root,int& ans,int x){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->data;
        
        int left=root->data;
        int right=root->data;
        
        if(x>root->data){
           if(root->right!=NULL) left=helper(root->right,ans,x);
        }else if(x<root->data){
           if(root->left!=NULL) right=helper(root->left,ans,x);
        }else{
            return root->data;
        }


        if((x-left)<=(x-right) && (x-left)>=0){
            return left;
        }else if((x-right)>=0){
            return right;
        }else{
            return -1;
        }
        return max(left,right);
    }
    int floor(Node* root, int x) {
        // Code here
        int ans=-1;
        return helper(root,ans,x);
        
    }
};

//{ Driver Code Starts.

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int s;
        cin >> s;
        Solution obj;
        cout << obj.floor(root, s) << "\n";
    }
}

// } Driver Code Ends