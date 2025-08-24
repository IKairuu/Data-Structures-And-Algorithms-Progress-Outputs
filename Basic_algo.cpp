#include <iostream>
#include <list>

void show_list() ;
void show_choices() ;
void list_append() ;
void list_insert() ;
void list_delete() ;
void list_sort() ;
int list_search() ;
void list_replace() ;
void list_access() ;
int size = 0 ;
int num_list[10] ;

int main()
{
    int user_input, num_index ;
    while (true)
    {
        system("CLS") ;
        show_list() ;
        show_choices() ;
        std::cout << "> " ;
        std::cin >> user_input ;

        switch (user_input) {
            case 1:
                list_append() ;
                break ;
            case 2:
                list_insert() ;
                break ;
            case 3:
                list_delete() ;
                break ;
            case 4:
                list_sort() ;
                break ;
            case 5:
                num_index = list_search() ;
                if (num_index == -1) {
                    std::cout << "Number Not Found" << std::endl ;
                }
                else {
                    std::cout << "Position: " << num_index << std::endl ;
                }
                break ;
            case 6:
                list_replace() ;
                break ;
            case 7:
                list_access() ;
                break ;
            case 8:
                exit(0) ;
                break ;
            default:
                std::cout << "Invalid Input" << std::endl ;
                break ;
        }
        system("pause") ;
    }
    return 0 ;
}

void show_choices()
{
    std::string choices[] = {"Append", "Insert", "Delete", "Sort", "Search", "Replace", "Access", "Exit"} ;
    for (int nums = 1 ; nums <= (sizeof(choices)/sizeof(choices[0])) ; nums++)
    {
        std::cout << "[" << nums << "] - " << choices[nums-1] << std::endl ;
    }
}


void show_list()
{
    if (size == 0)
    {
        std::cout << "No List" << std::endl ;
    }
    else
    {
        std::cout << "[" ;
        for (int a = 0 ; a < size ; a++)
        {
            std::cout << num_list[a] << ", " ;
        }
        std::cout << "]" << std::endl ;
    }
}

void list_append(){
    int user_input_num ;
    std::cout << "Input number: " ;
    std::cin >> user_input_num ;

    num_list[size] = user_input_num ;
    size++ ;
}

void list_insert() {
    int user_input_int, user_input_pos ;
    std::cout << "Input Number: " ;
    std::cin >> user_input_int ;
    std::cout << "Input Index: " ;
    std::cin >> user_input_pos ;

    if (user_input_pos > size) {
        std::cout << "Invalid Index" << std::endl ;
    }
    else {
        for (int a = size ; a > user_input_pos ; a--) {
            num_list[size] = num_list[size-1] ;
        }
        num_list[user_input_pos] = user_input_int ;
        size++ ;
    }

}

void list_delete() {
    int index ;
    std::cout << "Input Index: " ;
    std::cin >> index ;

    if (index > size-1) {
        std::cout << "Invalid Index" << std::endl ;
    }
    else {
        for (int nums = index ; nums < size ; nums++) {
            num_list[nums] = num_list[nums+1] ;
        }
        size-- ;
    }

}

void list_sort() {
    for (int num = 0 ; num < size ; num++) {
        for (int sec_num = num ; sec_num < size ; sec_num++) {
            if (num_list[num] > num_list[sec_num]) {
                int temp = num_list[num] ;
                num_list[num] = num_list[sec_num] ;
                num_list[sec_num] = temp ;
            }
        }
    }
}

int list_search() {
    int number;
    std::cout << "Input number: " ;
    std::cin >> number ;
    for (int num_index = 0 ; num_index < size ; num_index++) {
        if (number == num_list[num_index]) {
            return num_index ;
        }
    }
    return -1 ;
}

void list_replace() {
    int new_number, num_index ;
    std::cout << "Input new Number: " ;
    std::cin >> new_number ;
    std::cout << "Input Index: " ;
    std::cin >> num_index ;

    if (num_index > size-1) {
        std::cout << "Invalid Index" << std::endl ;
    }
    else {
        for (int nums = 0 ; nums < size ; nums++) {
            if (nums == num_index) {
                num_list[nums] = new_number ;
                break ;
            }
        }
    }

}

void list_access() {
    int num_index ;
    std::cout << "Input Index: " ;
    std::cin >> num_index ;

    if (num_index > size-1) {
        std::cout << "No Number at index: " << num_index << std::endl ;
    }
    else {
        std::cout << "Number at index " << num_index << ": " << num_list[num_index] << std::endl ;
    }
}














