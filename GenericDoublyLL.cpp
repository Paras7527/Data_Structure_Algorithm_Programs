#include <iostream>
using namespace std;
template <class T>
struct node
{
    T data;
    struct node *next;
    struct node *prev;
};
template <class T>
class DoublyLL
{
public:
    int iCount;
    struct node<T> *head;

    DoublyLL();
    void Display();

    void InsertFirst(T no);
    void InsertLast(T no);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int ipos);
    int Count();
    void InsertAtPos(T no, int ipos);
};
template <class T>
DoublyLL<T>::DoublyLL()
{
    head = NULL;
    iCount = 0;
}
template <class T>
void DoublyLL<T>:: Display()
{
    struct node<T> *temp = head;

    cout << "Elements in Singly Linear Linked List:\n";
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|<->";
        temp = temp->next;
    }
    cout << "NULL\n";
}
template <class T>
void DoublyLL<T>:: InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (head == NULL) // List is empty
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    iCount++;
}
template <class T>
void DoublyLL<T>:: InsertLast(T no)
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (head == NULL) 
    {
        head = newn;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}
template <class T>
void DoublyLL<T>:: DeleteFirst()
{
    struct node<T> *temp = NULL;
    if (head == NULL) // List is empty
    {
        return;
    }
    else if (head->next == NULL) // Only one element
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    iCount--;
}
template <class T>
void DoublyLL<T>:: DeleteLast()
{
    struct node<T> *temp = NULL;
    if (head == NULL) 
    {
        return;
    }
    else if (head->next == NULL) 
    {
        delete head;
        head = NULL;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }
    iCount--;
}
template <class T>
void DoublyLL<T>:: DeleteAtPos(int ipos)
{
    int i = 0;
    struct node<T> *temp = NULL;
    struct node<T> *target = NULL;
    if (ipos < 1 || ipos > iCount)
    {
        cout << "Invalid position!\n";
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = head;
        for (i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        target = NULL;
        target=temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;

        iCount--;
    }
}
template <class T>
int DoublyLL<T>:: Count()
{
    return iCount;
}
template <class T>
void DoublyLL<T>:: InsertAtPos(T no, int ipos)
{
    int i = 0;
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;
    if (ipos < 1 || ipos > iCount + 1)
    {
        cout << "Invalid position!\n";
        return;
    }
    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new node<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = head;
        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}
int main()
{
    DoublyLL <float>dobj;
    int iRet = 0;

    dobj.InsertFirst(51.1f);
    dobj.InsertFirst(21.2);
    dobj.InsertFirst(11.7);

    dobj.InsertLast(101.7);
    dobj.InsertLast(111.9);
    dobj.InsertLast(121.3);

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of Elements are:" << iRet << "\n";
    dobj.InsertAtPos(75.4, 4);

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of Elements are:" << iRet << "\n";

    return 0;
}