#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Pour strcmp

void print_hello();
void print_binary(const char *filename, int nb_octets); 

int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "binary") == 0) {
            if (argc != 4) {
                printf("ERROR: adam_tools binary needs 2 parameters: file_name and nb_octets\n");
                return 1;
            }
            print_binary(argv[2], atoi(argv[3]));
        } else {
            printf("ERROR: Unknown command \"%s\"\n", argv[1]);
        }
    } else {
        print_hello();
    }

    return 0;
}


void print_hello(){
	printf("    _       _                 _       _____           _     \n");
	printf("   / \\   __| | __ _ _ __ ___ ( )___  |_   _|__   ___ | |___ \n");
	printf("  / _ \\ / _` |/ _` | '_ ` _ \\|// __|   | |/ _ \\ / _ \\| / __|\n");
	printf(" / ___ \\ (_| | (_| | | | | | | \\__ \\   | | (_) | (_) | \\__ \\\n");
	printf("/_/   \\_\\__,_|\\__,_|_| |_| |_| |___/   |_|\\___/ \\___/|_|___/\n");
	printf("\n \n");
	printf("Welcome to Adam_Tools! What would you like to do?\n \n");
	printf("adam_tools sha256 file_name           --> hash my_file with SHA256 algo\n");
	printf("adam_tools leon_the_god               --> glory to Leon\n");
	printf("adam_tools discuss public_key message --> send message to public_key\n");
	printf("adam_tools binary file_name nb_octets --> return the binary of the file\n");
}

typedef struct {
    unsigned char *buffer;
    long buffer_size; // nombre d'octets du buffer
} Buffer;

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

