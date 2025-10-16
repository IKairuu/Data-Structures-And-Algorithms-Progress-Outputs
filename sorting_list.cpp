#include <iostream>
#include <ctime>
#include <conio.h>
#include "goto.h"
#define max 10
#define max_numbers 100

void show_list(int num_list[]) ;
void show_process(int i_x, int j_x) ;
void show_true_false(int first, int second) ;
void show_effects(int nums) ;


int main()
{
    int list_nums[max] ;
    srand(time(0)) ;
    for (int index = 0 ; index < max ; index++)
    {
        list_nums[index] = random(max_numbers) ;
    } 
    gotoxy(0,0) ; std::cout << "UNSORTED LIST: [ " ; show_list(list_nums) ; std::cout << "]" ; 
    for (int i = 0 ; i <= max-2 ; i++)
    {
        for (int j = i+1 ; j <= max-1 ; j++)
        {
            gotoxy(1,2) ; std::cout << std::string(100, ' ') ;
            gotoxy(1,2) ; show_list(list_nums) ;
            gotoxy(0, 3) ; std::cout << std::string(100, ' ') ;
            show_process(i, j) ;
            gotoxy(1, 7) ; std::cout << std::string(100, ' ') ;
            show_true_false(list_nums[i], list_nums[j]) ;
            show_effects(j) ;
            Sleep(700) ;
            if (list_nums[i] > list_nums[j])
            {
                int num = list_nums[i] ;
                list_nums[i] = list_nums[j] ; 
                list_nums[j] = num ;
            }
            
        }
    }
    
    gotoxy(1, 8) ; std::cout << "Sorted List: " ; show_list(list_nums) ;
    std::cout << std::endl ;
    system("pause") ;
    
    return 0 ;
}

void show_list(int num_list[])
{
    for (int index = 0 ; index < max ; index++)
    {
        std::cout << num_list[index] << " " ;
    }
}

void show_process(int i_x, int j_x)
{
    gotoxy(i_x* 3, 3) ; std::cout << "i" ;
    gotoxy(j_x* 3, 3) ; std::cout << "j" ;
}

void show_true_false(int first, int second)
{
    std::string greater ;
    if (first > second)
        greater = "true SWITCH!!" ;
    else
        greater = "false" ;
    gotoxy(1, 5) ; std::cout << std::string(50, ' ') ;
    gotoxy(1, 5) ; std::cout << "i = " << first ;
    gotoxy(1, 6) ; std::cout << std::string(50, ' ') ;
    gotoxy(1, 6) ; std::cout << "j = " << second ;
    gotoxy(1, 7) ; std::cout << std::string(50, ' ') ;
    gotoxy(1, 7) ; std::cout << "i > j = " << greater  ;
}

void show_effects(int nums)
{
    if (nums & 1 == 1)
    {
        gotoxy(0, 1) ; std::cout << std::string(100, ' ') ;
        gotoxy(0, 1) ; std::cout << " - - - - - - - - - - - - - - -" ;

        gotoxy(0, 4) ; std::cout << std::string(100, ' ') ;
        gotoxy(0, 4) ; std::cout << "- - - - - - - - - - - - - - - " ;
    }
    else
    {
        gotoxy(0, 1) ; std::cout << std::string(100, ' ') ;
        gotoxy(0, 1) ; std::cout << "- - - - - - - - - - - - - - - " ;

        gotoxy(0, 4) ; std::cout << std::string(100, ' ') ;
        gotoxy(0, 4) ; std::cout << " - - - - - - - - - - - - - - -" ;
    }

}