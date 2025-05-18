#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Pour strcmp
#include <stdint.h>
#include "../include/binary.h"
#include "../include/comp_datas.h"
#include "../include/leon_the_god.h"
#include "../include/my_datas.h"
#include "../include/discuss.h"
#include "../include/cloud.h"
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
			printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
			print_saying(argv[2]);
			printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
		}
		else {
			print_saying("Leon");
		}
	}
	else if (strcmp(argv[1], "my_datas") == 0){
		create_data_dir_and_file();
	}
	else if (strcmp(argv[1], "discuss") == 0){
		if (argc < 3) {
                printf("Choose to send or get message on your favorite canal!  \n");
                return 1;
                }
                if (strcmp(argv[2], "get") == 0){
                        if (argc < 4){
				printf("You have to precise the canal after get.\n");
			}
			else{
				get(argv[3]);
			}
                }
		else if (strcmp(argv[2], "send") == 0){
			if (argc < 5) {
				printf("You have to precise a canal and enter a message\n");
			}
			else{
				send(argv[3], argv[4]);
			}
		}
                else {
                        printf("This data_name does'nt exists. Available options: get and send\n");
                        return 1;
                }
	}
	else if (strcmp(argv[1], "cloud") == 0){
		if (argc < 3){
			printf("Choose what you want to do: get a file from the cloud or push one?\n");
		}
		else if (strcmp(argv[2], "get") == 0){
			if (argc < 4) {
				printf("You have to precise the adress of the file you want to get.\n");
			}
			else {
				get_file(argv[3]);
			}
		}
		else if (strcmp(argv[2], "push") == 0){
			if (argc < 4) {
				printf("You have precise the name of the file you want to push on cloud.\n");
			}
			else {
				push(argv[3]);
			}
		}
		else {
			printf("ERROR: Unknown command \"%s\"\n", argv[2]);
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
	printf("                                                                       ／＞　 フ\n");
	printf("                                                                      | 　_　_| \n");
	printf("    _       _                 _       _____           _             ／` ミ＿xノ \n");
	printf("   / \\   __| | __ _ _ __ ___ ( )___  |_   _|__   ___ | |___       /　　　　 |\n");
	printf("  / _ \\ / _` |/ _` | '_ ` _ \\|// __|   | |/ _ \\ / _ \\| / __|   ヽ　　 ﾉ\n");
	printf(" / ___ \\ (_| | (_| | | | | | | \\__ \\   | | (_) | (_) | \\__ \\ 　　|　|　|\n");
	printf("/_/   \\_\\__,_|\\__,_|_| |_| |_| |___/   |_|\\___/ \\___/|_|___/ ／￣|　　 |　|　|\n");
	printf("                                                                 (￣ヽ＿_ヽ_)__)\n");
	printf("                                                                    ＼二)\n");
	printf("\n \n");
	printf("Welcome to Adam_Tools! What would you like to do?\n \n");
	printf("adam_tools sha256 file_name           --> hash my_file with SHA256 algo\n");
	printf("adam_tools leon_the_god               --> glory to Leon\n");
	printf("adam_tools discuss                    --> discuss\n");
	printf("adam_tools binary file_name nb_octets --> return the binary of the file\n");
	printf("adam_tools comp_datas data_name       --> computer datas\n");
	printf("adam_tools my_datas data_name	      --> get YOUR datas\n");
	printf("adam_tools cloud                      --> push a file or get one existing on cloud\n");
	printf("\n");
}
