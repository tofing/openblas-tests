#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cblas.h>

#define EPSILON 1e-8
#define SUCCESS 0
#define FAILURE 1

int compare_double(double a, double b, double epsilon) {
    return fabs(a - b) < epsilon;
}

int test_daxpy() {
    printf("Testing cblas_daxpy... ");
    int n = 5;
    double alpha = 2.0;
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y[] = {1.0, 1.0, 1.0, 1.0, 1.0};
    double expected[] = {3.0, 5.0, 7.0, 9.0, 11.0};
    
    cblas_daxpy(n, alpha, x, 1, y, 1);
    
    for (int i = 0; i < n; i++) {
        if (!compare_double(y[i], expected[i], EPSILON)) {
            printf("FAILED (y[%d]=%f, expected %f)\n", i, y[i], expected[i]);
            return FAILURE;
        }
    }
    printf("PASSED\n");
    return SUCCESS;
}

int test_ddot() {
    printf("Testing cblas_ddot... ");
    int n = 5;
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double y[] = {2.0, 3.0, 4.0, 5.0, 6.0};
    double expected = 70.0;
    
    double result = cblas_ddot(n, x, 1, y, 1);
    
    if (!compare_double(result, expected, EPSILON)) {
        printf("FAILED (result=%f, expected %f)\n", result, expected);
        return FAILURE;
    }
    printf("PASSED\n");
    return SUCCESS;
}

int test_dscal() {
    printf("Testing cblas_dscal... ");
    int n = 5;
    double alpha = 3.0;
    double x[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double expected[] = {3.0, 6.0, 9.0, 12.0, 15.0};
    
    cblas_dscal(n, alpha, x, 1);
    
    for (int i = 0; i < n; i++) {
        if (!compare_double(x[i], expected[i], EPSILON)) {
            printf("FAILED (x[%d]=%f, expected %f)\n", i, x[i], expected[i]);
            return FAILURE;
        }
    }
    printf("PASSED\n");
    return SUCCESS;
}

int test_dnrm2() {
    printf("Testing cblas_dnrm2... ");
    int n = 3;
    double x[] = {3.0, 4.0, 0.0};
    double expected = 5.0;
    
    double result = cblas_dnrm2(n, x, 1);
    
    if (!compare_double(result, expected, EPSILON)) {
        printf("FAILED (result=%f, expected %f)\n", result, expected);
        return FAILURE;
    }
    printf("PASSED\n");
    return SUCCESS;
}

int test_idamax() {
    printf("Testing cblas_idamax... ");
    int n = 5;
    double x[] = {1.0, -5.0, 3.0, 2.0, 4.0};
    int expected = 1;
    
    int result = cblas_idamax(n, x, 1);
    
    if (result != expected) {
        printf("FAILED (result=%d, expected %d)\n", result, expected);
        return FAILURE;
    }
    printf("PASSED\n");
    return SUCCESS;
}

int main() {
    int passed = 0, total = 0;
    
    printf("\n=== CBLAS Level 1 Tests ===\n");
    
    total++; if (test_daxpy() == SUCCESS) passed++;
    total++; if (test_ddot() == SUCCESS) passed++;
    total++; if (test_dscal() == SUCCESS) passed++;
    total++; if (test_dnrm2() == SUCCESS) passed++;
    total++; if (test_idamax() == SUCCESS) passed++;
    
    printf("\n=== Results: %d/%d tests passed ===\n", passed, total);
    return (passed == total) ? 0 : 1;
}
