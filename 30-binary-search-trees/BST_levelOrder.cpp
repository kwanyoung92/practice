#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }
	void levelOrder(Node * root){
      	//Write your code here
		queue<Node*> tree_queue;
		tree_queue.push(root);
		
		while(!tree_queue.empty()) {
			cout << tree_queue.front()->data << " ";
			if(tree_queue.front()->left != NULL)
				tree_queue.push(tree_queue.front()->left);
			if(tree_queue.front()->right != NULL)
				tree_queue.push(tree_queue.front()->right);
			tree_queue.pop();
		}
	}
};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}
