#include <assert.h>
#include "list.h"

int main(void)
{
    struct list_head testlist;

    INIT_LIST_HEAD(&testlist);
    assert(list_empty(&testlist));

    return 0;
}
