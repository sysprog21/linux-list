#include <assert.h>
#include <stddef.h>
#include "list.h"

#include "common.h"

int main(void)
{
    struct listitem item;

    assert(&item == list_entry(&item.list, struct listitem, list));

    return 0;
}
