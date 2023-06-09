#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encryption.h"

char* read_file_content(FILE* f, int* file_size){
    char* file_data = (char*)malloc((*file_size) + 1);
    char symbol = fgetc(f);
    int i, j = 0;
    for(i = 0; i < *file_size; symbol = fgetc(f), i++){
        if(symbol == '\n') j++;
        file_data[i] = symbol;
    }
    file_data[i - j] = '\0';
    (*file_size) -= j;
    return file_data;
}

void encrypt_file(FILE* fin, int* file_size, char* password){
    char* file_data = read_file_content(fin, file_size);
    for(int i = 0; i < strlen(password); i++){
        for(int j = 0; j < strlen(file_data); j++){
            if(password[i] != file_data[j]){
                file_data[j] = file_data[j] ^ password[i];
            }
        }
    }

    rewind(fin);
    fwrite(file_data, sizeof(char), *file_size, fin);
    free(file_data);
}

void decrypt_file(FILE* fin, int* file_size, char* password) {
    char* file_data = read_file_content(fin, file_size);

    for(int i = strlen(password); i >= 0 ; i--){
        for(int j = 0; j < strlen(file_data); j++){
            if(password[i] != file_data[j]){
                file_data[j] = file_data[j] ^ password[i];
            }
        }
    }

    printf("%s\n", file_data);

    rewind(fin);
    fwrite(file_data, sizeof(char), *file_size, fin);
    free(file_data);
}