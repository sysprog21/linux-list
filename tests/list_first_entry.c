#include <assert.h>
#include <stddef.h>
#include "list.h"

#include "common.h"

int main(void)
{
    struct list_head testlist;
    struct listitem item[4];
    size_t i;

    for (i = 0; i < sizeof(item) / sizeof(*item); i++)
        item[i].i = (int) i;

    INIT_LIST_HEAD(&testlist);
    assert(list_empty(&testlist));

    list_add_tail(&item[0].list, &testlist);
    assert(!list_empty(&testlist));
    assert(list_first_entry(&testlist, struct listitem, list)->i == 0);

    list_add_tail(&item[1].list, &testlist);
    assert(!list_empty(&testlist));
    assert(list_first_entry(&testlist, struct listitem, list)->i == 0);

    list_add(&item[2].list, &testlist);
    assert(!list_empty(&testlist));
    assert(list_first_entry(&testlist, struct listitem, list)->i == 2);

    list_add(&item[3].list, &testlist);
    assert(!list_empty(&testlist));
    assert(list_first_entry(&testlist, struct listitem, list)->i == 3);

    return 0;
}
