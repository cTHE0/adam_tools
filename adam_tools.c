#include <stdio.h>
#include <stdlib.h>

void print_hello();

int main(int nb_param, char** param_list){
	print_hello();
	return 1;
}

void print_hello(){
    printf("    _       _                 _       _____           _     \n");
    printf("   / \\   __| | __ _ _ __ ___ ( )___  |_   _|__   ___ | |___ \n");
    printf("  / _ \\ / _` |/ _` | '_ ` _ \\|// __|   | |/ _ \\ / _ \\| / __|\n");
    printf(" / ___ \\ (_| | (_| | | | | | | \\__ \\   | | (_) | (_) | \\__ \\\n");
    printf("/_/   \\_\\__,_|\\__,_|_| |_| |_| |___/   |_|\\___/ \\___/|_|___/\n");
}
