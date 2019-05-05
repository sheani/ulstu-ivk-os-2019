#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf ("Лабораторная работа № 2.5\
            \nБатюшкиной А.Ю. ИСТбд-21 ");

    int fd = 0; // Файловый дескриптор
    size_t length; // Длина отображаемой части файла
    fd = open("/home/nastya/labs/2 labrab/2.6.2/txt3.txt", O_CREAT|O_RDWR, 0664);
    length=1000*sizeof(int);// Вычисляем будущую длину файла для записи в него 1000 структур
    ftruncate(fd, length);// Увеличиваем длину файла с помощью вызова ftruncate()
    //mmap -  второй этап отображения файла целиком или частично из дискового пространства в адресное пространство процесса
    int *ptr=(int*)mmap(NULL, //начало области адресного пространства, в которую будет отображен файл
                        length,
                        PROT_WRITE, //разрешена запись
                        MAP_SHARED, //полученное отображение файла впоследствии будет использоваться и другими процессами
                        fd,
                        0);// Файл отображаем с его начала (offset = 0) и до конца (length = длине файла); ptr-начальный адрес выделенной области
    close(fd);// Файловый дескриптор нам более не нужен, и мы его закрываем
    int * tmpptr = ptr;// В цикле заполняем образ файла числами; tmpptr-указатель для перемещения внутри области памяти
    if (ptr==MAP_FAILED)// Если отобразить файл не удалось – сообщаем об ошибке
    {
        printf("Mapping failed!\n");
            exit(2);
    }
    for (int i=0; i<1000; i++)
    {
            printf("%i ", *(tmpptr+i));
    }
    //Системный вызов munmap служит для прекращения отображения memory mapped файла в адресное пространство вычислительной системы
    munmap((void*)ptr, length);// Прекращаем отображать файл в память, записываем содержимое отображения на диск и освобождаем память

    return 0;
}
