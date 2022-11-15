//Lab10_1.c З введеного тексту видаляє всі слова, що мають подвоєні літери та підраховує кількість слів у тексті.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	system("chcp 1251");
	system("cls");
	setlocale(LC_CTYPE, "ukr");
		
	int N = 100;
	char *Str = (char*) calloc(N, sizeof(char*));
	printf("\n Введіть текст: ");
	gets (Str);
	N = strlen(Str) + 1;
	Str = (char*) realloc (Str, N*sizeof(char*));
	char *Str_Duo = calloc (N, sizeof(char*));
	char *Str_Mono =  calloc(N, sizeof(char*));
	char *Buf = calloc (31,sizeof(char*));//Найдовше слово В укр мові містить 31 літеру (Книги рекордів України)
	system("cls");
	
//a) Сортує слова в масиви слів з подвоєнням і слів без подвоєння.
	int i, j, L = 0, k = 0; 
	for (i = 0; i<=N; i++)
	{
		if (Str[i] == ' ' || Str[i] == '\0')
		{
			for (j=0; j < i-L; j++)
			{
				Buf[j] = Str[j+L];
				if (toupper (Str[j+L]) == toupper (Str[j+L + 1])) k++;
			}
			if (k > 0) strcat(Str_Duo, Buf);
			else strcat(Str_Mono, Buf);
			L = i; k = 0; 
			}
		for (j = 0; j <= 31; j++)
			Buf[j] = 0;
	}
	printf("\n Ви надрукували рядок: \n");
	printf("\t"); puts(Str);
	printf ("\n ЗАВДАННЯ:");
	printf("\na) Прибрати слова з подвоєнням у введеному рядку тексту");
	
	printf("\nПодвоєння зустрічається в наступних словах:\n");
	printf("\t"); puts(Str_Duo);
	printf("\nРядок після видалення слів з подвоєнням має вигляд:\n");
	printf("\t"); puts(Str_Mono);
	printf("\nб) Порахувати кількість слів у введеному рядку");
	//б) Підрахунок кількості слів у текстовому рядку
	int Num = 0, id = 0;
	for (i = 0; Str[i] != '\0'; i++)
	{
		if (Str[i] == ' ') 
		{ 
			Num++; id = i; 
		}
	}
	if (id == (i - 1) && Str[id]==' ') printf("\n Речення закінчується пробілом");
	else Num = Num + 1;
	
	printf("\n \t Кількість слів у введеному тексті: %d ", Num);

	getchar();
	free(Str);
	free(Str_Duo);
	free(Str_Mono);
	free(Buf);
	return 0;
}


