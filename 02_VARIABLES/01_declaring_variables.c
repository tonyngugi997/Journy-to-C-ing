#include<stdio.h>

//int main() is the main starting point of all C programs
int main() {
  //now lets declaer a variable to store the data from the example
  char username[50] = "Tony";
  char password[50] = "IloveC";
  int age = 50;
  char gender[1] = "M";

  //lets print the values

  printf("the username is %s\n", username);
  printf("the age is %d\n", age);
  printf("the password is %s\n", password);
  printf("the gender is %d\n", gender);

  
  return 0;
  
  
}