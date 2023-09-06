#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/  
    int heightPlusOne(Node* root) {
         
        //This code returns height + 1 BECAUSE while we want 
        //each node's height to be calculated by the height of the larger
        //subtree plus one (which is either left or right), the same 
        //calculation is done for the LEAVES, which shouldn't be the case
        //(The height of a leaf is 0. What this code ends up doing is that it
        //takes the height of 2 null trees, which returns 0 based on the code,
        //compares them then adds 1, making the height of the leaf 1.)
        
        if (root == nullptr) {
            
            return 0;
            
        } else {
            
            int leftTreeHeight = heightPlusOne(root->left);
            int rightTreeHeight = heightPlusOne(root->right);
            
            if (leftTreeHeight > rightTreeHeight) {
                
                return leftTreeHeight + 1;
                
            } else {
                
                return rightTreeHeight + 1;
                
            }
            
        }
        
    }

    int height(Node* root) {
        // Write your code here.
        //My workaround is to create a recursive function via heightPlusOne
        //which calculates the height but overdoes it so that there's a plus
        //one because of the leaf thing, then this main height function just
        //subtracts one from the final result.
        
        //std::cout << "heightPlusOne(root): " << heightPlusOne(root) << std::endl;
        
        return heightPlusOne(root) - 1;
        
    }

}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    int height = myTree.height(root);
    std::cout << height;

    return 0;
}
