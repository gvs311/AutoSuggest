#ifndef TRIEHEADER_H_INCLUDED
#define TRIEHEADER_H_INCLUDED
#define SIZE 26
#include <stdbool.h>
typedef struct node
{
    bool eow;
    struct node *next[SIZE];
}trieN;
trieN* createTrie();
bool insertWord(trieN* root, char word[]);
void print(trieN* root,char arr[],int last);
void printWithPrefix(trieN* root,char prefix[]);



#endif // TRIEHEADER_H_INCLUDED
