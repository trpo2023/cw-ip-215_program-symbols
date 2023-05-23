#include "help_func.c"

#include <ctest.h>

CTEST(is_balanced, program1)
{
    int exp = is_balanced("if (x < y) {z = x+y;}");
    const int real = 1;
    ASSERT_EQUAL(exp, real);
}

CTEST(is_balanced, program2)
{
    int exp = is_balanced("while (i < n) {a[i++] = 0;}");
    const int real = 1;
    ASSERT_EQUAL(exp, real);
}

CTEST(is_balanced, program3)
{
    int exp = is_balanced("for (int i = 0; i < n; i++) {sum += a[i];}");
    const int real = 1;
    ASSERT_EQUAL(exp, real);
}

CTEST(is_balanced, program4)
{
    int exp = is_balanced("if (x < y {z = x+y;}");
    const int real = 0;
    ASSERT_EQUAL(exp, real);
}

CTEST(is_balanced, program5)
{
    int exp = is_balanced("while (i < n {a[i++] = 0;}");
    const int real = 0;
    ASSERT_EQUAL(exp, real);
}

CTEST(is_balanced, program6)
{
    int exp = is_balanced("for (int i = 0; i < n; i++ {sum += a[i];}");
    const int real = 0;
    ASSERT_EQUAL(exp, real);
}
