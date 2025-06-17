#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Файли в домашній теці:\n");
    system("ls -l ~");

    printf("\nФайли в /usr/bin:\n");
    system("ls -l /usr/bin");

    printf("\nФайли в /etc:\n");
    system("ls -l /etc");

    printf("\nСпроба читання файлу /etc/shadow:\n");
    system("cat /etc/shadow");

    printf("\nСпроба записати у /etc/passwd:\n");
    system("echo 'Тест' >> /etc/passwd");

    printf("\nСпроба виконати програму /usr/bin/ls:\n");
    system("/usr/bin/ls");

    return 0;
}
