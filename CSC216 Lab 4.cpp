#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;



int splice(int arr[], size_t ARR_MAX, size_t index)
{
    int var_at = arr[index];

    for(size_t j = index; j < ARR_MAX; j++)
    {
        arr[j] = arr[j+1];
    }
    return var_at;
}

void fill_array(int arr[], size_t MAX_ARR)
{
    for(size_t i = 0; i < MAX_ARR; i++)
    {
        arr[i] = i + 1;
    }
    return;
}

void print_arr(int arr[], const size_t MAX_ARR)
{
    for(size_t i = 0; i < MAX_ARR; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shuffle_one(int arr[], const size_t ARR_MAX)
{
    size_t n = ARR_MAX;
    int copy[ARR_MAX];
    size_t i, copy_index = 0;

    while(n > 0)
    {
        i = floor(rand() % (ARR_MAX));

        if(arr[i] != 0)
        {
            copy[copy_index++] = arr[i];
            arr[i] = 0;
            n--;
        }
    }
    print_arr(copy,ARR_MAX);
    return;
}

void shuffle_two(int arr[], const size_t ARR_MAX)
{
    size_t n = ARR_MAX;
    int copy[ARR_MAX];
    size_t i, copy_index = 0;

    while(n > 0)
    {
        i = floor(rand() % (n--));

        copy[copy_index++] = splice(arr, n, i);
    }
    print_arr(copy, ARR_MAX);
    return;
}

void shuffle_three(int arr[], const size_t ARR_MAX)
{
    size_t m = ARR_MAX;
    size_t i;
    int t;

    while (m > 0)
    {
        i = floor(rand() % (m--));

        t = arr[m];
        arr[m] = arr[i];
        arr[i] = t;
    }
    print_arr(arr, ARR_MAX);
    return;
}

void print_all_arr(int arr[], const size_t MAX_ARR)
{
    int temp[MAX_ARR];
    cout << "\tShuffle 1:" << endl;
    for(int v = 1; v <= 4; v++)
    {
        cout << "\t\tTrial #" << v << endl;
        for(size_t k = 0; k < MAX_ARR; k++)
        {
            temp[k] = arr[k];
        }  
        shuffle_one(temp, MAX_ARR);
    }

    cout << "\n\tShuffle 2:" << endl;
    for(int v = 1; v <= 4; v++)
    {
        cout << "\t\tTrial #" << v << endl;
        for(size_t k = 0; k < MAX_ARR; k++)
        {
            temp[k] = arr[k];
        }  
        shuffle_two(temp, MAX_ARR);
    }

    cout << "\n\tShuffle 3:" << endl;
    for(int v = 1; v <=4; v++)
    {
        cout << "\t\tTrial #" << v << endl;
        for(size_t k = 0; k < MAX_ARR; k++)
        {
            temp[k] = arr[k];
        }  
        shuffle_three(temp, MAX_ARR);
    }
}

int main(void)
{
    srand(static_cast<unsigned>(time(nullptr)));

    size_t MAX_ARR1 = 10, MAX_ARR2 = 30, MAX_ARR3 = 52, MAX_ARR4 = 300;
    int arr1[MAX_ARR1], arr2[MAX_ARR2], arr3[MAX_ARR3], arr4[MAX_ARR4];

    fill_array(arr1, MAX_ARR1);
    fill_array(arr2, MAX_ARR2);
    fill_array(arr3, MAX_ARR3);
    fill_array(arr4, MAX_ARR4);

    cout << "Array 1:" << endl;
    print_all_arr(arr1, MAX_ARR1);
    cout << "\nArray 2:" << endl;
    print_all_arr(arr2, MAX_ARR2);
    cout << "\nArray 3:" << endl;
    print_all_arr(arr3, MAX_ARR3);
    cout << "\nArray 4:" << endl;
    print_all_arr(arr4, MAX_ARR4);

    return 0;
}