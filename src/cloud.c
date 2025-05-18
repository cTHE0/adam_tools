#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void push(const char *file_name) {
    if (!file_name) {
        fprintf(stderr, "Nom de fichier invalide\n");
        return;
    }

    // Taille de la commande = parties fixes + nom de fichier + sécurité
    size_t len = strlen("curl -s -F file=@") + strlen(file_name) +
                 strlen(" https://0x0.st") + 1;

    char *command = malloc(len);
    if (!command) {
        perror("malloc failed");
        return;
    }

    // Construction sécurisée de la commande (pas de guillemets inutiles)
    snprintf(command, len, "curl -s -F file=@%s https://0x0.st", file_name);

    // Exécution
    int status = system(command);
    if (status == -1) {
        perror("Échec de l'exécution de la commande");
    }

    free(command);
}

void get_file(const char *address) {
    if (!address) {
        fprintf(stderr, "Adresse invalide\n");
        return;
    }

    size_t len = strlen("wget -q https://0x0.st/") + strlen(address) + 1;
    char *command = malloc(len);
    if (!command) {
        perror("malloc failed");
        return;
    }

    snprintf(command, len, "wget -q https://0x0.st/%s", address);

    int status = system(command);
    if (status == -1) {
        perror("Échec de l'exécution de wget");
    }

    free(command);
}


