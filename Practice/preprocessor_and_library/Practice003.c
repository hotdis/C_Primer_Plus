/*Write a function that takes as arguments the name of an array of type int elements, 
 *the size of an array, and a value representing the number of picks. 
 *The function then should select the indicated number of items at random from the array and prints them.
 *No array element is to be picked more than once. (This simulates picking lottery numbers or jury members.)
 *Also, if your implementation has time()(discussed in C hapter 12) or a similar function available, 
 *use its output with srand() to initialize the rand() randomnumber generator.
 *Write a simple program that tests the function.
 */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 5

void pick_up_els(int *, int, int);

int main() {
	srand((unsigned int)time(0));

	int arr[SIZE] = { 1,2,3,4,5 };

	for (int i = 0; i < 500; i++) {
		pick_up_els(arr, SIZE, 3);
	}
	
	system("pause");
	return 0;
}

void pick_up_els(int *arr, int size, int num){
	
	int *p = (int *)malloc(sizeof(int)*size);
	int index;

	for (int i = 0; i < size; i++) {
		p[i] = 0;
	}
	
	for (int i = 0; i < num; i++) {
		index = rand() % size;
		while (1 == p[index]) {
			index = rand() % size;
		}
		p[index] = 1;
		printf("*%d ", arr[index]);
	}
	putchar('\n');
}