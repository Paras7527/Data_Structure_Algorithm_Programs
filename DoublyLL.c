#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;
void InsertFirst(PPNODE head,int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*head==NULL)
    {
        *head = newn;
    }
    else
    {
        newn->next = *head;
        (*head)->prev = newn;
        *head = newn;
    }
}
void InsertLast(PPNODE head, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (*head == NULL)
    {
        *head = newn;
    }
    else
    {
        temp = *head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}
void Display(PNODE head)
{
    printf("\nThe doubly Linked list:\n");
    while(head!=NULL)
    {
        printf("|%d|<=>", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int Count(PNODE head)
{
    int iCount = 0;
    while (head != NULL)
    {
        iCount++;
        head = head->next;
    }
    return iCount;
}
void DeleteFirst(PPNODE head)
{
    PNODE temp = NULL;
    if(*head==NULL)
    {
        return;
    }
    else if((*head)->next!=NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        *head = (*head)->next;
        free((*head)->prev);
        (*head)->prev = NULL;
    }
}
void DeleteLast(PPNODE head)
{
    PNODE temp = NULL;
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next != NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        temp = *head;
        while(temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}
void InsertAtPos(PPNODE head,int no,int ipos)
{
    PNODE newn = NULL;
    PNODE temp = NULL;
    int i = 0;
    int CountNode = 0;
    CountNode = Count(*head);
    if ((ipos < 1) || (ipos > CountNode + 1))
    {
        printf("Invalid Position...\n");
    }
    else if(ipos==1)
    {
        InsertFirst(head, no);
    }
    else if(ipos==CountNode+1)
    {
        InsertLast(head, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = *head;
        for (i = 1; i < ipos - 1;i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}
void DeleteAtPos(PPNODE head,int ipos)
{
    PNODE target = NULL;
    PNODE temp = NULL;
    int i = 0;
    int CountNode = 0;
    CountNode = Count(*head);
    if ((ipos < 1) || (ipos > CountNode + 1))
    {
        printf("Invalid Position...\n");
    }
    else if (ipos == 1)
    {
        DeleteFirst(head);
    }
    else if (ipos == CountNode + 1)
    {
        DeleteLast(head);
    }
    else
    {
        temp = *head;
        for (i = 1; i < ipos - 1;i++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        temp->next->prev = temp;
        free(target);
    }
}
int main()
{
    PNODE first = NULL;
    PNODE last = NULL;
    int iRet = 0;

    InsertFirst(&first, 51);
    InsertFirst(&first, 21);
    InsertFirst(&first, 11);

    InsertLast(&first, 101);
    InsertLast(&first, 111);
    InsertLast(&first, 121);

    Display(first);
    iRet =Count(first);
    printf("The Number Of Elements In The Linked List:%d", iRet);

    //DeleteFirst(&first);

   InsertAtPos(&first,75,4);

    Display(first);
    iRet = Count(first);
    printf("The Number Of Elements In The Linked List:%d", iRet);

    DeleteAtPos(&first,4);
    Display(first);
    iRet = Count(first);
    printf("The Number Of Elements In The Linked List:%d", iRet);

    return 0;
}