//
//  main.cpp
//  IterativeInorderTraversal
//
//  Created by adeeb mohammed on 25/04/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

/*
 {"id": "3", "left": "6", "right": "7", "value": 3},
 {"id": "4", "left": null, "right": "9", "value": 4},
 {"id": "6", "left": null, "right": null, "value": 6},
 {"id": "7", "left": null, "right": null, "value": 7},
 {"id": "9", "left": null, "right": null, "value": 9}
 
 time complexity of this algorithm is o(n)
 and space complexity is o(1)
 
 */


#include <iostream>
#include <vector>
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;

    BinaryTree(int value, BinaryTree *parent = NULL){
        this->value = value;
        this->right = NULL;
        this->left = NULL;
        this->parent = NULL;
    }
    void insert(std::vector<int> values, int i = 0){
        
    }
};

void displayValue(BinaryTree *tree){
    if (tree != NULL) {
        std::cout << tree->value << std::endl;
    }else{
        std::cout << "NULL-POINTER" << std::endl;
    }
}

void iterativeInOrderTraversal(BinaryTree *tree,
                               void (*callback)(BinaryTree *tree)) {
    BinaryTree *currentNode = tree;
    BinaryTree *prevNode = NULL;
    BinaryTree *nextNode = NULL;
    while (currentNode != NULL) {
        // it is the condition for iterating downward the left direction
        if(prevNode == NULL || prevNode == currentNode->parent){
            if (currentNode->left != NULL) {
                nextNode = currentNode->left;
            }else{
                // after the end of the sub tree we have to print the current node
                (*callback)(currentNode);
                nextNode = (currentNode->right != NULL)? currentNode->right : currentNode->parent;
            }
        // condition for iterating backwards the parent from the left root
        }else if(prevNode == currentNode->left){
            (*callback)(currentNode);
            nextNode = (currentNode->right != NULL)? currentNode->right : currentNode->parent;
        }else{
            nextNode = nextNode->parent;
        }
        prevNode = currentNode;
        currentNode = nextNode;
    }
}


int main(int argc, const char * argv[]) {
    std::cout << "Iterative Inodrder Traversal program "<< std::endl;
    BinaryTree *root = new BinaryTree(4);
    BinaryTree *childLeft = new BinaryTree(3);
    BinaryTree *childRight = new BinaryTree(2);
    childLeft->parent = root;
    childRight->parent = root;
    root->parent = NULL;
    root->left = childLeft;
    root->right = childRight;
    iterativeInOrderTraversal(root, &displayValue);
    delete childRight;
    delete childLeft;
    delete root;
    return 0;
}
