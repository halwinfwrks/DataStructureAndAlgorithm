#include <stdio.h>

/**
 * * Relationship between Arrays and Pointers
 * Arrays and Pointers are closely related to each other such that we can use pointers to perform all the possible operations of the array.
 * The array name is a constant pointer to the first element of the array and the array decays to the pointers when passed to the function.
 */

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = &arr[0];

    printf("Address of arr[0] = %p\n", (void *)&arr[0]);
    printf("Address of *ptr = %p\n", (void *)ptr);

    // traverse the array using pointer
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    return 0;
}
