#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node* PNODE;
class SinglyLL
{
    public:
    PNODE head;
    int iCount;
    SinglyLL()
    {
        iCount = 0;
        head = NULL;
    }
    void InsertFirst(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        if(head==NULL)
        {
            head = newn;
        }
        else
        {
            newn->next = head;
            head = newn;
        }
        iCount++;
    }
    void InsertLast(int no)
    {
        PNODE newn = NULL;
        PNODE temp = NULL;
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        if (head == NULL)
        {
            head = newn;
        }
        else
        {
            temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        iCount++;
    }
    void Display()
    {
        PNODE temp = NULL;
        temp = head;
        cout<<"Elements in Singly Linear Linked List:\n";
        while(temp!=NULL)
        {
            cout << "|" << temp->data << "|->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    int Count()
    {
        return iCount;
    }
    void DeleteFirst()
    {
        PNODE temp = NULL;
        if(head==NULL)
        {
            return;
        }
        else if(head->next==NULL)
        {
            delete head;
            head = NULL;
        }
        else 
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        iCount--;
    }
    void DeleteLast()
    {
        PNODE temp = NULL;
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
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        iCount--;
    }
    void InsertAtPos(int no, int ipos)
    {
        if ((ipos < 1) || (ipos > iCount + 1))
        {
            cout << "Invalid position\n";
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
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            PNODE temp = head;

            for (int i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next = newn;

            iCount++;
        }
    }

    void DeleteAtPos(int ipos)
    {
        if ((ipos < 1) || (ipos > iCount + 1))
        {
            cout << "Invalid position\n";
            return;
        }

        if (ipos == 1)
        {
            DeleteFirst();
        }
        else if (ipos == iCount + 1)
        {
            DeleteLast();
        }
        else
        {

            PNODE temp = NULL;
            PNODE target = NULL;
            temp = head;
            for (int i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            target = temp->next;
            temp->next = target->next;
            delete (target);

            iCount--;
        }
    }
};
int main()
{
    SinglyLL sobj;
    int iRet = 0;

    sobj.InsertFirst(20);
    sobj.InsertFirst(10);

    sobj.InsertLast(30);
    sobj.InsertLast(40);

    sobj.Display();
    iRet = sobj.Count();
    cout << sobj.Count();

    sobj.DeleteFirst();
    sobj.DeleteLast();

    sobj.Display();
    iRet = sobj.Count();
    cout << sobj.Count();

    return 0;
}