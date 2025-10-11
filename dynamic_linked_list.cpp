#include <iostream>

struct num_list
{
    int value ;
    struct num_list* next ;
} ;

struct num_list* head = nullptr ;
struct num_list* last = nullptr ;

void add_num() ;
void show_list() ;
void search_number() ;
void delete_number() ;

int main()
{
    std::string options[] = {"Add", "Search", "Delete", "Exit"} ;
    bool start = true ;
    while(start)
    {
        int user_input ;
        system("cls") ;
        std::cout << "List: [" ; show_list() ; std::cout << "]" << std::endl ;
        for (int index = 0 ; index < 4 ; index++)
        {
            std::cout << "[" << index+1 << "] - " << options[index] << std::endl ;
        }
        std::cout << "> " ; std::cin >> user_input ;
        switch (user_input)
        {
            case 1:
                add_num() ;
                break ;
            case 2:
                search_number() ;
                break ;
            case 3:
                delete_number() ;
                break ;
            case 4:
                start = false ;
                break ;
        }
        system("pause") ;
        
    }
    return 0 ;
}

void add_num()
{
    int user_input ;
    std::cout << "Input number: " ; std::cin >> user_input ;

    num_list* nums = new num_list() ;
    nums->value = user_input ;
    nums->next = nullptr ;

    if (head == nullptr)
    {
        head = nums ;
        last = nums ;
    }
    else
    {
        last->next = nums ;
        last = nums ;
    }    
}

void show_list()
{
    num_list* first = head ;
    while (first != nullptr)
    {
        std::cout << first->value << ", " ;
        first = first->next ;
    }
}
void search_number()
{
    int num, num_search = -1, index = 0 ;
    num_list* first = head ;    
    std::cout << "Input number: " ; std::cin >> num ;
    while (first != nullptr)
    {
        if (first->value == num)
        {
            num_search = index ;
            break ;
        }
        first = first->next ;
        index++ ;
    }

    if (num_search == -1)
        std::cout << "Number Not Found" << std::endl ;
    else
        std::cout << "Number found at Index: " << num_search << std::endl ;
}

void delete_number()
{
    int user_input, start_index = 0 ;
    std::cout << "Input Index: " ; std::cin >> user_input ;
    num_list* first = head ;
    num_list* prev = head ;
    if (user_input == 0)
    {
        head = head->next ;
    }
    else
    {
        while (first != nullptr)
        {
            if (first == last && start_index == user_input)
            {
                prev->next = nullptr ;
                first = nullptr ;
                last = prev ;
            }
            else if (start_index == user_input)
            {
                first = first->next ;
                start_index++ ;
            }
            else if (start_index == user_input+1)
            {
                prev->next = first ;
                first = nullptr ;
                break ;
            }
            else
            {
                prev = first ;
                first = first->next ;
                start_index++ ;
            }
        }
    }
}