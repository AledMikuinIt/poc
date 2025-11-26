#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Object {
    struct Object *next;    // pointeur principal
    struct Object *alt;     // pointeur alternatif
    struct Object *meta;    // pointeur additionel
    int val;     // valeur

} Object;

typedef struct RessourceManager {
    Object **handles; // tableau de pointeurs
    size_t num_objects; 
} RessourceManager;


RessourceManager* create_rm(size_t n) {
    RessourceManager* rm = malloc(sizeof(RessourceManager));    // on crée un tableau de la taille de la struct
    rm->num_objects = n;                                              // le nombre d'objet souhaité
    rm->handles = malloc(n * sizeof(Object*));                  // les handles ont la taille du nombre de pointeurs de taille des pointeurs Objet

    for(int i = 0; i < n; i++) {
        rm->handles[i] = malloc(sizeof(Object));                // handle prends taille struct objet
        rm->handles[i]->val = i;                                        // val = i comme ca c'est un peu comme l'id
        rm->handles[i]->next = (i < n-1) ? rm->handles[i+1] : NULL;     // le handle pointe vers le suivant, mais a la fin il pointe vers NULL
        rm->handles[i]->alt = NULL;                                     // pointe vers NULL
        rm->handles[i]->meta = NULL;                                    // pointe vers NULL
    }
    return rm;
}

int main() {

    RessourceManager *t = create_rm(10);

    
    for(int i =0; i<10; i++) {
        printf("%p\n", (void*)t->handles[i]);
        printf("%u\n", t->handles[i]->val);
    }
    
    


    return 0;
}

