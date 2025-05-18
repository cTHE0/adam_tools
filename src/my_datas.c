#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include "../include/leon_the_god.h"
#include "../include/my_datas.h"

void create_data_dir_and_file() {
    const char *home = getenv("HOME");
    if (!home) {
        fprintf(stderr, "Erreur : variable d'environnement HOME non définie.\n");
        return;
    }

    char dir_path[1024];
    snprintf(dir_path, sizeof(dir_path), "%s/.adam_tools", home);

    // Créer le dossier ~/.adam_tools si besoin
    if (mkdir(dir_path, 0700) == -1) {
        if (errno != EEXIST) {
            perror("mkdir");
            return;
        }
    }

    // Préparer le chemin complet du fichier dans ce dossier
    char file_path[1100];
    snprintf(file_path, sizeof(file_path), "%s/data.txt", dir_path);

    // Ouvrir le fichier en écriture (création ou écrasement)
    FILE *f = fopen(file_path, "w");
    if (!f) {
        perror("fopen");
        return;
    }

    // Écrire un message dans le fichier
    const char *message = "This is my datas\n";
    if (fputs(message, f) == EOF) {
        perror("fputs");
        fclose(f);
        return;
    }

    fclose(f);
    printf("Fichier '%s' créé avec succès.\n", file_path);
}

void print_datas(){
	int nb_lines = count_lines("~/.adam_tools");
	char *line;
	for (int i=0; i< nb_lines; i++){
		line = get_line("~/.adam_tools", i);
		printf("%s", line);
		printf("\n");
	}
}


void clear_file(const char *filename) {
    FILE *f = fopen(filename, "w");  // ouvrir en mode écriture écrase le fichier
    if (f) {
        fclose(f);  // fermer immédiatement suffit à vider le fichier
    } else {
        perror("fopen");
    }
}
