#include <stdio.h>

char* read_file_content(FILE* f, int file_size);
void encrypt_file(FILE* fin, int file_size, char* password);
void decrypt_file(FILE* fin, int file_size, char* password);