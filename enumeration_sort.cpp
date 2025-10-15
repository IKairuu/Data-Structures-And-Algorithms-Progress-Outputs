#include <iostream>
#include "goto.h"
#define MAX 10
#define MAX_NUMS 100

void show_list(int num_list[]) ;
int* sort_it(int num_list[], int index_list[], int new_list[]) ;
void show_index_list(int index_list[]) ;
void show_process(int i, int j, int curr_i, int curr_j) ;

int main()
{
    int nums[MAX], INDEX[MAX], new_list[MAX] ; 
    srand(time(0)) ;

    for (int index = 0 ; index < MAX ; index++)
    {
        new_list[index] = 0 ;
        INDEX[index] = 0 ;
        nums[index] = random(MAX_NUMS) ;
    }
    std::cout << "Unsorted List: " ; show_list(nums) ; 

    for (int index = 0 ; index < MAX-1 ; index++)
    {
        gotoxy(1,2) ; show_list(nums) ; 
        for (int sec_index = index+1 ; sec_index < MAX ; sec_index++)
        {
            show_process(index, sec_index, nums[index], nums[sec_index]) ;
            if (nums[index] > nums[sec_index])
            {
                INDEX[index]++ ;
            }
            else
            {
                INDEX[sec_index]++ ;
            }
            show_index_list(INDEX) ;
            Sleep(500) ;
        }
    }
    int* ptr_list = sort_it(nums, INDEX, new_list) ;
    gotoxy(1, 7) ; std::cout << "SORTED LIST: [" ; show_list(ptr_list) ; std::cout << "]" ;

    std::cout << std::endl ;
    system("pause") ;
    return 0 ;
}

void show_list(int num_list[])
{
    for (int index = 0 ; index < MAX ; index++)
    {
        std::cout << num_list[index] << " " ;
    }
}

int* sort_it(int num_list[], int index_list[], int new_list[])
{
    for (int index = 0 ; index < MAX ; index++)
    {
        new_list[index_list[index]] = num_list[index] ;
        gotoxy(1, 6) ; std::cout << std::string(100, ' ') ;
        gotoxy(1, 6) ; std::cout << "NEW LIST: [ "  ;
        for (int sec_index = 0 ; sec_index < MAX ; sec_index++)
        {
            std::cout << new_list[sec_index] << " " ;
        }
        std::cout << "]" ;
        Sleep(500) ; 
    }
    return new_list ;
}

void show_process(int i, int j, int curr_i, int curr_j)
{
    std::string greater ;
    gotoxy(0,3) ; std::cout << std::string(100, ' ') ;
    gotoxy(i*3, 3) ; std::cout << "i" ;
    gotoxy(j*3, 3) ; std::cout << "j" ;

    if (curr_i > curr_j)
        greater = "TRUE " ;
    else
        greater = "FALSE " ;
    
    gotoxy(1, 4) ; std::string(100, ' ') ;
    gotoxy(1, 4) ; std::cout << curr_i << " > " << curr_j << " = " << greater ;
}

void show_index_list(int index_list[])
{
    gotoxy(0,5) ; std::cout << std::string(100, ' ') ;
    gotoxy(0, 5) ; std::cout << "INDEX LIST: { " ;
    for (int index = 0 ; index < MAX ; index++)
    {
        std::cout << "[" <<index_list[index] << "] " ;
    }
    std::cout << "}" ;
}