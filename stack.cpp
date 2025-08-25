#include <iostream>

void show_choices() ;
void show_list() ;
void add_stack() ;
void remove_stack() ;
int max_size = 10 ;
int curr_size = 0 ;
int num_list[10] ;

int main() {
    bool start = true ;
    while (start) {
        int user_input ;
        system("cls") ;
        show_list() ;
        show_choices() ;
        std::cout << "> " ;
        std::cin >> user_input ;
        switch (user_input) {
            case 1:
                add_stack() ;
                break ;
            case 2:
                remove_stack() ;
                break ;
            case 3:
                start = false ;
                break ;
            default:
                break ;
        }

        system("pause") ;
    }
    return 0 ;
}

void show_choices() {
    std::string choices[] = {"Add", "Remove", "Exit"} ;
    for (int nums = 1 ; nums < (sizeof(choices)/sizeof(choices[0])) ; nums++)
    {
        std::cout << "[" << nums << "] - " << choices[nums-1] << std::endl ;
    }
}

void show_list() {
    if (curr_size <= 0) {
        std::cout << "There is no list" << std::endl ;
    }
    else {
        std::cout << "[" ;
        for (int a = 0 ; a < curr_size ; a++) {
            std::cout << num_list[a] << ", " ;
        }
        std::cout << "]" << std::endl ;
    }
}

void add_stack() {
    if (curr_size == max_size) {
        std::cout << "Stack is full" << std::endl ;
    }
    else {
        int number ;
        std::cout << "Input number: " ;
        std::cin >> number ;

        num_list[curr_size] = number ;
        curr_size++ ;
    }
}

void remove_stack() {
    if (curr_size <= 0) {
        std::cout << "Stack is empty" << std::endl ;
    }
    else {
        num_list[curr_size] = num_list[curr_size+1];
        curr_size-- ;
    }

}






