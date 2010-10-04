#ifndef WIN_PTHREADS_BARRIER_H
#define WIN_PTHREADS_BARRIER_H

#define LIFE_BARRIER 0xBAB1FEED
#define DEAD_BARRIER 0xDEADB00F

#define _PTHREAD_BARRIER_FLAG (1<<30)

#define CHECK_BARRIER(b)  { \
    if (!(b) || ( ((barrier_t *)(*b))->valid != (unsigned int)LIFE_BARRIER ) ) return EINVAL; }

typedef struct barrier_t barrier_t;
struct barrier_t
{
    int valid;
    int count;
    int total;
    pthread_mutex_t m;
    pthread_cond_t c;
};

#endif
