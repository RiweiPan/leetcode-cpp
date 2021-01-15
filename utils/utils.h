#include <stdlib.h>
#include <time.h>

static inline void init_rand(int *data, int len, int maxv)
{
    srand((unsigned int)time(NULL));
    for(int i = 0; i < len; i++) {
        data[i] = rand() % maxv;
    }
}