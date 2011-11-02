#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"
LIST_HEAD(qhead);
void vfnenqueue()
{
    struct stQueue *ptr = NULL;
    int iLocalData = 0;
    ptr = (struct stQueue *)malloc(sizeof(struct stQueue));
    if(ptr == NULL)
    {
        printf("malloc fail\n");
        return;
    }
    printf("please input data\n");
    scanf("%d",&iLocalData);
    ptr->iData = iLocalData;
    list_add_tail(&(ptr->list), &qhead);
}
void vfndequeue()
{
    struct list_head *ptr = qhead.next;
    if(list_empty(&qhead))
    {
        printf("empty queue\n");
        return;
    }
    list_del(ptr);
    free(ptr);
}
void vfnprintqueue(void)
{
    struct list_head *ptr;
    struct stQueue *entry;
    if(list_empty(&qhead))
    {
        printf("--------------------------------------------\n");
        printf("empty queue\n");
        printf("--------------------------------------------\n");
        return;
    }
    printf("------------------------------------------------\n");
    printf("head=>");
    list_for_each(ptr, &qhead)
    {
        entry = list_entry(ptr, struct stQueue, list);
        printf("%d",entry->iData);
        if(list_is_last(&(entry->list),&qhead))
        {

        }else{
            printf("->");
        }
    }
    printf("\n");
    printf("----------------------------------------------------\n");
}
void vfnreplace(int num)
{
    struct list_head *ptr;
    struct stQueue *entry;
    int iLocalData = 0;
    struct stQueue *ptr1 = NULL;
    ptr1 = (struct stQueue *)malloc(sizeof(struct stQueue));
    printf("please input replace data\n");
    scanf("%d",&iLocalData);
    ptr1->iData = iLocalData;
    if(list_empty(&qhead))
    {
        printf("empty queue\n");
        return;
    }
    list_for_each(ptr, &qhead)
    {
        entry = list_entry(ptr, struct stQueue, list);
        if(entry->iData == num)
        {
            list_replace(&(entry->list), &(ptr1->list));
            return;
        }

    }
    printf("no target number\n");
}
void vfncheckqueue()
{
    struct list_head *ptr;
    struct stQueue *entry;
    int iFlag = 0;
    if(list_empty(&qhead))
    {
        printf("empty queue\n");
        return;
    }
    list_for_each(ptr, &qhead)
    {
        entry = list_entry(ptr, struct stQueue, list);
        if(entry->iData > 10)
        {
            printf("has number greater than 10\n");
            iFlag = 1;
        }
    }
    if(iFlag == 0)
    {
        printf("no number greater than 10\n");
    }
}
