#ifndef TREENODE_H
#define TREENODE_H

#include<iostream>
using namespace std;

template<typename T>
class TreeNode
{
    // Data Members :
    private:
    T data;        
    TreeNode *left;
    TreeNode *right;

public:
    // -------------implementation of TreeNode class-------------

    TreeNode(T value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
    TreeNode *getLeftChild()
    {
        return left;
    }
    TreeNode *getRightChild()
    {
        return right;
    }
    T getData()
    {
        return data;
    }
   // void TreeNode:: setData(int val)
   // {
   //     data = val;
   // }
    void addLeftChild(TreeNode *node)
    {
        this->left = node;
    }
    void addRightChild(TreeNode *node)
    {
        this->right = node;
    }
};


#endif  