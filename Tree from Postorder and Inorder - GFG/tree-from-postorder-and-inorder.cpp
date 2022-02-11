// { Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/


unordered_map<int,int>mp;
Node * temp(int in[], int post[], int start, int end, int &rootIndx){
    if(start>end) return nullptr;
    int i= mp[post[rootIndx]];
    Node* curr= new Node(in[i]);
    rootIndx--;
    if(start==end) return curr;
    curr->right=temp(in, post, i+1, end, rootIndx );
    curr->left=temp(in, post, start, i-1, rootIndx);
    return curr;
}


//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    for(int i=0;i<n;i++){
        mp[in[i]]=i;
    }
    int rootIndx=n-1;
    return temp(in, post, 0,n-1,rootIndx );
}
