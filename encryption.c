#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encryption.h"

char* read_file_content(FILE* f, int file_size){
    char* file_data = (char*)malloc(file_size + 1);
    char symbol = fgetc(f);
    int i;
    for(i = 0; i < file_size; symbol = fgetc(f), i++){
        file_data[i] = symbol;
    }
    file_data[i] = '\0';
    return file_data;
}

void encrypt_file(FILE* fin, int file_size, char* password){
    char* file_data = (char*)malloc(file_size + 1);
    file_data = read_file_content(fin, file_size);
    for(int i = 0; i < strlen(password); i++){
        for(int j = 0; j < file_size; j++){
            if(password[i] != file_data[j]){
                file_data[j] = file_data[j] ^ password[i];
            }
        }
    }

    rewind(fin);
    fwrite(file_data, sizeof(char), file_size, fin);
    free(file_data);
}

void decrypt_file(FILE* fin, int file_size, char* password) {
    char* file_data = read_file_content(fin, file_size);

    for(int i = strlen(password); i >= 0 ; i--){
        for(int j = 0; j < file_size; j++){
            if(password[i] != file_data[j]){
                file_data[j] = file_data[j] ^ password[i];
            }
        }
    }

    rewind(fin);
    fwrite(file_data, sizeof(char), file_size, fin);
    free(file_data);
}

int main(){
    char password[100];
    FILE* fdata = fopen("data.txt", "r+");

    if(fdata == NULL){
        printf("Error. File can't open");
        return -1;
    }
    
    fseek(fdata, 0, SEEK_END);
    int file_size = ftell(fdata);
    rewind(fdata);

    printf("Enter password: ");
    scanf("%s", password);

    rewind(fdata);
    encrypt_file(fdata, file_size, password);
    rewind(fdata);

    char* input = read_file_content(fdata, file_size);
    printf("Encrypted: %s\n", input);

    rewind(fdata);
    decrypt_file(fdata, file_size, password);
    rewind(fdata);

    input = read_file_content(fdata, file_size);
    printf("Decrypted: %s\n", input);

    fclose(fdata);

    return 0;
}
