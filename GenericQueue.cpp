#include <iostream>
using namespace std;
template <class T>
struct node
{
    int data;
    struct node *next;
};
template <class T>
class Queue
{
public:
    struct node<T> *head;
    int iCount;

    Queue();
    void enqueue(T no);
    int dequeue();
    void Display();
    int Count();
};
template <class T>
Queue<T>::Queue()
{
    head = NULL;
    iCount = 0;
}
template <class T>
void Queue<T>::enqueue(T no) // InsertLast
{
    struct node<T> *newn = NULL;
    struct node<T> *temp = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

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
    }
    iCount++;
}
template <class T>
int Queue<T>::dequeue() // DeleteFirst
{
    T no = -1;
    struct node<T> *temp = NULL;
    if (head == NULL)
    {
        cout << "Queue is empty\n";
        return -1;
    }
    else
    {
        no = head->data;
        temp = head;
        head = head->next;
        delete temp;
    }
    iCount--;
    return no;
}
template <class T>
void Queue<T>::Display()
{
    struct node<T> *temp = NULL;
    cout << "Elements of queue are : \n";
    temp = head;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |\n";
        temp = temp->next;
    }
}
template <class T>
int Queue<T>::Count()
{
    return iCount;
}

int main()
{
    Queue <int>qobj;
    int iRet = 0;

    qobj.enqueue(101);
    qobj.enqueue(51);
    qobj.enqueue(21);
    qobj.enqueue(11);

    qobj.Display();
    iRet = qobj.Count();
    cout << "Number of elements are : " << iRet << "\n";

    iRet = qobj.dequeue();
    cout << "Removed element is : " << iRet << "\n";

    iRet = qobj.dequeue();
    cout << "Removed element is : " << iRet << "\n";

    qobj.Display(); // Corrected method call
    iRet = qobj.Count();
    cout << "Number of elements are : " << iRet << "\n";

    return 0;
}
