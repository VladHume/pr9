#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Результат whoami:\n");
    system("whoami");

    printf("\nРезультат id:\n");
    system("id");

    return 0;
}
