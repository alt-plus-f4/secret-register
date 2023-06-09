#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(){
    char password[100];
    FILE* fdata = fopen("data.txt", "rb+");
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
    encrypt_file(fdata, &file_size, password);
    rewind(fdata);

    char* input = read_file_content(fdata, &file_size);
    
    rewind(fdata);
    decrypt_file(fdata, &file_size, password);
    rewind(fdata);

    input = read_file_content(fdata, &file_size);

    fclose(fdata);
    return 0;
}
