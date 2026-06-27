# include "list.h"

int	detect_cycle(t_list *list)
{
    t_list *slow;
    t_list *fast;

    if(!list)
        return 0;
    slow = list;
    fast = list->next;
    while(fast && fast->next)
    {
        if(fast == slow)
            return 1;
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}
# include <stdlib.h>
# include <stdio.h>

int main()
{
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));


    int a = 10;
    int b = 20;
    int c = 30;

    node1->data = &c;
    node1->next = node2;

    node2->data = &b;
    node2->next = node3;

    node3->data = &c;
    node3->next = node1;

    t_list *head = node1;

    printf("%d\n", detect_cycle(head));
}