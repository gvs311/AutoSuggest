#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "trieHeader.h"
trieN* createTrie()
{
    trieN* newnode=malloc(sizeof(trieN));
    newnode->eow=false;
    int i;
    for (i=0;i<SIZE;i++)
        newnode->next[i]=NULL;
    return newnode;
}
bool insertWord(trieN* root, char word[])
{
    int i=0,index;
    while(word[i]!='\0')
    {
        index=word[i]-'a';
        if (root->next[index]==NULL)
            root->next[index]=createTrie();
        root=root->next[index];
        i++;
    }
    if (root->eow)
        return false;
    root->eow=true;
    return true;
}
void print(trieN* root,char arr[],int last)
{
    int i=0;
    if (root->eow)
        printf("%s\n",arr);
    while (i<SIZE)
    {
        if (root->next[i]!=NULL)
        {
            arr[last]='a'+i;
            arr[last+1]='\0';
            print(root->next[i],arr,last+1);
        }
        i++;
    }
}
void printWithPrefix(trieN* root,char prefix[])
{

    int i=0,index;
    char* arr=malloc(sizeof(char)*100);
    while (prefix[i]!='\0')
    {
        index=prefix[i]-'a';
        root=root->next[index];
        arr[i]=prefix[i];
        i++;
    }
    arr[i]=prefix[i];
    print(root,arr,i);
    free(arr);
}
