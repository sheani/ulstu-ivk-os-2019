#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/mman.h>

int main()
{
    printf("������������ ������ 2.��������� ��������� ������ �����-21 ���������� �.�.\ n");
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/");//��������� ����� ���������� ��� ����������

    if (!dir)
      {
        perror("diropen");//������� ������
        exit(1);
      };

    while ( (entry = readdir(dir)) != NULL)
      {
        printf("%lu - %s [%d] %d\n",entry->d_ino, entry->d_name, entry->d_type, entry->d_reclen);
      };

    closedir(dir);
}
