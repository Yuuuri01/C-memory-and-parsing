#include "list.h"
# include <stdlib.h>


int cmp(int a, int b)
{
    if(a > b)
        return 0;
    return 1;
}
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list *trave;
    int access;
    if(!lst || !cmp)
        return NULL;

    trave = lst;
    access = 1;
    while(access)
    {
        access = 0;
        trave = lst;
        while(trave->next)
        {
            if(cmp(*(int *)trave->data, *(int *)trave->next->data) == 0)
            {
                void *tmp = trave->data;
                trave->data = trave->next->data;
                trave->next->data = tmp;
                access = 1;
            }
            trave = trave->next;
        }
    }
    return lst;
}
# include <stdio.h>
void print_list(t_list *node)
{
    if(!node)
        return;
    printf("%d\n", *(int *)node->data);
    print_list(node->next);
}
int main()
{
    t_list *head;

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    int a = 5;
    int b = 2;
    int c = 1;

    node1->data = &a;
    node1->next = node2;

    node2->data = &b;
    node2->next = node3;

    node3->data = &c;
    node3->next = NULL;

    head = node1;
    t_list *new = sort_list(head, cmp);
    print_list(new);

}