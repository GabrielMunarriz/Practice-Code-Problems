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


    int height(Node* root) {
        // Write your code here.
        
        if (root == nullptr) {
            
            //Null trees are given a height of -1 so that the leaves
            //will have a height of 0 (based on how the function is coded)
            
            return -1; 
            
        } else {
            
            int leftTreeHeight = height(root->left);
            int rightTreeHeight = height(root->right);
            
            if (leftTreeHeight > rightTreeHeight) {
                
                return leftTreeHeight + 1;
                
            } else {
                
                return rightTreeHeight + 1;
                
            }
            
        }
        
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
