#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "TStack.h"

#define RUN 1
#define nl printf("\n")
#define TTStack_Push(X, Y) TStack_Push(X, Y, sizeof(Y))


void main(void) {

		if (RUN) {

			struct TStack myStringStack;

			TStack_init(&myStringStack);
			TTStack_Push(&myStringStack, "Johnson Large");
			TTStack_Push(&myStringStack, "Elvis");
			TTStack_Push(&myStringStack, "Kenny");

			int a = 100, b = 2200, c = 55555;
			TTStack_Push(&myStringStack, &a);
			TTStack_Push(&myStringStack, &b);
			TTStack_Push(&myStringStack, &c);

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

}

