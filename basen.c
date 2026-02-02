/* binary.c -- prints integer in binary form */
#include <stdio.h>

void to_base_n(unsigned long n, int base);

int main(void)
{
	unsigned long number;
    int base;

	printf("Enter base (2-16): ");
    scanf("%d", &base);

	if (base < 2 || base > 16)

	{
		printf("Error: base must be between 2 and 16. \n");
        return 1;
	}

	printf("Enter an integer(q to quit):\n");
    while (scanf("%lu", &number) == 1)
   {
        if (base == 8)
            printf("Equivalent in base 8: 0");
        else if (base == 16)
            printf("Equivalent in base 16: 0x");
        else
            printf("Equivalent in base %d: ", base);

        to_base_n(number, base);
        putchar('\n');

        printf("Enter an integer (q to quit):\n");
    }
    printf("Done. \n");
    return 0;
}


void to_base_n(unsigned long n, int base)  /* recursive function */
{
	int r;
    char digits[] = "012345678abcdef";

	r = n % base;
	if (n >= base)
		to_base_n(n / base, base);

	putchar(digits[r]);
	
}