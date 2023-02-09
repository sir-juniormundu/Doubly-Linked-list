#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node beg;
struct node *r;

insert()
{
    r->next=(struct node*)malloc(sizeof(struct node*));
    r->next->prev=r;
    r=r->next;
    printf("Enter Data: ");
    scanf("%d",&r->data);
    r->next=NULL;
}
print()
{
    printf("Linked list data:\n");
    r=beg.next;
    while(r!=NULL)
    {
        printf("%d ",r->data);
        r=r->next;
    }

}
insertfirst()
{
    struct node *nr;
    r=beg.next;
    nr=(struct node*)malloc(sizeof(struct node*));
    printf("Enter new node data: ");
    scanf("%d",&r->data);
    nr->next=beg.next;
    beg.next=nr;
    nr->prev=&beg;
    r->prev=nr;
}
insertlast()
{
    struct node *nr;
    r=beg.next;
    nr=(struct node*)malloc(sizeof(struct node*));
    printf("Enter new node data: ");
    scanf("%d",&r->data);
    while(r->next!=NULL)
    {
        r=r->next;
    }
    nr->next=NULL;
    nr->prev=r;
    r->next=nr;
}
deletefirst()
{
    printf("After Deleting\n");
    r=beg.next;
    beg.next=r->next;
    r->next=&beg;
}
deletelast()
{
    printf("After Deleting\n");
    r=beg.next;
    while(r->next->next!=NULL)
    {
        r=r->next;
    }
    r->next=NULL;
}
deletemain()
{
    int ch2;
        printf("1. Delete at First \n2. Delete at Last \n3. Exit");
        printf("\nYour Choice:");
        scanf("%d",&ch2);
        switch(ch2)
        {
        case 1:
            deletefirst();
            break;
        case 2:
            deletelast();
            break;
        case 3:
            printf("Exited!");
            break;
        default:
            printf("Wrong Choice");
            break;
        }
}
insertmain()
{
        int ch1;
        printf("1. Insert \n2. Insert at First \n3. Insert at Last  \n4. Exit");
        printf("\nYour Choice:");
        scanf("%d",&ch1);
        switch(ch1)
        {
        case 1:
            insert();
            break;
        case 2:
            insertfirst();
            break;
        case 3:
            insertlast();
            break;
        case 4:
            printf("Exited!");
            break;
        default:
            printf("Wrong Choice");
            break;
        }
}
operation()
    {
    int ch;
    printf("Operations Available\n");
    printf("1.Insert \n2.Print \n3.Delete \n4.Exit\n");
    printf("\nYour Choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        insertmain();
        printf("\n");
        operation();
        break;

    case 2:
        print();
        printf("\n");
        operation();
        break;

    case 3:
        deletemain();
        printf("\n");
        operation();
        break;

    case 4:
        printf("\nThank You!");
        break;

    default:
        printf("\nWrong Choice");
        }
    }
int main()
{
    int ch;
    beg.prev=NULL;
    beg.next=NULL;
    r=&beg;
    operation();


}
