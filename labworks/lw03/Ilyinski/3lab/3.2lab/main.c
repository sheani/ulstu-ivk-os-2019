#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("Лабораторная работа №3.2 Ильинский М.В. ИСТбд-22\n");
    pid_t pid, ppid;
    int x = 10;
    /* При успешном создании нового процесса с этого места псевдопараллельно
    начинают работать два процесса: старый и новый */
    /* Узнаем идентификаторы текущего и родительского процесса (в каждом из
    процессов !!!) */
    ppid = getppid();
    pid = getpid();
    (void)fork();
    /* Перед выполнением следующего выражения значение переменной x в
    обоих процессах равно 0 */
    for (int i = 0; i<10; i++)
    {
    x++;
    /* Печатаем значения PID, PPID и вычисленное значение переменной a (в
    каждом из процессов !!!) */
    printf("pid = %d, ppid = %d, result = %d\n", (int)pid, (int)ppid, x);
    }
    return 0;
}