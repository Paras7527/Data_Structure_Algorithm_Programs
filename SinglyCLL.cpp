#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;

class SinglyCLL
{
public:
    PNODE head;
    PNODE tail;
    int iCount;

    SinglyCLL()
    {
        head = NULL;
        tail = NULL;
        iCount = 0;
    }

    void InsertFirst(int no) 
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        if ((head == NULL) && (tail == NULL))
        {
            head = newn;
            tail = newn;
        }
        else
        {
            newn->next = head;
            head = newn;
        }
        tail->next = head;
        iCount++;
    }
    void InsertLast(int no) 
    {
        PNODE newn = NULL;
        newn = new NODE;
        newn->data = no;
        newn->next = NULL;

        if ((head == NULL) && (tail == NULL))
        {
            head = newn;
            tail = newn;
        }
        else
        {
            tail->next = newn;
            tail = newn;
        }
        tail->next = head;
        iCount++;
    }
    void InsertAtPos(int no, int ipos) 
    {
        int i = 0;
        if ((ipos < 1) || (ipos > iCount + 1))
        {
            printf("Invalid Position\n");
            return;
        }
        else if (ipos == 1)
        {
            InsertFirst(no);
        }
        else if (ipos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            PNODE newn = NULL;
            PNODE temp = NULL;
            newn = new NODE;
            newn->data = no;
            newn->next = NULL;

            temp = head;

            for (i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
        }
        iCount++;
    }

    void DeleteFirst() 
    {
        PNODE temp = NULL;
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
        }
        iCount--;
    }
    void DeleteLast() 
    {
        PNODE temp = NULL;
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
            while(temp->next!=tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = head;
        }
        iCount--;
    }
    void DeleteAtPos(int ipos)
    {
        if ((ipos < 1) || (ipos > iCount))
        {
            cout << "Invalid Position\n";
            return;
        }
        else if (ipos == 1)
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
            PNODE target = NULL;

            for (int i = 1; i < ipos - 1; i++)
            {
                temp = temp->next;
            }
            target = temp->next;
            temp->next = target->next;
            delete target;

            iCount--; 
        }
    }
    void Display()
    {
        PNODE temp = NULL;
        if (head == NULL)
        {
            cout << "Linked List is empty\n";
            return;
        }
        temp = head;
        cout << "Elements in Singly Circular Linked List :\n";
        do
        {
            cout << "|" << temp->data << "|->";
            temp = temp->next;
        } while (temp != head);
        cout << "\n";
    }
    int Count()
    {
        return iCount;
    }
};

int main()
{
    SinglyCLL obj;
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

    //obj.DeleteFirst();
    //obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements are : " << iRet << "\n";

    obj.InsertAtPos(75, 4);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements are : " << iRet << "\n";

    obj.DeleteAtPos(4);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of elements are : " << iRet << "\n";

    return 0;
}