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

        if (head == NULL)
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
            while (temp->next != NULL)
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
        cout << "Elements in Singly Linear Linked List:\n";
        while (temp != NULL)
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
            while (temp->next->next != NULL)
            {
                temp = temp->next;
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

            iCount++;
        }
    }
};
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
        return iCount;
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
class SinglyCL
{
public:
    PNODE head;
    PNODE tail;
    int iCount;

    SinglyCL()
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
            while (temp->next != tail)
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
class DoublyCLL
{
public:
    PNODE head;
    PNODE tail;
    int iCount;

    DoublyCLL()
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
    void InsertLast(int no)
    {
        PNODE newn = NULL;
        newn = new NODE;
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
    void InsertAtPos(int no, int ipos)
    {
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

    void DeleteFirst()
    {
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
            PNODE temp = head;
            head = head->next;
            delete temp;

            tail->next = head;
            head->prev = tail;
        }
        iCount--;
    }

    void DeleteLast()
    {
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
            PNODE temp = tail;
            tail = tail->prev;
            delete temp;

            tail->next = head;
            head->prev = tail;
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

            PNODE target = temp->next;
            temp->next = target->next;
            target->next->prev = temp;

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
            cout << "|" << temp->data << "|<=>";
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

    return 0;
}