class Node 
{
    public int data;
    public Node next;

    public Node(int x) 
    {
        data = x;
        next = null;
    }
}

class SinglyCL 
{
    public Node head;
    public Node tail;
    public int iCount;

    public SinglyCL() 
    {
        head = null;
        tail = null;
        iCount = 0;
    }

    public void InsertFirst(int no) 
    {
        Node newn = new Node(no);

        if (head == null && tail == null) 
        {
            head = newn;
            tail = newn;
        } 
        else 
        {
            newn.next = head;
            head = newn;
        }

        tail.next = head;
        iCount++;
    }

    public void InsertLast(int no) 
    {
        Node newn = new Node(no);

        if (head == null && tail == null) 
        {
            head = newn;
            tail = newn;
        } 
        else 
        {
            tail.next = newn;
            tail = newn;
        }
        tail.next = head;

        iCount++;
    }

    public void Display() 
    {
        if (head == null) 
        {
            System.out.println("The linked list is empty.");
            return;
        }

        Node temp = head;

        System.out.println("Elements of the linked list are:");
        do 
        {
            System.out.print("|" + temp.data + "| -> ");
            temp = temp.next;
        } while (temp != head);

        System.out.println();
    }

    public int Count() 
    {
        return iCount;
    }

    public void DeleteFirst() 
    {
        if (head == null) 
        {
            return;
        }

        if (head == tail) {
            head = null;
            tail = null;
        } 
        else 
        {
            head = head.next;
            tail.next = head;
        }

        iCount--;
    }

    public void DeleteLast() 
    {
        if (head == null) 
        {
            return;
        }

        if (head == tail) 
        {
            head = null;
            tail = null;
        } 
        else 
        {
            Node temp = head;
            while (temp.next != tail) 
            {
                temp = temp.next;
            }
            tail = temp;
            tail.next = head;
        }

        iCount--;
    }

    public void InsertAtPos(int no, int iPos) 
    {
        if (iPos < 1 || iPos > iCount + 1) 
        {
            System.out.println("Invalid position");
            return;
        }

        if (iPos == 1) 
        {
            InsertFirst(no);
        } 
        else if (iPos == iCount + 1) 
        {
            InsertLast(no);
        } 
        else 
        {
            Node newn = new Node(no);
            Node temp = head;

            for (int i = 1; i < iPos - 1; i++) 
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteAtPos(int iPos) 
    {
        if (iPos < 1 || iPos > iCount) 
        {
            System.out.println("Invalid position");
            return;
        }

        if (iPos == 1) 
        {
            DeleteFirst();
        } 
        else if (iPos == iCount) 
        {
            DeleteLast();
        } 
        else 
        {
            Node temp = head;

            for (int i = 1; i < iPos - 1; i++) 
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;
            iCount--;
        }
    }
}

class SinglyCircular 
{
    public static void main(String[] args) 
    {
        int iRet;

        SinglyCL dobj = new SinglyCL();

        dobj.InsertFirst(51);
        dobj.InsertFirst(21);
        dobj.InsertFirst(11);

        dobj.InsertLast(101);
        dobj.InsertLast(111);
        dobj.InsertLast(121);

        dobj.Display();

        iRet = dobj.Count();
        System.out.println("Number of elements in the linked list: " + iRet);

        dobj.DeleteAtPos(4);

        dobj.Display();

        iRet = dobj.Count();
        System.out.println("Number of elements in the linked list: " + iRet);
    }
}
