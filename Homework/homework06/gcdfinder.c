*/gcc gcdFinder.c -o gcdFinder 
./gcdFinder
*/
    
#include <stdio.h>
#include <assert.h>

extern int gcd(int a, int b);

int main() {
    int num1, num2, result;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    result = gcd(num1, num2);
    printf("GCD(%d, %d) = %d\n", num1, num2, result);

    return 0;
}
