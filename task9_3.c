#include <stdio.h>
#include <stdlib.h>

int main() {
    system("echo 'Test file' > /tmp/userfile.txt");
    printf("File created by user\n");

    printf("Copy file from root...\n");
    system("sudo cp /tmp/userfile.txt ~/rootcopy.txt");
    system("sudo chown root:root ~/rootcopy.txt");

    printf("Trying to change file...\n");
    int ret = system("echo 'Adding new line' >> ~/rootcopy.txt");
    if (ret != 0)
        printf("Can not change file: access denied\n");

    printf("Trying to delete file...\n");
    ret = system("rm ~/rootcopy.txt");
    if (ret != 0)
        printf("Can not delete file: permission denied\n");

    return 0;
}
