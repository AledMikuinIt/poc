#include <stdio.h>
#include <stdlib.h>
#include "ressourceManager.h"


RessourceManager* create_rm(size_t n) {
    RessourceManager* rm = malloc(sizeof(RessourceManager));    // on crée un tableau de la taille de la struct
    if(!rm) return NULL;
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

void free_rm(RessourceManager *rm) {

    // Libération de mémoire 
    for(int i = 0; i < rm->num_objects; i++) {
        free(rm->handles[i]);
        rm->handles[i] = NULL;  // mettre le pointeur a NULL pour éviter les UAF
    }
    free(rm->handles);
    free(rm);

}