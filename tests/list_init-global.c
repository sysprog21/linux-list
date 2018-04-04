#include <assert.h>
#include "list.h"

static LIST_HEAD(testlist);

int main(void)
{
    assert(list_empty(&testlist));

    return 0;
}
