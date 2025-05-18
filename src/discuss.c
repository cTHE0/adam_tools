#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void get(char *canal) {
    // Calcule la taille nécessaire pour la commande complète
    size_t len = strlen("curl https://ntfy.sh/") + strlen(canal) + strlen("/json") + 1;

    // Alloue dynamiquement la mémoire pour la commande
    char *command = malloc(len);
    if (!command) {
        perror("malloc failed");
        return;
    }

    // Crée la commande complète
    snprintf(command, len, "curl https://ntfy.sh/%s/json", canal);

    // Exécute la commande
    system(command);

    // Libère la mémoire allouée
    free(command);
}

void send(char *canal, char *message) {
    // Calcule la taille nécessaire pour la commande complète
    size_t len = strlen("curl -d \"") + strlen(message) +
                 strlen("\" https://ntfy.sh/") + strlen(canal) + 1;

    // Alloue dynamiquement la mémoire pour la commande
    char *command = malloc(len);
    if (!command) {
        perror("malloc failed");
        return;
    }

    // Crée la commande complète
    snprintf(command, len, "curl -d \"%s\" https://ntfy.sh/%s", message, canal);

    // Exécute la commande
    system(command);

    // Libère la mémoire allouée
    free(command);
}


