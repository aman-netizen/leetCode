//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
    Node* reverse_list(Node* root){
        Node* prev=NULL;
        Node* curr=root;
        while(curr!=NULL){
            Node* nexxt = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nexxt;
        }
        return prev;
    }
    void rearrange(struct Node *odd)
    {
        //add code here
        if(odd==NULL || odd->next==NULL) return;
        Node* first1 = odd;
        Node* second1 = odd->next;
        Node* first = first1;
        Node* second = second1;
        Node* curr=second->next;
        int i=0;
        while(curr!=NULL){
            if(i%2==0){
                first->next=curr;
                first=first->next;
            }else{
                second->next=curr;
                second=second->next;
            }
            i++;
            curr=curr->next;
        }
        //first->next=NULL;
        second->next=NULL;
        second1 = reverse_list(second1);
        first->next=second1;
        // return first1;
        odd=first1;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends