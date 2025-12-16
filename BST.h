#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "TreeNode.h"
#include "queue.h"

template <typename T>
class Tree
{
private:
    TreeNode<T> *root;

public:
    Tree()
    {
        root = nullptr;
    }

    void insertNode(T value)
    {
        TreeNode<T> *app = new TreeNode<T>(value);

        if (root == nullptr)
        {
            root = app;
            return;
        }

        LinkedQueue<TreeNode<T> *> q;
        q.enqueue(root);

        while (!q.isEmpty())
        {
            TreeNode<T> *cur = q.dequeue();

            if (cur->getLeftChild() == nullptr)
            {
                cur->addLeftChild(app);
                return;
            }
            else
                q.enqueue(cur->getLeftChild());

            if (cur->getRightChild() == nullptr)
            {
                cur->addRightChild(app);
                return;
            }
            else
                q.enqueue(cur->getRightChild());
        }
    }

    // ---------------- HEIGHT ----------------
    int height(TreeNode<T> *node)
    {
        if (node == nullptr)
            return -1;

        int lh = height(node->getLeftChild());
        int rh = height(node->getRightChild());

        return 1 + max(lh, rh);
    }

    int getTreeHeight()
    {
        return height(root);
    }

    // ---------------- FIND NODE ----------------
    TreeNode<T> *findNode(T value)
    {
        if (root == nullptr)
            return nullptr;

        LinkedQueue<TreeNode<T> *> q;
        q.enqueue(root);

        while (!q.isEmpty())
        {
            TreeNode<T> *temp = q.dequeue();

            if (temp->getData() == value)
                return temp;

            if (temp->getLeftChild())
                q.enqueue(temp->getLeftChild());

            if (temp->getRightChild())
                q.enqueue(temp->getRightChild());
        }
        return nullptr;
    }

    TreeNode<T> *getRoot()
    {
        return root;
    }

    // ---------------- TRAVERSALS ----------------
    void preorderprint(TreeNode<T> *node)
    {
        if (node == nullptr)
            return;

        node->getData().show();
        cout << endl;

        preorderprint(node->getLeftChild());
        preorderprint(node->getRightChild());
    }

    void postorderprint(TreeNode<T> *node)
    {
        if (node == nullptr)
            return;

        postorderprint(node->getLeftChild());
        postorderprint(node->getRightChild());

        node->getData().show();
        cout << endl;
    }

    // ---------------- LEVEL ORDER ----------------
    void levelOrderTraversal()
    {
        if (root == nullptr)
            return;

        LinkedQueue<TreeNode<T> *> q;
        q.enqueue(root);

        while (!q.isEmpty())
        {
            TreeNode<T> *temp = q.dequeue();
            temp->getData().show();
            cout << endl;

            if (temp->getLeftChild())
                q.enqueue(temp->getLeftChild());

            if (temp->getRightChild())
                q.enqueue(temp->getRightChild());
        }
    }

    // ---------------- DELETE NODE ----------------
    void deleteNode(T value)
    {
        if (root == nullptr)
            return;

        LinkedQueue<TreeNode<T> *> q;
        q.enqueue(root);

        TreeNode<T> *target = nullptr;
        TreeNode<T> *last = nullptr;
        TreeNode<T> *parentOfLast = nullptr;

        while (!q.isEmpty())
        {
            TreeNode<T> *temp = q.dequeue();

            if (temp->getData() == value)
                target = temp;

            if (temp->getLeftChild())
            {
                parentOfLast = temp;
                q.enqueue(temp->getLeftChild());
            }

            if (temp->getRightChild())
            {
                parentOfLast = temp;
                q.enqueue(temp->getRightChild());
            }

            last = temp;
        }

        if (!target)
            return;

        target->setData(last->getData());

        if (parentOfLast)
        {
            if (parentOfLast->getLeftChild() == last)
                parentOfLast->addLeftChild(nullptr);
            else
                parentOfLast->addRightChild(nullptr);
        }
        else
            root = nullptr;

        delete last;
    }
};

#endif
