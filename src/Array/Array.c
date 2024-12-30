#include <stdio.h>

int main(int argc, char const *argv[])
{
    /**
     * * Array initialization
     */

    // Array Initialization with Declaration
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Array Initialization with Declaration without Size
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Array Initialization after Declaration (Using Loops)
    int arr3[10];
    for (int i = 0; i < 10; i++)
    {
        arr3[i] = i + 1;
    }

    /**
     * * Access Array Elements
     */
    printf("%d\n", arr[0]); // Output: 1

    /**
     * * Update Array Element
     */
    arr[0] = 10;

    /**
     * * Traverse Array Elements
     */
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    /**
     * * Type of Array
     */

    // 1D Array
    int arr1D[10];
    // 2D Array
    int arr2D[10][10];
    // 3D Array
    int arr3D[10][10][10];
    return 0;
}
