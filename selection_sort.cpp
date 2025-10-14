#include <iostream>
#include "goto.h"
#define MAX_NUMS 100
#define MAX 20

void show_list(int num_list[]) ;
void show_process(int i, int j, int min, int loc, int curr) ;
void show_list_process(int list_nums[]) ;

int main()
{
    int nums[MAX] ;
    srand(time(0)) ;
    for (int index = 0 ; index < MAX ; index++)
    {
        nums[index] = random(MAX_NUMS) ;
    } 
    std::cout << "Unsorted List: [" ; show_list(nums) ; std::cout << "]" ;
    gotoxy(1, 1) ;show_list(nums) ;

    for (int index = 0 ; index <= MAX-2 ; index++)
    {
        int min = nums[index], loc = index ;
        for (int sec_index = index + 1 ; sec_index <= MAX-1 ; sec_index++)
        {
            show_process(index, sec_index, min, loc, nums[sec_index]) ;
            if (nums[sec_index] < min)
            {
                min = nums[sec_index] ;
                loc = sec_index ;
            }
            Sleep(500) ;
        }

        if (min != nums[index])
        {
            nums[loc] = nums[index] ;
            nums[index] = min ;
            gotoxy(1, 6) ; std::cout << "SWAP!!" ;
            Sleep(300) ;
            gotoxy(1, 6) ; std::cout << std::string(100, ' ') ;
        }
        gotoxy(1, 1) ; std::cout << std::string(100, ' ') ;
        gotoxy(1, 1) ; show_list(nums) ;
        
    }
    gotoxy(1, 5) ; std::cout << "List: [" ; show_list(nums) ; std::cout << "]" << std::endl ;
    system("pause") ;


    return 0 ;
}

void show_list(int num_list[])
{
    for (int index = 0 ; index < MAX ; index++)
    {
        std::cout << num_list[index] << " ";
    }
}

void show_process(int i, int j, int min, int loc, int curr)
{
    std::string swap ;
    gotoxy(0, 2) ; std::cout << std::string(100, ' ') ;
    gotoxy(i*3, 2) ; std::cout << "i" ;
    gotoxy(j*3, 2) ; std::cout << "j" ;
    gotoxy(0, 3) ; std::cout << std::string(100, ' ') ;
    gotoxy(2, 3) ; std::cout << "min = " << min ;
    gotoxy(0, 4) ; std::cout << std::string(100, ' ') ;
    gotoxy(2, 4) ; std::cout << "loc = " << loc ;
    gotoxy(0, 5) ; std::cout << std::string(100, ' ') ;

    if (min > curr)
        swap = "TRUE CHANGE!!" ;
    else
        swap ="FALSE" ; 
    gotoxy(2, 5) ; std::cout << "min > " << curr << " = " << swap ;
}