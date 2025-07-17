// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to build the tree from given inorder and preorder traversals
    int Find(vector<int>inorder,int target ,int InStart,int InEnd){
        for(int i = InStart;i<=InEnd;i++){
            if(inorder[i]==target)
            return i;
        }
        return -1;
    }
    Node* Tree(vector<int>inorder, vector<int>preorder,int InStart,int InEnd,int &index){
        if(InStart>InEnd) return NULL;
        
        Node* root = new Node(preorder[index]);
        int pos = Find(inorder,preorder[index],InStart,InEnd);
        index++;
        root->left= Tree(inorder,preorder,InStart,pos-1,index);
        root->right = Tree(inorder,preorder,pos+1,InEnd,index);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int n = preorder.size();
        int index = 0;
       return Tree(inorder,preorder,0,n-1,index);
    }
};