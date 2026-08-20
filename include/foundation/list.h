#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdlib.h>
#include <string.h>

typedef struct sNode 
{
    void *data;
    unsigned dataSize;
    struct sNode *next;
}tNode;

typedef tNode *tList;

typedef (*CompareFunc)(const void *, const void *);
typedef (*ActionFunc)(void *, void *);
typedef (*ShowFunc)(const void *);

tError initList(tList *list);
tError insertHead(tList *list, const void *data, unsigned dataSize);
tError insertTail(tList *list, const void *data, unsigned dataSize);
tError insertOrdered(tList *list, const void *data, unsigned dataSize, CompareFunc compare);
tError getHead(tList *list, void *data, unsigned dataSize);
tError getTail(tList *list, void *data, unsigned dataSize);
tError deleteElementByKey(tList *list, const void *data, unsigned dataSize, CompareFunc compare);
tError mapList(tList *list, ActionFunc action, void *context);
tError showList(tList *list, ShowFunc show);
void freeList(tList *list);


#endif // LIST_H_INCLUDED
