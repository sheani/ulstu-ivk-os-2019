#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
//Лабораторная работа №4
//Тема:Потоковое межпроцессное взаимодействие.Межпроцессное взаимодействие через канал FIFO.
///Задание: напишите на базе предыдущего примера две программы, одна
///из которых пишет информацию в FIFO, а вторая – читает из него, так чтобы
///между ними не было ярко выраженных родственных связей (т.е. чтобы ни одна из них не была потомком другой).
//Выполнила студентка гр. ИСТбд-22 Тулисова А.А.
int main() {
	int fd;
	size_t size;
	char result[1024];
	printf("Открываем FIFO на чтение...\n");
	fd = open("/home/student/Documents/4_41/fifo", O_RDONLY);
    printf("Начало чтения...\n");
	char *s = result;// считываемый символ
	do {
		size = read(fd, s, 1);
		s++;
	} while (size != 0);//считоваем по одному символу пока они не закончатся
	printf("Данные прочитаны\n");
	printf("Результат: %s\n", result);
	close(fd);

	return 0;
}
