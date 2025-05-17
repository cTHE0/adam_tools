#ifndef BINARY_H
#define BINARY_H

typedef struct {
    unsigned char *buffer;
    long buffer_size; // nombre d'octets du buffer
} Buffer;

Buffer read_file(const char *filename);
void print_octet(unsigned char octet);
void print_binary(const char *filename, int nb_octets);

#endif
