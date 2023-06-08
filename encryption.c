#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(char* input, char* password){
    for(int i = 0; i < strlen(password); i++){
        for(int j = 0; j < strlen(input); j++){
            if(password[i] != input[j]){
                input[j] = input[j] ^ password[i]; 
            }
        }
        }
    return input;
}

char* decrypt(char* input, char* password) {
    for(int i = strlen(password) - 1; i >= 0; i--){
        for(int j = 0; j < strlen(input); j++){
            if(password[i] != input[j]){
                input[j] = input[j] ^ password[i]; 
            }
        }
    }
    return input;
}

int main(){
  /*  char* password = (char*)malloc(100);
    char* result = (char*)malloc(100);
    char* input = (char*)malloc(100);
    char* crypted = (char*)malloc(100);
    FILE* fdata = fopen("data.txt", "r");
    if(fdata == NULL){
        printf("Error. File can't open");
        return -1;
    }
    fscanf(fdata, "%s", input);
    printf("%s", input);
    printf("\nEnter password: ");
    scanf("%s", password);

    crypted = encrypt(input, password);
    fclose(fdata);
    printf("Encrypted: %s\n", crypted);
    result = decrypt(crypted, password);
    printf("Decrypted: %s\n", result);
    fdata = fopen("data.txt", "w");
    fprintf(fdata, "%s",result);
    fclose(fdata);*/
    return 0;
}