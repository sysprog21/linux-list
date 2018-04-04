#ifndef PRIVATE_COMMON_H
#define PRIVATE_COMMON_H

#include <stddef.h>
#include <stdint.h>

#include "list.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

struct listitem {
    uint16_t i;
    struct list_head list;
};

static inline uint8_t getnum(void)
{
    static uint16_t s1 = UINT16_C(2);
    static uint16_t s2 = UINT16_C(1);
    static uint16_t s3 = UINT16_C(1);

    s1 *= UINT16_C(171);
    s1 %= UINT16_C(30269);

    s2 *= UINT16_C(172);
    s2 %= UINT16_C(30307);

    s3 *= UINT16_C(170);
    s3 %= UINT16_C(30323);

    return s1 ^ s2 ^ s3;
}

static uint16_t get_unsigned16(void)
{
    uint16_t x = 0;
    size_t i;

    for (i = 0; i < sizeof(x); i++) {
        x <<= 8;
        x |= getnum();
    }

    return x;
}

static inline int cmpint(const void *p1, const void *p2)
{
    const uint16_t *i1 = (const uint16_t *) p1;
    const uint16_t *i2 = (const uint16_t *) p2;

    return *i1 - *i2;
}

static inline void random_shuffle_array(uint16_t *operations, uint16_t len)
{
    uint16_t i;
    uint16_t j;

    for (i = 0; i < len; i++) {
        /* WARNING biased shuffling */
        j = get_unsigned16() % (i + 1);
        operations[i] = operations[j];
        operations[j] = i;
    }
}

#endif /* PRIVATE_COMMON_H */
