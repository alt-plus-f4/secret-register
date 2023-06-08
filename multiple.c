#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 30

int main() {
  char** users = NULL;
  char* user = malloc(MAX_USERNAME_LENGTH * sizeof(char)); 

  size_t amount_of_users = 0, user_exists = 0;

  do {
    printf("Who is using this diary? \n");
    scanf("%s", user);
    printf("\n%s", user);
  } while (strlen(user) >= MAX_USERNAME_LENGTH);

  users = malloc(sizeof(char*)); 

  printf("\nasd");
  for (int i = 0; i < amount_of_users; i++) {
    if (strcmp(user, users[i]) == 0) { // Checking if user already exists
      user_exists = 1;
      // input function here
      break;
    }
  }

  if (!user_exists) { // If user doesn't exist, add him
    users[amount_of_users] = malloc(MAX_USERNAME_LENGTH * sizeof(char)); 
    strcpy(users[amount_of_users], user);
    amount_of_users++;
    // input function here
  }

  return 0;
}