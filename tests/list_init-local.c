#include <assert.h>
#include "list.h"

int main(void)
{
    LIST_HEAD(testlist);

    assert(list_empty(&testlist));

    return 0;
}
