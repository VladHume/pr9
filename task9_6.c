#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Files in home directory:\n");
    system("ls -l ~");

    printf("\nFiles in /usr/bin:\n");
    system("ls -l /usr/bin");

    printf("\nFiles в /etc:\n");
    system("ls -l /etc");

    printf("\nAttempt to read the file /etc/shadow:\n");
    system("cat /etc/shadow");

    printf("\nAttempt to write to /etc/passwd:\n");
    system("echo 'Тест' >> /etc/passwd");

    printf("\nAttempting to execute a program /usr/bin/ls:\n");
    system("/usr/bin/ls");

    return 0;
}
