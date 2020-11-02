#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


#define size 26

struct node{
    int cnt;
    struct node *children[size];
};


node *root;

node* CreateNode()
{
    struct node *newnode;
    int n;
    newnode = (struct node *)malloc(sizeof(node));
    newnode->cnt = 0;
    for(n=0; n<size; n++)
    {
        newnode->children[n]=NULL;
    }
    return newnode;
}

void InsertNode()
{
    int n;
    int k;
    char word[20];
    struct node *temp;
    root = CreateNode();
    printf("please input 5 words:");
    for(n=1; n<=5; n++)
    {
        temp = root;
        memset(word, 0, sizeof(word));
        scanf("%s", word);
        //printf("%s ", words);
        for(k=0; k<strlen(word); k++)
        {
            if(temp->children[word[k]-'a']==NULL)
            {
                temp->children[word[k]-'a'] = CreateNode();
            }
            else
            {

            }
            temp = temp->children[word[k]-'a'];
        }
        temp->cnt += 1;
    }
}

void SearchWords()
{
    char word[20];
    struct node *temp;
    temp = root;
    int k;
    memset(word, 0, sizeof(word));
    printf("please input a word:");
    {
        scanf("%s", word);
        for(k=0; k<strlen(word); k++)
        {
            if(temp->children[word[k]-'a']!=NULL)
            {
                temp=temp->children[word[k]-'a'];
            }
            else
            {
                printf("Can not find the word in the Tree!\n");
                break;
            }
        }
        if(k==strlen(word))
        {
            printf("Find the word! The count of this word is %d.\n", temp->cnt);
        }
    }
}

int main()
{   
    root = NULL;
    //CreateNode();
    InsertNode();
    SearchWords();
    /* std::cout << "Hello world" << std::endl; */
    return 0;
}


/*
please input 5 words:the the right new hold
please input a word:the
Find the word! The count of this word is 2.
*/
