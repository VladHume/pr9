#include <stdio.h>
#include <stdlib.h>

int main() {
    system("echo 'Test file' > /tmp/userfile.txt");
    printf("Файл створено користувачем\n");

    printf("Копіюємо файл від імені root...\n");
    system("sudo cp /tmp/userfile.txt ~/rootcopy.txt");
    system("sudo chown root:root ~/rootcopy.txt");

    printf("Спроба змінити файл...\n");
    int ret = system("echo 'Додаємо рядок' >> ~/rootcopy.txt");
    if (ret != 0)
        printf("Неможливо змінити файл: немає прав\n");

    printf("Спроба видалити файл...\n");
    ret = system("rm ~/rootcopy.txt");
    if (ret != 0)
        printf("Неможливо видалити файл: немає прав\n");

    return 0;
}
