//Back-end complete function Template for C++
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class Solution {
  public:
  int Findpe(int inorder[],int target ,int InStart,int InEnd){
        for(int i = InStart;i<=InEnd;i++){
            if(inorder[i]==target)
            return i;
        }
        return -1;
    }
   Node* Treepe(int inorder[], int preorder[],int InStart,int InEnd,int &index){
        if(InStart>InEnd) return NULL;
        
        Node* root = new Node(preorder[index]);
        int pos = Findpe(inorder,preorder[index],InStart,InEnd);
        index++;
          if(pos == -1){
            return NULL;
        }
        root->left= Treepe(inorder,preorder,InStart,pos-1,index);
        root->right = Treepe(inorder,preorder,pos+1,InEnd,index);
        return root;
    }
  int Findpo(int inorder[],int target,int start,int end){
        for(int i = start;i<=end;i++){
            if(inorder[i]==target) return i;
        }
        return -1;
    }
    Node* Treepo(int inorder[], int postorder[],int InStart,int InEnd,int &index){
        
        if(InStart>InEnd) return NULL;
        Node *root= new Node(postorder[index]);
        int pos = Findpo(inorder,postorder[index],InStart,InEnd);
        if(pos == -1){
            return NULL;
        }
        index--;
        root->right = Treepo(inorder,postorder,pos+1,InEnd,index);
        root->left = Treepo(inorder,postorder,InStart,pos-1,index);
        return root;
    }
    bool IsSame(Node*root1,Node*root2){
        if(!root1 && !root2)
            return 1;
        
        else if(!root1 || !root2) return 0;
        else
         return (root1->data == root2->data) &&  IsSame(root1->left,root2->left) &&  IsSame(root1->right, root2->right);
    }
    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        // Your code goes hereint index = postorder.size()-1;
        int indexpe = 0;
        int indexpo = N-1;
 
        Node *root1 = Treepo(inorder, postorder, 0,N-1,indexpo);
        Node *root2 = Treepe(inorder, preorder, 0,N-1,indexpe);
        bool ans = IsSame(root1,root2);
        return ans;
    }
};
