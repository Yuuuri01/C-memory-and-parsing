# include "list.h"

void	list_apply(ListNode *list, void (*f)(void *))
{
    ListNode *trav;

    if(!list)
        return;
    
    trav = list;
    while(trav)
    {
        f(trav->data);
        trav = trav->next;
    }
}
