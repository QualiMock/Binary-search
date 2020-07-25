#include <iostream>

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

int binary_find(int *arr, int num, int from, int to)
{
    int finder = (from+to)/2, pivot;

    pivot = arr[finder-1];

    //printf("%d - %d\n", finder, pivot);

    if(from <= to)
    {
        if(pivot > num)
            to = finder-1;
        else if(pivot < num)
            from = finder+1;
        else if(pivot == num)
            return finder;
        else
            printf("There's no this number\n");

        binary_find(arr, num, from, to);
    }
    else
        return finder;
}

int main(int argc, char *argv[])
{

    int size = argc-1, result, number;

    //std::cout << "This program will sort an array and find a number in it\nand show you it's position\n\n";
    //std::cout << "Enter amount of numbers\n"; std::cin >> size; printf("\n");
    //std::cout << "Enter numbers\n";

    if(size > 0)
    {
        int *array = new int[size];

        for(int i = 0; i < size; i++)
            array[i] = atoi(argv[i+1]);

        qsort(array, size, sizeof(int), compare_ints);

        std::cout << "Your sorted array: ";

        for(int i = 0; i < size; i++)
            printf("%d ", array[i]);
        printf("\n");

        std::cout << "Enter required number: "; std::cin >> number;

        result = binary_find(array, number, array[0], size-1);

        printf("Your number is on %d position\n", result);
    }
    else
        std::cout << "Enter not less 1 element\n";

    return 0;
}
