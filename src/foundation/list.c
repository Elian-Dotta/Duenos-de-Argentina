#include "../../include/foundation/list.h"

#define minimum( A , B ) ( ( A ) < ( B ) ? ( A ) : ( B ))

tError initList(tList *list)
{
    if(!list)
    {
        return ERROR_INVALID_ARGUMENT;
    }

    *list = NULL;

    return OK;
}

tError insertHead(tList *list, const void *data, unsigned dataSize)
{
    tNode *new;

    if(!list || !data || !dataSize)
    {
        return ERROR_INVALID_ARGUMENT;
    }

    new = (tNode*)malloc(sizeof(tNode));

    if(new == NULL ||
      (new->data = malloc(dataSize)) == NULL)
    {
        free(new);
        return ERROR_MEMORY_ALLOCATION;
    }

    memcpy(new->data, data, dataSize);
    new->dataSize = dataSize;
    new->next = *list;
    *list = new;

    return OK;
}

tError insertTail(tList *list, const void *data, unsigned dataSize)
{
    tNode *new;

    if(!list || !data || !dataSize)
    {
        return ERROR_INVALID_ARGUMENT;
    }

    new = (tNode*)malloc(sizeof(tNode));

    if(new == NULL ||
      (new->data = malloc(dataSize)) == NULL)
    {
        free(new);
        return ERROR_MEMORY_ALLOCATION;
    }

    while(*list)
    {
        list = &(*list)->next;
    }

    memcpy(new->data, data, dataSize);
    new->dataSize = dataSize;
    new->next = *list;
    *list = new;

    return OK;
}

tError insertOrdered(tList *list, const void *data, unsigned dataSize, CompareFunc compare)
{
    tNode *new;
    int comp;

    if(!list || !data || !dataSize)
    {
        return ERROR_INVALID_ARGUMENT;
    }

    while(*list && (comp = compare((*list)->data, data)) < 0) // old - new < 0 | old < new -> move right
    {
        list = &(*list)->next;
    }

    if(comp == 0)
    {
        return ERROR_DUPLICATED_ENTRY;
    }

    new = (tNode*)malloc(sizeof(tNode));

    if(new == NULL ||
    (new->data = malloc(dataSize)) == NULL)
    {
        free(new);
        return ERROR_MEMORY_ALLOCATION;
    }

    memcpy(new->data, data, dataSize);
    new->dataSize = dataSize;
    new->next = *list;
    *list = new;

    return OK;
}

tError getHead(tList *list, void *data, unsigned dataSize)
{
    if(!list || !data || !dataSize)
    {
        return ERROR_INVALID_ARGUMENT;
    }

    memcpy(data, (*list)->data, minimum(dataSize, (*list)->dataSize));

    return OK;
}

tError getTail(tList *list, void *data, unsigned dataSize)
{
    if(!list || !data || !dataSize)
    {
        return ERROR_INVALID_ARGUMENT;
    }

    while(*list)
    {
        list = &(*list)->next;
    }

    memcpy(data, (*list)->data, minimum(dataSize, (*list)->dataSize));

    return OK;
}

tError deleteElementByKey(tList *list, const void *data, unsigned dataSize, CompareFunc compare)
{
    tNode *toFree;
    int comp;

    if(!list || !data || !dataSize)
    {
        return ERROR_INVALID_ARGUMENT;
    }

    while(*list && (comp = compare((*list)->data, data)) != 0) // old - new < 0 | old < new -> move right
    {
        list = &(*list)->next;
    }

    if(comp != 0)
    {
        return ERROR_NOT_FOUND;
    }

    toFree = *list;
    *list = toFree->next;

    free(toFree->data);
    free(toFree);

    return OK;
}

tError mapList(tList *list, ActionFunc action, void *context)
{
    if(!list || !action)
    {
        return ERROR_INVALID_ARGUMENT;
    }

    while(*list)
    {
        action((*list)->data, context);

        list = &(*list)->next;
    }

    return OK;
}

tError showList(tList *list, ShowFunc show)
{
    if(!list || !show)
    {
        return ERROR_INVALID_ARGUMENT;
    }

    while(*list)
    {
        show((*list)->data);

        list = &(*list)->next;
    }

    return OK;
}

void freeList(tList *list)
{
    tNode *toFree;

    if(!list)
    {
        return;
    }

    while(*list)
    {
        toFree = *list;
        *list = toFree->next;
        free(toFree->data);
        free(toFree);
    }
}
