#include <iostream>
#include <string>
using namespace std;
template <typename T>
class TreeNode {
private:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
public:
    TreeNode(T value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }

    TreeNode<T>* getLeftChild() { return left; }
    TreeNode<T>* getRightChild() { return right; }
    T getData() { return data; }

    void addLeftChild(TreeNode<T>* node) { left = node; }
    void addRightChild(TreeNode<T>* node) { right = node; }
};


template <typename T>
class QNode {
public:
    T data;
    QNode<T>* next;

    QNode(T d) {
        data = d;
        next = nullptr;
    }
};

template <typename T>
class LinkedQueue {
private:
    QNode<T>* front;
    QNode<T>* rear;
    int size;
public:
    LinkedQueue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    ~LinkedQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    void enqueue(T data) {
        QNode<T>* newNode = new QNode<T>(data);
        if (isEmpty()) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue empty\n";
            return nullptr;
        }
        QNode<T>* delNode = front;
        T delData = front->data;
        front = front->next;
        delete delNode;
        size--;
        if (front == nullptr)
            rear = nullptr;
        return delData;
    }

    int getSize() { return size; }
};


template <typename T>
class Tree {
private:
    TreeNode<T>* root;
public:
    Tree() {
        root = nullptr;
    }

    TreeNode<T>* getRoot() {
        return root;
    }
    int maxH(int n1, int n2) {
        if (n1 > n2) {
            return n1;
        }
        else {
            return n2;
        }
    }

    int heightHelper(TreeNode<T>* node) {
        if (node == nullptr) return -1;
        int leftH = heightHelper(node->getLeftChild());
        int rightH = heightHelper(node->getRightChild());
        return 1 + maxH(leftH, rightH);
    }
    void insertNode(T value) {
        TreeNode<T>* newN = new TreeNode<T>(value);
        if (root == nullptr) {
            root = newN;
            return;
        }

        LinkedQueue<TreeNode<T>*> que;
        que.enqueue(root);
        while (!que.isEmpty()) {
            TreeNode<T>* curr = que.dequeue();
            if (curr->getLeftChild() == nullptr) {
                curr->addLeftChild(newN);
                return;
            }
            else {
                que.enqueue(curr->getLeftChild());
            }
            if (curr->getRightChild() == nullptr) {
                curr->addRightChild(newN);
                return;
            }
            else {
                que.enqueue(curr->getRightChild());
            }
        }
    }

   
    void printInorderHelper(TreeNode<T>* node) {
        if (node == nullptr) return;
        printInorderHelper(node->getLeftChild());
        cout << node->getData()->getTitle() << " ";
        printInorderHelper(node->getRightChild());
    }
   
    void printInorder() {
        printInorderHelper(root);
         cout << endl;
    }
    int getTreeHeight() {
        return heightHelper(root);
    }
};
