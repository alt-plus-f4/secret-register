#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encryption.h"

char* read_file_content(FILE* f, int* file_size){
    char* file_data = (char*)malloc((*file_size) + 1);
    fread(file_data, *file_size, sizeof(char), f);
    return file_data;
}

void encrypt_file(FILE* fin, int* file_size, char* password){
    char* file_data = read_file_content(fin, file_size);
    for(int i = 0; i < strlen(password); i++){
        for(int j = 0; j < *file_size; j++){
            if(password[i] != file_data[j]){
                file_data[j] = file_data[j] ^ password[i];
            }
        }
    }
    rewind(fin);
    fwrite(file_data, *file_size, sizeof(char), fin);
    free(file_data);
}

void decrypt_file(FILE* fin, int* file_size, char* password) {
    char* file_data = read_file_content(fin, file_size);
    for(int i = strlen(password); i >= 0 ; i--){
        for(int j = 0; j < *file_size; j++){
            if(password[i] != file_data[j]){
                file_data[j] = file_data[j] ^ password[i];
            }
        }
    }
    rewind(fin);
    fwrite(file_data, *file_size, sizeof(char), fin);
    free(file_data);
}