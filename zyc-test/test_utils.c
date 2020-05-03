#include <stdio.h>
#include "../zyc-libs/utils.h"

int main() {

  char* sname = "hello";
  char dname[5] = {0};
  printf("sname: %s\n", sname);
  printf("dname: %s\n", dname);

  cpystr(dname, sname);
  printf("After cpystr, dname: %s\n", dname);

  int isEqual = cmpstr(dname, sname);
  if (isEqual) {
    printf("'%s' and '%s' Is equal!\n", sname, dname);
  } else {
    printf("'%s' and '%s' Is Not equal!\n", sname, dname);
  }
  isEqual = cmpstr("how", "how");
  if (isEqual) {
    printf("'how' and 'how' Is equal!\n");
  } else {
    printf("'how' and 'how' Is Not equal!\n");
  }
  isEqual = cmpstr("what", "why");
  if (isEqual) {
    printf("'what' and 'why' Is equal!\n");
  } else {
    printf("'what' and 'why' Is Not equal!\n");
  }
  isEqual = cmpstr("who", "whom");
  if (isEqual) {
    printf("'who' and 'whom' Is equal!\n");
  } else {
    printf("'who' and 'whom' Is Not equal!\n");
  }
  isEqual = cmpstr("whom", "who");
  if (isEqual) {
    printf("'whom' and 'who' Is equal!\n");
  } else {
    printf("'whom' and 'who' Is Not equal!\n");
  }

  return 0;

}