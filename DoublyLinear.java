class node
{
    public int data;
    public node next;
    public node prev;

    public node(int x)
    {
        data = x;
        next = null;
        prev=null;
    }
}

class DoublyLL
{
    public node head;
    public int iCount;

    public DoublyLL()
    {
        head = null;
        iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);

        if(head == null)
        {
            head = newn;
        }
        else
        {
            newn.next = head;
            head.prev=newn;
            head = newn;
        }
        iCount++;
    }
    
    public void InsertLast(int no)
    {
        node newn = null;

        newn = new node(no);

        if(head == null)
        {
            head = newn;
        }
        else
        {
            node temp = head;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
            newn.prev=temp;
        }
        iCount++;
    }

    public void Display()
    {
        System.out.println("Elements of the LinkedList are : ");

        node temp = head;

        while(temp != null)
        {
            System.out.print("|"+temp.data+"|<->");
            temp = temp.next;
        }
        System.out.println("|null|");
    }

    public int Count()
    {
        return iCount;
    }

    public void DeleteFirst()
    {
        if(head == null)
        {
            return;
        }
        else if(head.next == null)
        {
            head = null;
            System.gc();
        }
        else
        {
            node temp=head;
            head = head.next;
            head.prev=null;
            System.gc();
        }
        iCount--;
    }

    public void DeleteLast()
    {
        if(head == null)
        {
            return;
        }
        else if(head.next == null)
        {
            head = null;
            System.gc();
        }
        else
        {
            node temp = head;

            while(temp.next!= null)
            {
                temp = temp.next;
            }
            temp.prev.next = null;
            System.gc();
        }
        iCount--;
    }

    public void InsertAtPos(int no, int ipos)
    {
        if((ipos < 1) || (ipos > iCount+1))
        {
            System.out.println("Invalid position");
            return;
        }

        if(ipos == 1)
        {
            InsertFirst(no);
        }
        else if(ipos == iCount+1)
        {
            InsertLast(no);
        }
        else
        {   
            node newn = new node(no);
            node temp = head;

            int i = 0;

            for(i = 1; i < ipos-1; i++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            newn.prev=temp;
            temp.next.prev=newn;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteAtPos(int ipos)
    {
        if((ipos < 1) || (ipos > iCount))
        {
            System.out.println("Invalid position");
            return;
        }

        if(ipos == 1)
        {
            DeleteFirst();
        }
        else if(ipos == iCount)
        {
            DeleteLast();
        }
        else
        {   
            node temp = head;
            int i = 0;
            node target=null;

            for(i = 1; i < ipos-1; i++)
            {
                temp = temp.next;
            }

            target=temp.next;
            temp.next=target.next;
            target.next.prev=temp;

            System.gc();

            iCount--;
        }
    }
}

class DoublyLinear
{
    public static void main(String Arg[])
    {
        DoublyLL sobj = new DoublyLL();
        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);
        
        sobj.Display();
        iRet = sobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        sobj.InsertAtPos(75,4);
        
        sobj.Display();
        iRet = sobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

        sobj.DeleteAtPos(4);

        sobj.Display();
        iRet = sobj.Count();

        System.out.println("Number of elements in the LinkedList are : "+iRet);

    }
}