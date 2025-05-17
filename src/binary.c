#include <stdio.h>
#include <stdlib.h>
#include "../include/binary.h"

// Lire le contenu d'un fichier binaire et retourner un Buffer structuré
Buffer read_file(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return (Buffer){NULL, 0};

    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    rewind(f);
    if (filesize <= 0) { fclose(f); return (Buffer){NULL, 0}; }

    unsigned char *buffer = malloc(filesize);
    if (!buffer) { fclose(f); return (Buffer){NULL, 0}; }

    size_t read_bytes = fread(buffer, 1, filesize, f);
    fclose(f);
    if (read_bytes != (size_t)filesize) {
        free(buffer);
        return (Buffer){NULL, 0};
    }

    return (Buffer){buffer, filesize};
}

// Affiche les 8 bits d'un octet
void print_octet(unsigned char octet){
    for (int i = 7; i >= 0; i--) {
        unsigned char bit = (octet >> i) & 1;
        printf("%u", bit);
    }
    printf(" "); // ajout pour aérer la sortie
}

// Affiche les bits de N octets d’un fichier
void print_binary(const char *filename, int nb_octets){
    Buffer buf = read_file(filename);
    if (buf.buffer == NULL || buf.buffer_size == 0) {
        printf("Erreur : impossible de lire le fichier\n");
        return;
    }

    for (int i = 0; i < nb_octets && i < buf.buffer_size; i++) {
        print_octet(buf.buffer[i]);
    }
    printf("\n");

    free(buf.buffer); // libération du buffer alloué
}

