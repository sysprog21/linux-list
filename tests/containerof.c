#include <assert.h>
#include <stddef.h>
#include "list.h"

struct teststruct {
    int a;
    int b;
};

int main(void)
{
    struct teststruct item;

    assert(&item == container_of(&item.b, struct teststruct, b));

    return 0;
}
