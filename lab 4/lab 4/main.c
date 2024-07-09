#include "Header.h"
//Part 1
int main(void) {
  int n1 = 10, n2 = 42, list[] = { 6, 8, 42, 3, 2, 2, -6 };
  int* const p1 = &n1; //Yes 
  const int* p2 = &n1;
  int* p3 = list;
  const int* const p4 = NULL;
  *p1 = 15;//yes
  p1 = &n2;//no
  p2 = &n2;//yes
  *p2 = 67;//no
  p3[4] = 67;//yes
  list = &n1;//no
  p4 = list;//no
  *p4 = 25;//no







  return 0;
}