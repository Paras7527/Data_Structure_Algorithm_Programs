#include <iostream>
using namespace std;
template <class T>
struct node
{
    int data;
    struct node *next;
};
template <class T>
class Stack
{
public:
    struct node<T> *head;
    int iCount;

    Stack();
    void push(T no);
    int pop();
    void Display();
    int Count();
};
template <class T>
Stack<T>::Stack()
{
    head = NULL;
    iCount = 0;
}
template <class T>
void Stack<T>::push(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = head;
    head = newn;
    iCount++;
}
template <class T>
int Stack<T>::pop()
{
    struct node<T> *temp = NULL;
    if (head == NULL)
    {
        cout << "Stack is Empty" << endl;
        return -1;
    }

    T no = head->data;
    temp = head;
    head = head->next;
    delete temp;
    iCount--;
    return no;
}
template <class T>
void Stack<T>::Display()
{
    struct node<T> *temp = NULL;
    temp = head;
    cout << "Elements in the Stack:" << endl;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|" << endl;
        temp = temp->next;
    }
}
template <class T>
int Stack<T>::Count()
{
    return iCount;
}
int main()
{
    Stack <int>sobj;
    int iRet = 0;

    sobj.push(51);
    sobj.push(21);
    sobj.push(11);

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of Elements in the Stack: " << iRet << endl;

    iRet = sobj.pop();
    cout << "Popped element is: " << iRet << endl;

    sobj.Display();
    iRet = sobj.Count();
    cout << "Number of Elements in the Stack: " << iRet << endl;

    return 0;
}
