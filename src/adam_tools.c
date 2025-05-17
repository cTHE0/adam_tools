#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Pour strcmp
#include "../include/binary.h"

void print_hello();

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
