#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct node{
    int num;
    struct node *next;
};


node *head;



void createdList()
{
    struct node *newnode;
    struct node *temp;
    int n;
    printf("please input 5 nums:\n");
    for(n=1; n<=5; n++)
    {
        newnode = (struct node *)malloc(sizeof(node));
        scanf("%d", &newnode->num);
        newnode->next=NULL;
        if(head==NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next=newnode;
        }
    }
}
void displayList()
{
    struct node *temp;
    //temp=head;
    for(temp=head; temp!=NULL;temp=temp->next)
    {
        printf("%d ", temp->num);
    }
    printf("\n");
}
int main()
{
    head = NULL;
    createdList();
    displayList();
    /* std::cout << "Hello world" << std::endl; */
    return 0;
}

