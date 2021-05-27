#include <stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    
}Node;

Node *start = NULL;


int getval()
{
    int val;
    printf("\n Enter the value : ");
    scanf("%d",&val);
    return val;
}

Node* getNode()
{
    int val = getval();
    Node *n = (Node*)malloc(sizeof(Node));
    n->next=NULL;
    n->data =val;
    return n;
}


void displayList(Node *n)
{
    while(n!=NULL)
    {
        printf("%d ",n->data);
        n= n->next;
    }
}

int length(Node * n)
{
    int count=0;
    while(n!=NULL)
    {
        count++;
        n=n->next;
    }
    return count;
}


int search(Node *n, int val)
{
    int count=0;
    while (n!=NULL) {
        if(val == n->data)
        {
            printf("\n Value found at location %d",count);
            return 0;
        }
        count++;
    }
    return -1;
}




void Insert_beg( Node *n)
{
    Node *newNode =getNode();
    newNode->next=n;
    start =newNode;
}


void Insert_end(Node *n)
{
    Node *newNode =getNode();
    if(n==NULL)
    {
        start = newNode;
    }
    else
    {
        while(n->next != NULL)
        {
            n= n->next;
        }
        n->next=newNode;
    }
}

void insert_pos(Node *n, int pos)
{
    Node *temp =n;
    int val = length(start);
    if(pos == 0)
        Insert_beg(start);
    else if(pos == val)
        Insert_end(start);
    else if(val > pos){
        while(--pos)
        {
            temp = n;
            n = n->next;
        }
        Node *newNode =getNode();
        newNode->next = n;
        temp->next = newNode;
    }
    else
    {
        printf("\n invalid postion");
    }
}

void delete_end(Node *n)
{
    if(n == NULL)
    {
        printf("\n cant delete from empty list");
        return;
    }
    if(start->next == NULL)
    {
        free(start);
        start = NULL;
        return;
    }
    while(n->next->next != NULL)
    {
        n=n->next;
    }
    free(n->next);
    n->next = NULL;
}
void delete_pose(Node *n, int pos)
{
    Node *temp=NULL;
    if (n==NULL)
    {
        
    printf("\n Cant free empty List");
    return;
        
    }
    if (pos > length(n))
    {
        printf("\n Invalid postion");
        return;
    }
    else if(pos == 0)
    {
        start = start->next;
        free(n);
    }
    else if (pos == length(n)-1)
    {
        delete_end(n);
    }
    else
    {
        while(--pos)
        {
            n=n->next;
        }
        temp =n->next->next;
        free(n->next);
        n->next = temp;
        
    }
}

void Push(Node *n)
{
    Insert_end(n);
}
void Pop(Node *n)
{
    delete_end(n);
}
void Peek(Node *n)
{
    while(n->next != NULL)
    {
        n=n->next;
    }
    printf("\n %d",n->data);
}
void enqueue(Node *n)
{
    Insert_end(n);
    displayList(start);
    
}
void unque(Node *n)
{
    delete_pose(n,0);
    displayList(start);
}
int main()
{
    int opt, val;
    while(1)
    {
        printf("1. LinkedList 2. Stack \n 3. Queue \n 5. Dequeue \n 6. Exit");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            
            while (1)
            {
                
                printf("\n Enter the operation \n 1. Add Node \n 2. Delete Node \n 3. Display List \n 4. Search element \n 5. Length \n 0. Exit \n : ");
                scanf("%d",&opt);
                switch(opt)
                {
                case 1:
                    printf("\n Enter the operation \n 1. Begining \n 2. End \n 3. Position. Exit \n : ");
                    scanf("%d",&opt);
                    switch(opt)
                    {
                    case 1:
                        Insert_beg(start);
                        break;
                    case 2:
                        Insert_end(start);
                        break;
                    case 3:
                        printf("\n Enter the position to be inserted (index start from 0) : ");
                        scanf("%d",&opt);
                        insert_pos(start, opt);
                        break;
                    default:
                        printf("\n Invalid Entry ");
                    }
                    displayList(start);
                    break;
                case 2:
                    printf("\n Enter the operation \n 1. Begining \n 2. End \n 3. Position. Exit \n : ");
                    scanf("%d",&opt);
                    switch(opt)
                    {
                    case 1:
                        delete_pose(start, 0);
                        break;
                    case 2:
                        delete_end(start);
                        break;
                    case 3:
                        printf("\n Enter the position : ");
                        scanf("%d",&opt);
                        delete_pose(start, opt);
                        break;
                    default:
                        printf("\n Invalid entry");
                    }
                    displayList(start);
                case 3:
                    displayList(start);
                    break;
                case 4:
                    printf("\n Enter the value : ");
                    scanf("%d",&val);
                    if  (search(start, val) == -1)
                        printf("\n The given value is not present in the list");
                    break;
                case 5:
                    printf("\n Length : %d ",length(start));
                    break;
                case 0:
                    exit(0);
                    break;
                    
                default:
                    printf("\n Invalid Entry");
                }
            }
        case 2:
            start=NULL;
            while(1)
            {
                printf("\n Enter stack the operation 1. Push 2. Pop: 3. Peek 4. Length 0. Exit ");
                scanf("%d", &opt);
                if(opt==0) break;
                
                switch(opt)
                {
                case 1:
                    Push(start);
                    break;
                case 2:
                    Pop(start);
                    break;
                case 3:
                    Peek(start);
                    break;
                case 4:
                    printf("\n Length = %d", length(start));
                    break;
                    
                default:
                    printf("\n Invalid operation");
                    
                }
                
            }
        case 3:
            start = NULL;
            while(1)
            {
                printf("\n Enter queue the operation 1. Enqueue 2. Unque 3. Length 0. Exit ");
                scanf("%d", &opt);
                if(opt==0) break;
                
                switch(opt)
                {
                case 1:
                    enqueue(start);
                    break;
                case 2:
                    unque(start);
                    break;
                case 3:
                    printf("\n Length = %d", length(start));
                    break;
                    
                default:
                    printf("\n Invalid operation");
                }
                
            }
                
            
        }
        return 0;
    }
}
