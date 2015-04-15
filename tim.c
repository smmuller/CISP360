#define CONST 60
int main(void)
{int a, b, left;printf("Enter a time in mins\n");scanf("%d", &a);while (a>0){b= a/CONST;left= a % CONST;printf("%d mins is %d hours, %d mins.\n", a, b, left);printf("Enter time in mins. Num <0 to quit.\n");scanf("%d", &a);}return 0;}
