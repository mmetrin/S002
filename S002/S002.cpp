// S002.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	char s[256];
	char t[256];
	char firststr[] = "Enter first string\n";
	char secondstr[] = "Enter second string\n";
	char f[] = "%s";
	char resultmore[] = "1\n";
	char resultless[] = "-1\n";
	char resultequal[] = "0\n";
	_asm {
		// ввод первой строки
		lea ebx, firststr
		push ebx
		lea ecx, f
		push ecx
		call printf
		add esp, 8

		// чтение первой строки
		lea ebx, s
		push ebx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8

		// ввод второй строки
		lea ebx, secondstr
		push ebx
		lea ecx, f
		push ecx
		call printf
		add esp, 8
		// чтение второй строки
		lea ebx, t
		push ebx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8

		// подготовка цикла прохода первой строки
		lea ebx, s
		dec ebx
		lea ecx, t
		dec ecx

		b1 :
		inc ebx
			inc ecx
			mov al, [ebx]
			mov dl, [ecx]

			cmp al, 0
			je b2 // поиск и обнаружение конца первой строки

			cmp dl, 0
			je f3 // найден конец второй строки - первая строка оказалась больше 
			cmp al, dl
			je b1 // продолжаем цикл если эквивалентны символы в первой и во второй строке 

			jb f4 // символ в первой строке меньше символа во второй
			jmp f3 // символ во второй больше

			b2 : // конец первой строки
		cmp dl, 0
			je f5 // конец второй строки - строки эквивалентны
			jmp f4 // первая строка меньше

			f3 :  // первая строка больше
		lea ebx, resultmore
			push ebx
			lea ecx, f
			push ecx
			call printf
			add esp, 8
			jmp end

			f4 : // первая строка меньше
		lea ebx, resultless
			push ebx
			lea ecx, f
			push ecx
			call printf
			add esp, 8
			jmp end

			f5 : // строки эквивалентны
		lea ebx, resultequal
			push ebx
			lea ecx, f
			push ecx
			call printf
			add esp, 8

			end:
	}
}

