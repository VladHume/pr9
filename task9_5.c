#include <stdio.h>
#include <stdlib.h>

int main() {
    system("touch /tmp/tempfile.txt");
    system("echo 'Data' > /tmp/tempfile.txt");

    printf("Change the owner to root and access rights...\n");
    system("sudo chown root:root /tmp/tempfile.txt");
    system("sudo chmod 600 /tmp/tempfile.txt");

    printf("Trying to read the file:\n");
    int ret = system("cat /tmp/tempfile.txt");
    if (ret != 0)
        printf("Reading isn`t allowed\n");

    printf("Attempt to write to file:\n");
    ret = system("echo 'New line' >> /tmp/tempfile.txt");
    if (ret != 0)
        printf("Writing isn`t allowed\n");

    return 0;
}
