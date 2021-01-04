/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
	bool checkBST(Node* root) {
       return getOutput(root,0,10000);
           
            
    
	}
    bool getOutput(Node*root,int min, int max){
        if(!root){
            return true;
        }
        else if (root->data <= min || root->data >= max){
            return false;
        }
        else{
            return getOutput(root->left,min,root->data) && getOutput(root->right,root->data,max);
        }
//          
    }