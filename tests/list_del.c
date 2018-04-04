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

    list_del(&item.list);
    assert(list_empty(&testlist));

    return 0;
}
