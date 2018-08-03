/******************************************************************************
VINAL BAGARIA
SE COMPS
Batch A
Roll No. 07
AIM:
Expt 1 : Application of Linked list sparse Matrics
THEORY:
A sparse matrix or sparse array is a matrix in which most of the elements are zero. By contrast, if most of
the elements are nonzero, then the matrix is considered dense.
When storing and manipulating sparse matrices on a computer, it is beneficial and often necessary to use
data structures that take advantage of the sparse structure of the matrix. Operations using standard
structures are slow and inefficient when applied to large sparse matrices as processing and memory are
wasted on the zeroes.

*******************************************************************************/
//CODE
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int r,c,data;
    struct node *down,*right,*link;
}node;
node* mainhead=NULL;
node* head=NULL;
void create_head(int x);
void create_element(int v,int rr,int cc);
void display(int y,int z);
void create_head(int x)//connecting head nodes
{
    node*temp;
    temp=(node*)malloc(sizeof(node));
    head->link=temp;
    head=temp;
    head->r=x;
    head->c=x;
    head->down=head;
    head->right=head;
    head->link=mainhead;
}
void create_element(int v,int rr,int cc)//creating element nodes
{
    node *temp1,*temp2;
    temp1=(node*)malloc(sizeof(node));
    temp2=temp1;
    temp1->r=rr;
    temp1->c=cc;
    temp1->data=v;
    //row connections
    node *p,*q;
    p=mainhead->link;
    q=p;
    while((p->r)!=(temp1->r))
    {
        p=p->link;
    }
    if(p->right==p)//first element
    {
        p->right=temp1;
        temp1->right=p;
    }
    else
    {

        while(((p->right->c)<(temp1->c))&&(p->right!=q))
        {
            p=p->right;
        }
        temp1->right=p->right;
        p->right=temp1;
    }
    //column connections
    node *s,*t;
    s=mainhead->link;
    t=s;
    while((s->c)!=(temp2->c))
    {
        s=s->link;
    }
    if(s->down==s)//first element
    {
        s->down=temp2;
        temp2->down=s;
    }
    else
    {

        while(((s->down->r)<(temp2->r))&&(s->down!=t))
        {
            s=s->down;
        }
        temp2->down=s->down;
        s->down=temp2;
    }
}
void display(int y,int z)//display of matrix
{
    node *h,*trav;
    h=mainhead->link;
    for(int m=1;m<=y;m++)//loop for rows
    {   trav=h;
        for(int n=1;n<=z;n++)//loop for columns
        {
            //trav=trav->right;
            if((trav->right->c)==n&&(trav->right != h))
            {
            printf("%4d",(trav->right->data));
            trav=trav->right;
            }
            else
            printf("%4d",0);
        }
        h=h->link;
        printf("\n");
    }
}
void main()
{

    head=(node*)malloc(sizeof(node));
    mainhead=head;
    printf("Enter dimensions");
    scanf("%d%d",&head->r,&head->c);
    int n;
    if((head->r)>(head->c))
    n=head->r;
    else
    n=head->c;
    for(int i=1;i<=n;i++)
    {
        create_head(i);
    }
    int e;
    printf("Enter no of non-zero elements");
    scanf("%d",&e);
    for(int j=1;j<=e;j++)//connect non-zero elements
    {
        int val,rn,cn;
        printf("Enter data");
        scanf("%d",&val);
        printf("Enter row and column");
        scanf("%d%d",&rn,&cn);
        create_element(val,rn,cn);//call to create_element function

    }
    printf("The matrix is as displayed\n");
        display(mainhead->r,mainhead->c);//call to display function

}
/*
RESULT:
Enter dimensions3
4
Enter no of non-zero elements3
Enter data5
Enter row and column2
2
Enter data9
Enter row and column9
3
Enter data7
Enter row and column1
4
The matrix is as displayed
   0   0   0   7
   0   5   0   0
   0   0   9

CONCLUSION:
Much space and computing time is saved explicitly if only non zero numbers are retained.
Sparse data is by nature more easily compressed and thus requires significantly less storage.

*/



