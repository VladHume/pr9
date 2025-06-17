#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Result of whoami:\n");
    system("whoami");

    printf("\Result of id:\n");
    system("id");

    return 0;
}
