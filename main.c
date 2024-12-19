#include <stdio.h>
#include <stdlib.h>

enum returnvalue
{
    Failure = 0,
    Success
};

struct node
{
    int data;
    struct node *next;
};

struct node* createNode(struct node *head)
{
    struct node *newnode, *temp;
    int choice,count = 0;
    while(choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if(newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return Failure;
        }
        printf("Enter data\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;

        if(head == 0)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != 0)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
        ++count;
        printf("Want to continue... press 1 else 0\n");
        scanf("%d",&choice);
    }
    return head;
}

int displayList(struct node *head)
{
    struct node *temp = head;
    if(temp == 0)
    {
        printf("List is empty\n");
        return Failure;
    }
    else
    {
        while(temp != 0)
        {
            printf("%d\n",temp->data);
            temp = temp->next;
        }
        return Success;
    }
}

int searchByValue(struct node *head,int value)
{
    struct node*temp = head;
    while(temp != 0 && temp->data != value)
    {
        temp = temp->next;
    }
    if(temp == 0)
    {
        printf("Value not found\n");
        return Failure;
    }
    else
    {
    printf("value = %d\n",temp->data);
    return Success;
    }
}

int searchByPosition(struct node *head,int pos)
{
    struct node*temp = head;
    int i = 1;

    if(pos == 0)
    {
        printf("value = %d\n",temp->data);
        return Success;
    }
    else
    {
        while(temp != 0 && i < pos + 1)
        {
            temp = temp->next;
            i++;
        }
        if(temp == 0)
        {
            printf("Entered position not found\n");
            return Failure;
        }
        else
        {
        printf("value = %d\n",temp->data);
        return Success;
        }
    }
}

int main()
{
    struct node *head = 0;
    int option,True = 1,count = 0;
    while(True)
    {
        printf("Enter\n1.Create Node\n2.Display List\n3.Search by value\n4.Search by position\n5.Exit:");
        scanf("%d",&option);
        switch(option)
        {
            int pos,value;
        case 1:
            head = createNode(head);
            break;
        case 2:
            displayList(head);
            printf("List displayed\n");
            break;
        case 3:printf("Enter value to search\n");
            scanf("%d",&value);
            searchByValue(head,value);
            break;
        case 4:
            printf("Enter position to search\n");
            scanf("%d",&pos);
            searchByPosition(head,pos);
            break;
        case 5:True = 0;
            printf("Exiting.....\n");
            break;
        default:
            printf("Enter valid option\n");
            break;
        }
    }
}

