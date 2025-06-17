#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Вміст /etc/shadow:\n");
    system("sudo cat /etc/shadow");
    return 0;
}
