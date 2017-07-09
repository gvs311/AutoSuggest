#include <stdio.h>
#include <stdlib.h>
#include "trieHeader.h"
trieN* alphabetT[SIZE];
void initialize_alphabetT()
{
    int i;
    for (i=0;i<SIZE;i++)
        alphabetT[i]=NULL;
}
char* toLowerCase(char* str)
{
    //printf("in toLowerCase, string:%s\n",str);
    int i=0;
    while (str[i]!='\0')
    {
        if (str[i]>='A' && str[i]<='Z')
            str[i]+='a'-'A';
            i++;
    }
    return str;
}
void trieBuilder(char ch)
{
    FILE *fp=fopen("dictionary.txt","r");
    if (fp==NULL)
    {
        printf("Cannot open dictionary file.\n");
        fclose(fp);
        return;
    }
    else
        printf("File opened.\n");
    trieN* root=createTrie();
    char temp[100];
    while (fscanf(fp,"%s",temp)==1)
    {
        if (temp[0]==ch)
        {
            insertWord(root,temp);
        }
    }
    alphabetT[ch-'a']=root;

}
int main()
{
    initialize_alphabetT();
    int index;
    char* word=malloc(sizeof(char)*100);
    printf("Enter word you want to search:");
    scanf("%s",word);
    printf("%s\n",word);
    word=toLowerCase(word);
    index=word[0]-'a';
    if (alphabetT[index]==NULL)
        trieBuilder(word[0]);
    printWithPrefix(alphabetT[index],word);
    free(word);
    return 0;
}
