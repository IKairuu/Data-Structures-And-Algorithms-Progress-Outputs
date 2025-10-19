#include <iostream>
#include "goto.h"
#define MAX 20
#define MAX_NUMS 100

struct num_list
{
    int value ; 
    struct num_list* next ;
    struct num_list* prev ;
} ;
struct num_list* head ; 

void show_list(int num_list[]) ; 
void show_linked_list() ; 
void show_process(int i) ; 

int main()
{
    int nums[MAX] ; 
    for (int index = 0 ; index < MAX ; index++)
        nums[index] = random(MAX_NUMS) ;
    
    std::cout << "UNSORTED LIST: ( " ; show_list(nums) ; std::cout << ")" ; 

    for (int index = 0 ; index < MAX ; index++)
    {
        num_list* num = new num_list() ; 
        num->value = nums[index] ; 
        gotoxy(1, 2) ; show_list(nums) ; 
        show_process(index) ; 
        if (index == 0)
        {
            num->next = nullptr ; 
            num->prev = nullptr ; 
            num->value = nums[index] ; 
            head = num ; 
        }
        else
        {
            num_list* first = head ; 
            while(first != nullptr)
            {
                if ((first->next != nullptr && num->value >= first->value && num->value <= first->next->value))
                {
                    num->prev = first ; 
                    num->next = first->next; 
                    first->next->prev = num ; 
                    first->next = num ;  
                    break ; 
                }
                else if (first->prev == nullptr && first->value > num->value)
                {
                    num->prev = nullptr ; 
                    num->next = first ; 
                    first->prev = num ; 
                    head = num ; 
                    break ;
                }
                else if (first->next == nullptr && first->value < num->value)
                {
                    num->next = nullptr ; 
                    num->prev = first ; 
                    first->next = num ; 
                    break ;
                }
                first = first->next ; 
            }
        }
        gotoxy(0, 5) ; std::cout << std::string(100, ' ') ; 
        gotoxy(1, 5) ; std::cout << "LINKED LIST: [ " ; show_linked_list() ; std::cout << "]" ; 
        Sleep(700) ; 
    }
    gotoxy(1, 6) ; std::cout << "SORTED LIST: ( " ; show_linked_list() ; std::cout << ")" ; 
    gotoxy(1, 7) ;system("pause") ; 

    return 0 ;
}

void show_list(int num_list[])
{
    for (int index = 0 ; index < MAX ; index++)
        std::cout << num_list[index] << " " ; 
}

void show_linked_list()
{
    num_list* first = head ; 
    while(first != nullptr)
    {
        std::cout << first->value << " " ; 
        first = first->next ; 
    }
}

void show_process(int i)
{
    gotoxy(0, 3) ; std::cout << std::string(100, ' ') ; 
    gotoxy(i*3, 3) ; std::cout << "i" ; 
}