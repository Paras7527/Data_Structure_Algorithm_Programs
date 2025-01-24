#include <iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
} NODE, *PNODE;

class Stack
{
public:
    PNODE head;
    int iCount;

    Stack()
    {
        head = NULL;
        iCount = 0;
    }

    void push(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = head;
        head = newn;
        iCount++;
    }

    int pop()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        int no = head->data;
        PNODE temp = head;
        head = head->next;
        delete temp;
        iCount--;
        return no;
    }

    void Display()
    {
        PNODE temp = head;
        cout << "Elements in the Stack:" << endl;
        while (temp != NULL)
        {
            cout << "|" << temp->data << "|" << endl;
            temp = temp->next;
        }
    }

    int Count()
    {
        return iCount;
    }
};

int main()
{
    Stack sobj;
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
