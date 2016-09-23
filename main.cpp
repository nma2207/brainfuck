#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<locale.h>


using namespace std;
int BrainFuckArbeit(char*programm)
{
	int skobka = 0;
	const int N = 3000;
	char values[N];
	for (int k = 0; k < N; k++)
		values[k] = 0;
	int j = 0;
	int i = 0;
	while (programm[j] != '\0')
	{
		switch (programm[j])
		{
			case'>': i++; break;
			case'<':i--; break;
			case '+': values[i]++; break;
			case '-':values[i]--; break;
			case '.':putchar(values[i]); break;
			case',':values[i] = getchar(); break;
			case '[':
				if (values[i] == 0)
				{
					skobka = 1;
					while (programm[j] != '\0' && skobka != 0)
					{
						j++;
						switch (programm[j])
						{
							case '[': skobka++; break;
							case']':skobka--; break;
						}
					}
					if (programm[j] == '\0' && skobka != 0)
						return 1;
				}
				break;
			case ']':
				if (values[i] != 0)
				{
					skobka = 1;
					while (j > 0 && skobka != 0)
					{
						j--;
						switch (programm[j])
						{
							case '[': skobka--; break;
							case ']':skobka++; break;
						}
						if (j == 0 && skobka != 0)
							return 1;
					}
				}
				break;
			default:
				return 1; break;
		}
		j++;
	}
	return 0;
}
int main()
{
	setlocale(0, "");
	printf("ƒобро пожаловать в интерпретатор BrainFuck! \n\n");
	printf("8 команд, при помощи которых сумашедшие люди программируют на BrainFuck:\n");
	printf("1) > - перейти к следующей €чейке\n");
	printf("2) < - перейти к предыдущей €чейке\n");
	printf("3) + - увеличить значение в текущей €чейке на 1\n ");
	printf("4) - - уменьшить значение в текущей €чейке на 1\n");
	printf("5) . - напечатать значение из текущей €чейки\n");
	printf("6) , - ввести извне значение текущей €чейки\n");
	printf("7) [ - если значение текущей €чейки ноль, пройти вперед по тексту программы, следующую за соответствующей ]\n");
	printf("8) ] - если значение текущей €чейки не нуль, перейти назад по тексту на символ [\n");
	printf("\nƒл€ того, печатать в консоли программу на BrainFuck, нажмите 1, чтобы загрузить готовую программу в txt файле нажмите 2\n");
	int k;
	scanf("%d", &k);
	printf("\n");
	const int N = 1000000;
	char program[N];
	if (k == 1)
	{
		printf("код программы:\n\n");
		scanf("%s", program);
	}
	else
	{
		printf("¬ведите путь к текстовому файлу\n");
		char filename[200];
		scanf("%s", filename);
		FILE*file =fopen(filename, "r");
		char ch;
		int i = 0;
		if (file == NULL)
		{
			printf("file error!");
			system("pause");
			return 0;
		}
		while ((ch = getc(file)) != EOF)
		{
			program[i] = ch;
			i++;
		}
		program[i] = '\0';
		printf("\nкод программы:\n\n");
		printf("%s\n\n",program);
	}
	printf("результат работы программы: \n\n");
	int resultat = BrainFuckArbeit(program);
	if (resultat == 0)
		printf("\nпрограмма завершена!\n");
	else
		printf("\n в коде есть ошибка!\n");
	system("pause");
	return 0;

}