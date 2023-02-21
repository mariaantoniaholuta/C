#include <stdio.h>
#include <stdlib.h>
#define M 7 //dimensiunea tabelei de dispersie

typedef struct node
{
    int val;
    struct node *next;
} NodeT;

int hFunction(int key)
{
    return key%M;
}

void insert(NodeT* hTable[M], int key)
{
    NodeT *newnode = malloc(sizeof(NodeT));
    newnode->val = key;
    newnode->next = NULL;

    int key2 = hFunction(key);
    if( hTable[key2] == NULL )
    {
        hTable[key2] = newnode;
    }
    else
    {
        NodeT *p = hTable[key2];
        while(p->next)
        {
            p = p->next;
        }
        p->next = newnode;
    }
}


NodeT* search(NodeT* hTable[M], int key)
{
    int key2 = hFunction(key);
    NodeT *p = hTable[key2];

    if( hTable[key2] == NULL )
    {
        //   printf("elementul cu cheia %d nu exista", key);
        return NULL;
    }
    else
    {
        while( p != NULL )
        {
            if( p->val == key )
            {
                // puts("gasit");
                return p;
                break;
            }
            p = p->next;
        }

    }


    return NULL;
}

void deleteKey(NodeT* hTable[M], int key)
{
    int key2 = hFunction(key);
    NodeT *p = hTable[key2];
    NodeT *q = search(hTable, key);


    if ( q != NULL )
    {
        hTable[key2] = hTable[key2]->next;
       // free(p);
    }
}




void showAll(NodeT* hTable[M])
{
    int i;
    for(i = 0; i < M; i++)
    {
        printf(" %d :",i);

        if(hTable[i] != NULL)
        {

            NodeT *p;
            p = hTable[i];
            while (p != NULL)
            {
                printf(" %d ",p->val);
                p = p->next;
            }
        }
        printf("\n");
    }
    printf("\n");
}

void insert2(NodeT* hTable[M], int key)
{

    NodeT *newnode = malloc(sizeof(NodeT));
    newnode->val = key;
    newnode->next = NULL;
    int index, i, hkey;

    hkey=key%M;
    for( i=0; i < M; i++ )
    {

        index=(hkey+i)%M;

        if(hTable[index] == NULL)
        {
            hTable[index] = newnode;
            break;
        }

    }

//    if( i == M )
//
//        printf("NU POATE FI INSERAT\n");
}



int main()
{

    //initializare
    NodeT* hTable[M];
    for(int i = 0; i < M; i++)
    {
        hTable[i] = NULL;
    }

    //test inserare
    int vals[] = {36, 18, 6, 43, 72, 10, 5, 15};
    for(int i=0; i < sizeof(vals)/sizeof(int); i++)
        insert(hTable, vals[i]);
    showAll(hTable);

    // 0:
    // 1: 15 43 36
    // 2: 72
    // 3: 10
    // 4: 18
    // 5: 5
    // 6: 6

    NodeT *q = search(hTable, 5);
    if( q != NULL )
    {
        deleteKey(hTable, 5);
    }
    // NodeT *p = deleteKey2(hTable, 5);
    deleteKey(hTable, 12);
    showAll(hTable);



     NodeT* hTable2[M];
    for(int i = 0; i < M; i++)
    {
        hTable2[i] = NULL;
    }

    int vals2[] = {36, 18, 6, 43, 72, 10, 5, 15};
    for(int i=0; i < sizeof(vals2)/sizeof(int); i++)
        insert2(hTable2, vals2[i]);
    showAll(hTable2);

    return 0;
}
