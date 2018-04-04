#include <assert.h>
#include "list.h"

#include "common.h"

int main(void)
{
    struct list_head testlist;
    struct listitem item;

    INIT_LIST_HEAD(&testlist);
    assert(list_empty(&testlist));

    list_add(&item.list, &testlist);
    assert(!list_empty(&testlist));

    assert(!list_empty(&item.list));

    list_del_init(&item.list);
    assert(list_empty(&testlist));

    assert(list_empty(&item.list));

    return 0;
}
