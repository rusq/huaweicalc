#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "encrypt.h"

int main(int argc, char* argv[]) {

char codebuf[40];
int opt;
int ff=0;

while ((opt = getopt(argc, argv, "fF123hH")) != -1) {
  switch (opt) {
   case 'h':
   case 'H':
     printf(
"\n\n *** Калькулятор кодов разблокировки модемов HUAWEI ***\n\n\
    %s [-f123] IMEI\n\n\
    -f - только flash-код\n\
    -1 - только код v1\n\
    -2 - только код v2\n\
    -3 - только код v201\n\n",argv[0]);
    return 0;
   case 'f':
   case 'F':
     ff=1;
     break;
   case '1':
     ff=2;
     break;
   case '2':
     ff=3;
     break;
   case '3':
     ff=4;
     break;
  }
}

if (optind >= argc) {
  printf("\n Не указан IMEI\n\n");
  return 1;
}

if (strlen(argv[optind]) != 15) {
  printf("\n Неправильная длина IMEI\n");
  return 1;
}

switch (ff) {
  case 0:
    encrypt_v1(argv[optind],codebuf,"e630upgrade");
    printf("\n Flash code        = %s",codebuf);

    encrypt_v1(argv[optind],codebuf,"hwe620datacard");
    printf("\n Encrypt_v1 code   = %s",codebuf);

    calc2(argv[optind],codebuf);
    printf("\n Encrypt_v2 code   = %s",codebuf);

    calc201(argv[optind],codebuf);
    printf("\n Encrypt_v201 code = %s\n\n",codebuf);
    break;

  case 1:
    encrypt_v1(argv[optind],codebuf,"e630upgrade");
    printf("%s\n",codebuf);
    break;

  case 2:
    encrypt_v1(argv[optind],codebuf,"hwe620datacard");
    printf("%s\n",codebuf);
    break;

  case 3:
    calc2(argv[optind],codebuf);
    printf("%s\n",codebuf);
    break;

  case 4:
    calc201(argv[optind],codebuf);
    printf("%s\n",codebuf);
    break;
}

return 0;
}
