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
class DoublyCLL
{
    public:
        struct node<T> *head;
        struct node<T> *tail;
        int iCount;

        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int ipos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int ipos);
        void Display();
        int Count();
};
template <class T>
DoublyCLL<T>::DoublyCLL()
{
    head = NULL;
    tail = NULL;
    iCount = 0;
}
template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        newn->next = head;
        head->prev = newn;
        head = newn;
    }
    tail->next = head;
    head->prev = tail;
    iCount++;
}
template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;

    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((head == NULL) && (tail == NULL))
    {
        head = newn;
        tail = newn;
    }
    else
    {
        tail->next = newn;
        newn->prev = tail;
        tail = newn;
    }
    tail->next = head;
    head->prev = tail;

    iCount++;
}
template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int ipos)
{
    int i = 0;
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;
    if ((ipos < 1) || (ipos > iCount + 1))
    {
        cout << "Invalid Position\n";
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
        for (i = 1; i < ipos - 1; i++)
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
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    struct node<T> *temp = NULL;
    if ((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        delete temp;

        tail->next = head;
        head->prev = tail;
    }
    iCount--;
}
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    struct node<T> *temp = NULL;
    if ((head == NULL) && (tail == NULL))
    {
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        temp = tail;
        tail = tail->prev;
        delete temp;

        tail->next = head;
        head->prev = tail;
    }
    iCount--;
}
template <class T>
void DoublyCLL<T>::DeleteAtPos(int ipos)
{
    int i = 0;
    struct node<T> *temp = NULL;
    struct node<T> *target = NULL;

    if ((ipos < 1) || (ipos > iCount))
    {
        cout << "Invalid Position\n";
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

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;

        delete target;
        iCount--;
    }
}
template <class T>
void DoublyCLL<T>::Display()
{

    struct node<T> *temp = NULL;
    temp = NULL;
    if (head == NULL)
    {
        cout << "Linked List is empty\n";
        return;
    }
    temp = head;
    cout << "Elements in Singly Circular Linked List :\n";
    do
    {
        cout << "|" << temp->data << "|<=>";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}
template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

int main()
{
    DoublyCLL <int>obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements are : " << iRet << "\n";
    
    obj.InsertAtPos(75, 4);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements are : " << iRet << "\n";


    return 0;
}