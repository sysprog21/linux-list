#include <assert.h>
#include <stdlib.h>
#include "list.h"

#include "common.h"

int main(void)
{
    struct list_head testlist;
    struct listitem *item;
    struct list_head *li = NULL, *lis = NULL;
    size_t i;

    INIT_LIST_HEAD(&testlist);

    assert(list_empty(&testlist));

    for (i = 0; i < 5; i++) {
        item = (struct listitem *) malloc(sizeof(*item));
        assert(item);
        item->i = i;
        list_add_tail(&item->list, &testlist);
    }

    assert(!list_empty(&testlist));

    i = 0;
    list_for_each_safe(li, lis, &testlist)
    {
        item = list_entry(li, struct listitem, list);
        assert(item->i == i);
        list_del(&item->list);
        free(item);
        i++;
    }

    assert(i == 5);
    assert(list_empty(&testlist));

    return 0;
}
