#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node *PNODE;
class DoublyLL
{
public:
    int iCount;
    PNODE head;

    DoublyLL()
    {
        head = NULL;
        iCount = 0;
    }
    void Display()
    {
        PNODE temp = NULL;
        temp = head;
        cout << "Elements in Singly Linear Linked List:\n";
        while (temp != NULL)
        {
            cout << "|" << temp->data << "|<->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    
    void InsertFirst(int no)
    {
        PNODE newn = new NODE;
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
    void InsertLast(int no)
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        if (head == NULL) // List is empty
        {
            head = newn;
        }
        else
        {
            PNODE temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
            newn->prev = temp;
        }
        iCount++;
    }
    void DeleteFirst()
    {
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
            PNODE temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
        iCount--;
    }
    void DeleteLast()
    {
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
            PNODE temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->prev->next = NULL;
            delete temp;
        }
        iCount--;
    }
    void DeleteAtPos(int ipos)
    {
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
            PNODE temp = head;
            for (int i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }

            PNODE targ = temp->next;
            temp->next = targ->next;
            targ->next->prev = temp;
            delete targ;

            iCount--;
        }
    }
    int Count()
    {
        int iCount;
    }
    void InsertAtPos(int no, int ipos)
    {
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
            PNODE newn = new NODE;
            newn->data = no;
            newn->next = NULL;
            newn->prev = NULL;

            PNODE temp = head;
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
};
int main()
{
    DoublyLL dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);

    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.InsertAtPos(75, 4);

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of Elements are:" << iRet << "\n";

    dobj.DeleteFirst();

    dobj.DeleteLast();

    dobj.DeleteAtPos(4);

    dobj.Display();
    iRet = dobj.Count();
    cout << "Number of Elements are:" << iRet << "\n";

    return 0;
}