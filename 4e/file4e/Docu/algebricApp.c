#include <stdio.h>
// descrivono cosa fa la funz

/// @brief compute add of two numbers
/// @param a first parameter
/// @param b second parameter
/// @return sum of the two numbers
int add(int a, int b)
{
    return a + b;
}

/// @brief  compute mul of two numbers
/// @param a first parameter
/// @param b second parameter
/// @return product of the two numbers
int mul(int a, int b)
{
    return a * b;
}

/// @brief compute sub of two numbers
/// @param a first parameter
/// @param b second parameter
/// @return subof of the two numbers
int sub(int a, int b)
{
    return a - b;
}

/// @brief compute division of two numbers
/// @param a first parameter
/// @param b first parameter
/// @return division of the two numbers
double division(int a, int b)
{
    return a / b;
}

/// @brief non ha parametri, main function
void main()
{
    printf("%d\n", add(6, 3));
    printf("%d\n", mul(6, 3));
    printf("%d\n", sub(6, 3));
    printf("%f\n", division(6, 3));
}
