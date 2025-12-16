#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
template <typename T>
class DoublyNode
{
public:
    T data;
    DoublyNode<T> *next;
    DoublyNode<T> *previous; // <--- YEH POINTER ZAROORI HAI

    // Constructor
    explicit DoublyNode(T value)
        : data(value), next(nullptr), previous(nullptr)
    {
    }

    // YEH DO FUNCTIONS ADD KARO (agar nahi hain to)
    DoublyNode<T> *getPrevious() const
    {
        return previous;
    }

    void setPrevious(DoublyNode<T> *prev)
    {
        previous = prev;
    }

    // Optional but good practice – next ke liye bhi
    DoublyNode<T> *getNext() const
    {
        return next;
    }

    void setNext(DoublyNode<T> *n)
    {
        next = n;
    }
    T getData()
    {
        return data;
    }
};

template<typename T>

class List
{
private:
    //--------------------------private class attributes:------------------------

    DoublyNode<T> *head;
    DoublyNode<T> *tail;
    int count;

public:
    //----------------------- private class attributes:----------------------------
    // Default constructor
    List()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    // parametarized constructor:
    List(DoublyNode<T> *h, DoublyNode<T> *t)
    {
        head = h;
        tail = t;
        count = 0;
    }

    // Destructor:
    ~List()
    {
        DoublyNode<T> *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->getNext();
            delete temp;
        }
    }
  
    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        else
            return false;
    }
    void append(T data)
    {
        if (isEmpty() == true)
        {
            DoublyNode<T> *app = new DoublyNode<T>(data);
            head = app;
            tail = app;
            cout << "while first add:" << endl;
            count++;
        }
        else
        {
            DoublyNode<T> *app = new DoublyNode<T>(data);
            // cout << "after the 1st node:" << endl;
            //  cout << tail->getPrevious() << endl;

            app->setPrevious(tail);
            tail->setNext(app);
            tail = app;
            count++;
            // cout << "append new at the last:" << endl;
        }
    }
    void prepend(T data)
    {
        if (isEmpty() == true)
        {
            DoublyNode<T> *prep = new DoublyNode<T>(data);
            head = prep;
            tail = prep;
            cout << "while first add:" << endl;
            count++;
        }
        else
        {
            DoublyNode<T> *prep = new DoublyNode<T>(data);
            prep->setNext(head);
            head->setPrevious(prep);

            head = prep;
            // head->setPrevious(nullptr);
            count++;
        }
    }
    void insertAtIndex(T data, int index)
    {

        if (index < 0 || index > count)
        {
            return;
        }
        else if (isEmpty() == true)
        {
            DoublyNode<T> *temp = new DoublyNode<T>(data);
            head = temp;
            tail = temp;
            count++;
            return;
        }
        else if (index == 0)
        {
            prepend(data);
            return;
        }
        else if (index == count)
        {
            append(data);
            return;
        }
        else
        {
            DoublyNode<T> *temp1 = new DoublyNode<T>(data);

            DoublyNode<T> *start = head;
            int ind = 0;
            while (ind < index - 1)
            {
                cout << "chexk the current index" << ind << endl;
                start = start->getNext();
                ind++;
            }
            DoublyNode<T> *A = start->getNext(); // node at index:
            start->setNext(temp1);
            temp1->setPrevious(start); // previous of temp
            temp1->setNext(A);
            A->setPrevious(temp1); // set previous of indexed node
            count++;
        }
    }

    void deleteFromEnd()
    {
        if (isEmpty() == true)
        {
            cout << "the Linked list is Empty:" << endl;
            return;
        }
        else
        {
            DoublyNode<T> *del = tail;

            if (head == tail)
            {
                tail = nullptr;
                head = nullptr;
            }
            else
            {
                tail = tail->getPrevious();
                tail->setNext(nullptr);
            }

            del->setPrevious(nullptr);

            delete del;
            count--;
        }
    }
    void deleteFromStart()
    {
        if (isEmpty() == true)
        {
            cout << "the Linked list is Empty:" << endl;
            return;
        }
        else
        {
            DoublyNode<T> *del = head;

            if (head == tail)
            {
                tail = nullptr;
                head = nullptr;
            }

            else
            {
                head = head->getNext(); // next of head:

                head->setPrevious(nullptr);
            }
            del->setNext(nullptr);
            delete del;
            count--;
        }
    }

    void deleteFromIndex(int index)
    {
        if (isEmpty() == true)
        {
            cout << "the Linked list is Empty:" << endl;
            return;
        }
        else if (index < 0 || index >= count)
        {
            return;
        }
        else if (index == 0)
        {
            deleteFromStart();
            return;
        }
        else if (index == count - 1)
        {
            deleteFromEnd();
            return;
        }
        else
        {

            DoublyNode<T> *start = head;
            int ind = 0;

            while (ind < index - 1)
            {
                // cout << "chexk the current index" << ind << endl;
                start = start->getNext();
                ind++;
            }

            DoublyNode<T> *A = start->getNext(); // index current DoublyNode<T>:
            DoublyNode<T> *Z = A->getNext();     // pointer of next:

            start->setNext(Z);
            Z->setPrevious(start);
            delete A;
            count--;
        }
    }
    void printList()
    {
        DoublyNode<T> *temp = head;
        while (temp != nullptr)
        {
            // cout << "print the new 1:" << endl;
            cout << temp->getData() << " ";
            // cout << "print the new 2:" << endl;
            temp = temp->getNext();
            // cout << "print the new:" << endl;
        }
    }
    DoublyNode<T> *getHead()
    {
        return head;
    }
    DoublyNode<T> *getTail()
    {
        return tail;
    }

    int getCount()
    {
        return count;
    }
};

#endif
