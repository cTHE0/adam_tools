#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Pour strcmp
#include <stdint.h>
#include "../include/binary.h"
#include "../include/comp_datas.h"
#include "../include/leon_the_god.h"
#include <inttypes.h> // Nécessaire pour PRIu64

void print_hello();

int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "binary") == 0) {
            if (argc != 4) {
                printf("ERROR: adam_tools binary needs 2 parameters: file_name and nb_octets\n");
                return 1;
            }
            print_binary(argv[2], atoi(argv[3]));
        }
	else if (strcmp(argv[1], "comp_datas") == 0){
		if (argc != 3) {
                printf("ERROR: adam_tools comp_datas needs 1 parameter: data_name\n");
                return 1;
            	}
		if (strcmp(argv[2], "cpu_temperature") == 0){
			float cpu_temp = get_cpu_temperature();
			printf("Your CPU has a temperature of %f°C\n", cpu_temp);
		}
		else if (strcmp(argv[2], "time") == 0){
			uint64_t time = get_exact_time();
			printf("Number of nanoseconds since 1970, 00:00:00 UTC: %" PRIu64 "\n", time);
			}
		else {
			printf("This data_name does'nt exists. Available data_name: cpu_temperature; time \n");
			return 1;
		}
	}
	else if (strcmp(argv[1], "leon_the_god") == 0){
		if (argc > 2) {
			printf("\n -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
			print_saying(argv[2]);
			printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*- \n");
		}
		else {
			print_saying("Leon");
		}
	}
	 else {
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
	printf("adam_tools comp_datas data_name       --> computer datas\n");
	printf("\n");
}
