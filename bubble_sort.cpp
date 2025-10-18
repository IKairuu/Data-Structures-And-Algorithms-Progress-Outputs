#include <iostream>
#include "goto.h"
#define MAX 20
#define MAX_NUMS 100
#define mm 400

void show_list(int num_list[]) ;
void show_process(int i, int j) ;
void show_true_false(int i, int j) ;

int main()
{
    int nums[MAX] ;
    srand(time(0)) ;
    for (int index = 0 ; index < MAX ; index++)
    {
        nums[index] = random(MAX_NUMS) ;
    }

    std::cout << "UNSORTED LIST : ( " ; show_list(nums) ; std::cout << ")" ;

    for (int times = 0, lim = MAX ; times < MAX ; times++, lim--)
    {
        for (int i = 0; i < lim-1 ; i++)
        {
            gotoxy(1, 3) ; std::cout << std::string(100, ' ') ;
            gotoxy(1, 3) ; show_list(nums) ;
            gotoxy(0, 4) ; std::cout << std::string(100, ' ') ;
            show_process(i, i+1) ;
            show_true_false(nums[i], nums[i+1]) ;
            Sleep(mm) ;
            if (nums[i+1] < nums[i])
            {
                int temp = nums[i+1] ;
                nums[i+1] = nums[i] ;
                nums[i] = temp ;
                show_process(i+1, i) ;
                gotoxy(1, 3) ; std::cout << std::string(100, ' ') ;
                gotoxy(1, 3) ; show_list(nums) ;
                Sleep(mm) ;
            }
        }
    }
    gotoxy(0, 7) ; std::cout << "SORTED LIST : ( " ; show_list(nums) ; std::cout << ")" ;
    gotoxy(0, 8) ;system("pause") ;
    return 0 ;
}

void show_list(int num_list[]) 
{
    for (int index = 0 ; index < MAX ; index++)
    {
        std::cout << num_list[index] << " " ;
    }
}

void show_process(int i, int j)
{
    gotoxy(0, 4) ; std::cout << std::string(100, ' ') ;
    gotoxy(i*3, 4) ;std::cout << "i" ;
    gotoxy(j*3, 4) ;std::cout << "j" ;
}

void show_true_false(int i, int j) 
{
    std::string greater = "" ;
    gotoxy(1, 5) ; std::cout << std::string(100, ' ') ;
    gotoxy(1, 5) ; std::cout << "i = " << i << ", j = " << j ;

    if (i > j )
        greater = "True SWAP!!" ;
    else
        greater = "False" ;

    gotoxy(1, 6) ; std::cout << std::string(100, ' ') ;
    gotoxy(1, 6) ; std::cout << i << " > " << j << " = " << greater ;
}