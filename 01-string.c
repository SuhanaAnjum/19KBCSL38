#include <stdio.h>

int main(void) {
  char STR[100], PAT[100], REP[100], ANS[100];
  int pat, ans, str, m, flag = 0;
  printf("Enter the MAIN string: ");
  gets(STR);
  printf("Enter the PATTERN string: ");
  gets(PAT);
  printf("Enter the REPLACE string: ");
  gets(REP);

  pat = m = str = ans = 0;
  while (STR[str] != '\0') {
    if (STR[m] == PAT[pat]) {
      pat++;
      m++;
      flag = 1;
      if (PAT[pat] == '\0') {
        for (int rep = 0; REP[rep] != '\0'; rep++, ans++)
          ANS[ans] = REP[rep];
        pat = 0;
        str = m;
      }
    } else {
      ANS[ans] = STR[str];
      ans++;
      str++;
      m = str;
      pat = 0;
    }
  }

  if (flag == 0)
    printf("Pattern not found\n");
  else {
    ANS[ans] = '\0';
    printf("The resultant string is: %s\n", ANS);
  }
}
