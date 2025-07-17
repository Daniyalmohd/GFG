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

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    int Find(vector<int> inorder,int target,int start,int end){
        for(int i = start;i<=end;i++){
            if(inorder[i]==target) return i;
        }
        return -1;
    }
    Node* Tree(vector<int> inorder, vector<int> postorder,int InStart,int InEnd,int &index){
        
        if(InStart>InEnd) return NULL;
        Node *root= new Node(postorder[index]);
        int pos = Find(inorder,postorder[index],InStart,InEnd);
        index--;
        root->right = Tree(inorder,postorder,pos+1,InEnd,index);
        root->left = Tree(inorder,postorder,InStart,pos-1,index);
        return root;
    }
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here
        int index = postorder.size()-1;
        int n = postorder.size();
        return Tree(inorder,postorder,0,n-1,index);
    }
};