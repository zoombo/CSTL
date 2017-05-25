#include <stdio.h>
#include <stdlib.h>
#include <thr\threads.h>
#include <stddef.h>
#include "func_h.h"
#include "TStack.h"


int divi(int number, int divisor);

#define RUN 1
#define nl printf("\n")

#define TESTDEFF




void main(void) {
	if (!RUN) {
		int i = 5;
		i = i++;
		printf("i = i++ : %d\n", i);

		i = 5;
		i = ++i;
		printf("i = ++i : %d\n", i);

		i = 5;
		i = i++ + i++;
		printf("i = i++ + i++ : %d\n", i);

		i = 5;
		i = ++i + i++;
		printf("i = ++i + i++ : %d\n", i);

		i = 5;
		i = ++i + ++i;
		printf("i = ++i + ++i : %d\n", i);

		i = 5;
		i = (i += 1) + (i += 1);
		printf("i = (i+=1) + (i+=1) : %d\n", i);

		i = 5;
		i++;
		i++;
		i = i + i;
		printf("i = 5; i++; i++; i = i + i; : %d\n", i); // Ебать мой мозг... Дважды...
	}
	if (!RUN) {
		int num;
		scanf_s("%d", &num);
		int div;
		scanf_s("%d", &div);

		printf("%d\n", divi(num, div));
	}

	if (!RUN) {

		printf("char*\t: %zd\n", sizeof(char*));
		printf("void*\t: %zd\n", sizeof(void*));
		printf("char\t: %zd\n", sizeof(char));
		printf("wchar_t\t: %zd\n", sizeof(wchar_t));
		printf("size_t\t: %zd\n", sizeof(size_t));
		printf("int\t: %zd\n", sizeof(int));
		printf("short int\t: %zd\n", sizeof(short int));
		printf("long\t: %zd\n", sizeof(long));
		printf("long long\t: %zd\n", sizeof(long long));
		printf("float\t: %zd\n", sizeof(float));
		printf("double\t: %zd\n", sizeof(double));
		printf("NULL\t: %zd\n", NULL);
		int inull = NULL;
		printf("inull\t: %zd\n", inull); nl;
		system("pause");
	}

	if (!RUN) {
		struct human iams = {
			.human_construct = human_construct,
			.human_getname = human_getname,
			.human_setname = human_setname,
		};

		iams.human_construct(&iams);
		iams.human_setname(&iams, "Dimasik\n");
		struct errstruct merr;
		errstruct_construct(&merr);
		merr = iams.human_getname(&iams);
		printf("%s : %d\n", merr.message, merr.errnum);
		merr = human_testerrret();
		printf("%s : %d\n", merr.message, merr.errnum);
		system("pause");
	}

	if (!RUN) {
		char *p1 = (char*)0x1000;
		printf("%d\n", p1);
		system("pause");
		*p1 = '1';
	}

	if (!RUN) {
		enum MyEnumTest
		{
			ZERO = 0,
			ONE = 1,
			TWO = 2
		} entest;

		entest = TWO;
		printf("%d\n", entest);

	}

	if (!RUN) {

		//printf("%d", TESTDEFF); nl; // Не работает.

	}

	if (!RUN) {

		int testarr1[3][6] = { { 1, 2, 3, 11 },{ 9, 8, 7, 70 }, {34} };
		printf("sizeof testarr1 = %d\n", sizeof testarr1);
		for (int i = 0; i < 8; i++)
			printf("%d : ", **(testarr1 + i)); // ??? 
		nl; nl;
		for (int i = 0; i < 8; i++)
			printf("%d : ", *(int*)((int)testarr1 + (sizeof(int) * 6) * i)); // ??? 
				// printf("%d : ", **(testarr1 + i)); // ???
				// printf("%d : ", *((int*)testarr1 + i)); // ???!!!

		// Я врубился! При прибавлении к указателю на двухмерный массив, прибавляется длинна строки! 
		// *(testarr1 + i)  =  ((int)testarr1 + (sizeof(int) * 6) * i)
		// ^_^ 

		nl;

		/*
		int testarr2[][5] = { {1, 2, 3, 11, 12}, {9, 8, 7, 70, 80} };
		for (int i = 0; i < 10; i++)
			printf("%d : ", *(testarr2 + i)); // ???
			// printf("%d : ", **(testarr2 + i)); // ???
			// printf("%d : ", *((int*)testarr2 + i)); // ???!!!
		nl;

		int testarr3[][3] = { {10, 11, 12}, {50, 60, 70} };
		for (int i = 0; i < 2; i++) {
			nl;
			for (int k = 0; k < 3; k++)
				printf("%d\t", &(testarr3[i][k]));
		}
		nl;
		*/

		system("pause");
	}

	if (!RUN) {
		enum MyTestEnum1
		{
			ONE = 1,
			TWO,
			THREE
		} en1;

		enum MyTestEnum2
		{
			AAA = 10,
			BBB
		} en2;

		//en1 = 3; //+
		en2 = 500;
		en1 = TWO;
		// en1 = (enum MyTestEnum1)en2; //+
		en1 = en2;


		if (en1 == 1)
			printf("en1 = 1.\n");
		if (en1 == 2)
			printf("en1 = 2.\n");
		if (en1 == 3)
			printf("en1 = 3.\n");
		printf("en1 = %d.\n", en1);


	}

	if (!RUN) {

		struct MyStruct123
		{
			int val1;
		} str123 = { 100 };

		struct MyStruct321
		{
			float val2;
		} str321 = { 100.50 };

		struct MyStruct123* str1;
		str1 = &str321;



		//printf("%d\n", (struct MyStruct321*)str1->val1); //+

		// struct MyStruct123 str123 = { 0 }; //+

	}

	if (!RUN) {

		union TestUnion1
		{
			long long l1;
			float f1;
			int i1;
			char c1;
		} testu;

		testu.l1 = 101;

		printf("%d", testu.l1); nl;
		printf("%d", testu.i1); nl;
		printf("%f", testu.f1); nl;
		printf("%c", testu.c1); nl;


	}


	if (!RUN) {

		if (RUN) {

#define TTStack_Push(X, Y) TStack_Push(X, Y, sizeof(Y))

			struct TStack myStringStack;

			TStack_init(&myStringStack);
			TTStack_Push(&myStringStack, "Johnson Large");
			TTStack_Push(&myStringStack, "Elvis");
			TTStack_Push(&myStringStack, "Kenny");

			int a = 100, b = 2200, c = 55555;
			TTStack_Push(&myStringStack, &a);
			TTStack_Push(&myStringStack, &b);
			TTStack_Push(&myStringStack, &c);

			//printf("%s", *(myStringStack.data)); nl;
			//printf("%s", *(myStringStack.data + 1)); nl;
			//printf("%s", *(myStringStack.data + 2)); nl;
			int i = myStringStack.position;
			printf("%d", *(int*)(TStack_Pop(&myStringStack))); nl;
			printf("%d", *(int*)(TStack_Pop(&myStringStack))); nl;
			printf("%d", *(int*)(TStack_Pop(&myStringStack))); nl;

			printf("%s", (char*)TStack_Pop(&myStringStack)); nl;
			printf("%s", (char*)TStack_Pop(&myStringStack)); nl;
			printf("%s", (char*)TStack_Pop(&myStringStack)); nl;
			nl;
			printf("Lens : %d", myStringStack.position); nl;
			for (; i > 0; i--) {
				printf("%d", myStringStack.lens[i - 1]); nl;
			}

		}

		if (!RUN) {

			const int sizess = 100000000;

			int *pa = malloc(sizess * sizeof *pa); // allocate an array of 10 int
			printf("Address : %p\n", (void*)pa);
			if (pa) {
				printf("%zu bytes allocated. Storing ints: ", 10 * sizeof(int));
				for (int n = 0; n < sizess; ++n)
					//printf("%d ", pa[n] = n);
					pa[n] = n;
				for (int n = 0; n < 10; ++n)
					printf("%d ", pa[n]);
			}

			int *pb = realloc(pa, 100000 * sizeof *pb); // reallocate array to a larger size
			printf("\nAddress : %p", (void*)pa);
			if (pb) {
				printf("\n%zu bytes allocated, first 10 ints are: ", 1000000 * sizeof(int));
				for (int n = 0; n < 10; ++n)
					printf("%d ", pb[n]); // show the array
				free(pb);
			}
			else { // if realloc failed, the original pointer needs to be freed
				free(pa);
			}
			nl;
		}

		if (!RUN) {

			byte **pparr;
			pparr = (byte**)calloc(10, sizeof(byte*));
			*pparr = malloc(20);
			*(pparr + 1) = malloc(20);
			*(pparr + 2) = malloc(20);
			*(pparr + 3) = malloc(20);

			*(*(pparr + 0) + 0) = 'J';
			*(*(pparr + 0) + 1) = 'o';
			*(*(pparr + 0) + 2) = 'h';
			*(*(pparr + 0) + 3) = 'n';
			*(*(pparr + 0) + 4) = '\0';

			*(*(pparr + 1) + 0) = 'D';
			*(*(pparr + 1) + 1) = 'o';
			*(*(pparr + 1) + 2) = 'w';
			*(*(pparr + 1) + 3) = 's';
			*(*(pparr + 1) + 4) = '\0';

			*(*(pparr + 2) + 0) = 'W';
			*(*(pparr + 2) + 1) = 'a';
			*(*(pparr + 2) + 2) = 'l';
			*(*(pparr + 2) + 3) = 'l';
			*(*(pparr + 2) + 4) = 'e';
			*(*(pparr + 2) + 5) = 'i';
			*(*(pparr + 2) + 6) = '\0';

			printf("%s\n%s\n%s\n", *pparr, *(pparr + 1), *(pparr + 2));

		}

	}



	if (!RUN) {

		int i = 10;
		unsigned char *c = "Hello!";

		int *ip = &i;
		ip = c;
		printf("%d", *ip); nl;

		c = "lo";
		ip = c;
		printf("%d", *ip); nl;

		c = "lp";
		ip = c;
		printf("%d", *ip); nl;

		c = "lq";
		ip = c;
		printf("%c", *(char*)((void*)ip)); nl; // Забыл что void нельзя разыменовывать.

	}

	if (!RUN) {

		struct Person *p = malloc(sizeof(struct Person));
		p->id = 1;
		p->name = "John";
		printf("%d\t%s", p->id, p->name); nl;
		TransformP(p);
		printf("%d\t%s", p->id, p->name); nl;
		TransformPP(&p);
		printf("%d\t%s", p->id, p->name); nl;

	}

	if (!RUN) {
		// ...
		double d = 100.4, r;
		int *p;
		p = (int*)&d;
		r = *p;
		// r = *((double*)p); // А так норм.
		printf("%f", r); nl;

		char *tmp = (char*)&d;
		r = (double)*p;
		r = (int)d;
		int a = d;
		printf("%f", r); nl;
		printf("%d", a); nl;
	}

	if (!RUN) {

		char *ch = malloc(6);
		short *sh = malloc(6);
		int *i = malloc(6);
		long long *ll = malloc(6);
		void *vd = malloc(6);
		short si = 1;
		char **chpp = (char**)calloc(6, sizeof(char*));
		printf("char*:\t\t\t%d   ", ch++); printf("%d   ", ch++); printf("%d   ", ch++); printf("%d   ", ch++); nl;
		printf("short*:\t\t\t%d   ", sh++); printf("%d   ", sh++); printf("%d   ", sh++); printf("%d   ", sh++); nl;
		printf("int*:\t\t\t%d   ", i++); printf("%d   ", i++); printf("%d   ", i++); printf("%d   ", i++); nl;
		printf("long long*:\t\t%d   ", ll++); printf("%d   ", ll++); printf("%d   ", ll++); printf("%d   ", ll++); nl;
		printf("long long* += short:\t%d   ", ll += si); printf("%d   ", ll += si); printf("%d   ", ll += si); printf("%d   ", ll += si); nl;
		// printf("void*:\t\t%d   ", vd++); printf("%d   ", vd++); // А хуй там! К void* адресная арифметика не применима :'(
		printf("char** += short:\t%d   ", chpp += si); printf("%d   ", chpp += si); printf("%d   ", chpp += si); printf("%d   ", chpp += si); nl;

	}

	if (RUN) {
		// Массив указателей на функции (функции с прототипом как у printf).
		typedef int(*funcs_ptrs)(const char*, ...);

		funcs_ptrs funcs_arr[10];

	}



	//system("pause");
}


void TransformP(struct Person *Pp) {

	Pp->id = 100;
	Pp = malloc(sizeof(struct Person));
	Pp->id = 200;
	Pp->name = "Curt";

}

void TransformPP(struct Person **Pp) {

	(*Pp)->id = 300;
	*Pp = malloc(sizeof(struct Person));
	(*Pp)->id = 800;
	(*Pp)->name = "Dimasik";
}

// Рекурсивное нахождение остатка от деления по модулю.
int divi(int number, int divisor) {
	int result = number;
	if (number >= divisor) {
		number -= divisor;
		result = divi(number, divisor);
	}
	return result;
}


