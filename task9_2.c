#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Contents /etc/shadow:\n");
    system("sudo cat /etc/shadow");
    return 0;
}
