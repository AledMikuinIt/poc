#include <stddef.h>
#include <stdio.h>
#include "ressourceManager.h"

int main() {

    RessourceManager *t = create_rm(10);

    
    for(int i =0; i<10; i++) {
        printf("%p\n", (void*)t->handles[i]);
        printf("%u\n", t->handles[i]->val);
    }
    

    // Free
    free_rm(t);

    return 0;
}

