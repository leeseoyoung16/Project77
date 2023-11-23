#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 20
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;
int move, compare; 


void print_array(int arr[], int size) { //과정 출력
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

inc_insertion_sort(int list[], int first, int last, int gap)
{
    move = 0;
    compare = 0;
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
        
        for (j = i - gap; j >= first && key < list[j]; j = j - gap) {
            list[j + gap] = list[j];
            move++;
            compare++;
            
        }
		list[j + gap] = key;
        move++;
        
	}
}

void shell_sort(int list[], int n)   // n = size
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) gap++;
        for (i = 0; i < gap; i++) {		// 부분 리스트의 개수는 gap
            inc_insertion_sort(list, i, n - 1, gap);
 
        }
        print_array(list, n);
        
	}
}

void shell_sort2(int list[], int n)  //출력생략
{
    int i, gap;
    for (gap = n / 2; gap > 0; gap = gap / 2) {
        if ((gap % 2) == 0) gap++;
        for (i = 0; i < gap; i++) {		
            inc_insertion_sort(list, i, n - 1, gap);

        }
        //print_array(list, n);

    }
}



int main(void) {
    int i, j;
    int move_count = 0;
    int compare_count = 0;
    int count = 1;
    n = MAX_SIZE;

    srand(time(NULL));
    for (i = 0; i < n; i++)
        list[i] = rand() % 100;

    printf("Original list\n");
    print_array(list, n);

    printf("\nShell Sort\n");
    shell_sort(list, n);

    move_count += move;
    compare_count += compare;

    for (j = 1; j <= 19; j++) {
        for (i = 0; i < n; i++)
            list[i] = rand() % 100;

        shell_sort2(list, n);

        move_count += move;
        compare_count += compare;
        count++;

    }
    printf("Average Move Count: %d\n", move_count / count);
    printf("Average Compare Count: %d\n", compare_count / count);



    return 0;
}