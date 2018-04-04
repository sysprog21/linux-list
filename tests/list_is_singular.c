#include <assert.h>
#include "list.h"

#include "common.h"

int main(void)
{
    struct list_head testlist;
    struct listitem item1;
    struct listitem item2;

    INIT_LIST_HEAD(&testlist);
    assert(list_empty(&testlist));
    assert(!list_is_singular(&testlist));

    list_add(&item1.list, &testlist);
    assert(!list_empty(&testlist));
    assert(list_is_singular(&testlist));

    list_add(&item2.list, &testlist);
    assert(!list_empty(&testlist));
    assert(!list_is_singular(&testlist));

    return 0;
}
