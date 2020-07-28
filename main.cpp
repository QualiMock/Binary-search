#include <iostream>
#include <regex>

int compare_ints(const void* a, const void* b)  // this part for qsort()
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

int binary_search(int *arr, int num, int from, int to)  // recursive search algorithm
{
    int searcher = (from+to)/2, pivot;  //  finding central element of searching range

    pivot = arr[searcher-1];    // taking central element

    //printf("%d - %d\n", searcher, pivot);

    if(from <= to)
    {
        if(pivot > num)         // if pivot less than searching
            to = searcher-1;    // making right border 'searcher - 1'
        else if(pivot < num)    // if pivot more than searching 
            from = searcher+1;  // making right border 'searcher + 1'
        else if(pivot == num)   // if pivot equals searching number
            return searcher;    // return it's position in array
        else
            printf("There's no this number\n");

        binary_search(arr, num, from, to);  // if hasn't returned, searching in changed range 
    }
    else
        return searcher;
}

int main(int argc, char *argv[])
{
    bool can_do = true;

    int size = argc-1, result, number;

    //std::cout << "This program will sort an array and search a number in it\nand show you it's position\n\n";
    //std::cout << "Enter amount of numbers\n"; std::cin >> size; printf("\n");
    //std::cout << "Enter numbers\n";

    if(size > 0)
    {
        int *array = new int[size];

        for(int i = 1; i < argc; i++)
        {
            if(!std::regex_match(argv[i], std::regex("[0-9]+")))    // checking only for numbers
            {
                can_do = false;
                break;
            }
        }   

        if(can_do)
        {
            for(int i = 0; i < size; i++)
                array[i] = atoi(argv[i+1]);

            qsort(array, size, sizeof(int), compare_ints);  // sorting array, bin search can search only in sorted arrays

            std::cout << "Your sorted array: ";

            for(int i = 0; i < size; i++)
                printf("%d ", array[i]);
            printf("\n");

            std::cout << "Enter required number: "; std::cin >> number;     // entering required number

            result = binary_search(array, number, array[0], size-1);    // start searching

            printf("Your number is on %d position\n", result);
        }
        else
            std::cout << "Enter numbers next time\n";
    }
    else
        std::cout << "Enter not less 1 element\n";

    return 0;
}
