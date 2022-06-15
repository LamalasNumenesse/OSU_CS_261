#include <stdio.h>
#include <stdlib.h>

struct Student
{
  char * name;
  float gpa;
  int id;
  void* extra_info;
};

void print_student(struct Student* s){
  printf("%s\n", s->name);
  printf("%f\n", s->gpa);
  printf("%i\n", s->id);
  printf("%s\n", s->extra_info);
}

int main (){
  struct Student a;
  a.name = "Blah";
  a.gpa = 4.0;
  a.id = 789;
  a.extra_info = "90X4567";
  //print_student(&a);
}