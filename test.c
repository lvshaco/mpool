#include "mpool.h"
#include <assert.h>

void test_mpool() {
    struct mpool* m = mpool_new(1024);
    int i;
    void* last_p = NULL;
    for (i=0; i<1024/4; ++i) {
        void *p = mpool_alloc(m, 4);
        if (last_p) {
            assert((p-last_p) == 4);
        }
        last_p = p;
    }

    void* p = mpool_alloc(m, 1024);
    p = mpool_alloc(m, 1025);
    p = mpool_alloc(m, 1020);
    p = mpool_alloc(m, 10240);
    
    mpool_dump(m); 
    mpool_delete(m);
}

int 
main(int argc, char* argv[]) {
    test_mpool();
    return 0;
}
