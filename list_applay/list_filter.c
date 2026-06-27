#include "list.h"
#include <stdlib.h>

int cmp(void *a, void *b)
{
    if(*(int *)a == *(int *)b)
        return 0;
    return 1;
}
void	list_filter(ListNode **begin, void *ref, int (*cmp)(void *, void *))
{
    ListNode *trav;
    ListNode *prev;
    void *tmp;

    if(!begin || !*begin || !ref || !cmp)
        return;

    prev = NULL;
    trav = *begin;

    while(trav)
    {
        if(cmp(trav->data, ref) == 0)
        {
            tmp = trav;
            if(prev == NULL)
            {
                *begin = trav->next;
            }
            else
                prev->next = trav->next;
            trav = trav->next;

            free(tmp);
        }
        else
        {
            prev = trav;
            trav = trav->next;
        }
    }
}
# include <stdio.h>

int cmp_val(void *b1, void *b2)
{
    if(*(int *)b1 == *(int *)b2) // 4  == 5
    {
        return 0;
    }
    return 1;
}
void push(ListNode **node, int data_add)
{
    ListNode *new;
    ListNode *tmp;
    int *data;

    data = malloc(sizeof(int));
    *data = data_add;

    new = malloc(sizeof(ListNode));
    new->data = data;
    new->next = NULL;

    if(!*node)
    {
        *node = new;
        return;
    }
    tmp = *node;
    while(tmp->next)
        tmp = tmp->next;

    tmp->next = new;
}
void print_list(ListNode *node)
{
    while(node)
    {
        printf("%d ", *(int*) node->data);
        node = node->next;
    }
}
int main()
{
    ListNode *head = NULL;
    int data_rem = 4;

    push(&head, 4);
    push(&head, 2);
    push(&head, 4);
    push(&head, 7);
    push(&head, 9);

    print_list(head);
    printf("\n");
    list_filter(&head, &data_rem, cmp_val);

    print_list(head);
    printf("\n");
}