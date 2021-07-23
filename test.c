#include<stdio.h>
#include<string.h>

int main(){
  char buffer[512+1];
  fgets(buffer, 512, stdin);
  char* keyword = strtok(buffer, " ");
  char* id = strtok(NULL, " ");
  char* username = strtok(NULL, "\"");
  char* email = strtok(NULL, " \n");
  printf("Keyword: %s\n",keyword);
  printf("id: %s\n",id);
  printf("Username: %s\n",username);
  printf("Email: %s\n",email);
  return 0;
}
