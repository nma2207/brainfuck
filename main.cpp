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
	printf("����� ���������� � ������������� BrainFuck! \n\n");
	printf("8 ������, ��� ������ ������� ���������� ���� ������������� �� BrainFuck:\n");
	printf("1) > - ������� � ��������� ������\n");
	printf("2) < - ������� � ���������� ������\n");
	printf("3) + - ��������� �������� � ������� ������ �� 1\n ");
	printf("4) - - ��������� �������� � ������� ������ �� 1\n");
	printf("5) . - ���������� �������� �� ������� ������\n");
	printf("6) , - ������ ����� �������� ������� ������\n");
	printf("7) [ - ���� �������� ������� ������ ����, ������ ������ �� ������ ���������, ��������� �� ��������������� ]\n");
	printf("8) ] - ���� �������� ������� ������ �� ����, ������� ����� �� ������ �� ������ [\n");
	printf("\n��� ����, �������� � ������� ��������� �� BrainFuck, ������� 1, ����� ��������� ������� ��������� � txt ����� ������� 2\n");
	int k;
	scanf("%d", &k);
	printf("\n");
	const int N = 1000000;
	char program[N];
	if (k == 1)
	{
		printf("��� ���������:\n\n");
		scanf("%s", program);
	}
	else
	{
		printf("������� ���� � ���������� �����\n");
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
		printf("\n��� ���������:\n\n");
		printf("%s\n\n",program);
	}
	printf("��������� ������ ���������: \n\n");
	int resultat = BrainFuckArbeit(program);
	if (resultat == 0)
		printf("\n��������� ���������!\n");
	else
		printf("\n � ���� ���� ������!\n");
	system("pause");
	return 0;

}