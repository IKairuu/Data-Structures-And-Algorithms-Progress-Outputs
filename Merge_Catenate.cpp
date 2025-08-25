#include <iostream>

void show_choices() ;
void show_lists() ;
void add_list() ;
void remove_list() ;
void list_catenate() ;
void list_merge() ;
int num_lists[10][10] ;
int sizes[10] ;
int num_list_size = 0, sizes_size = 0 ;

int main() {
    int user_input ;
    bool start = true ;
    while (start) {
        system("cls") ;
        show_lists() ;
        show_choices() ;
        std::cout << "> " ;
        std::cin >> user_input ;

        switch (user_input) {
            case 1:
                add_list() ;
                break ;
            case 2:
                remove_list() ;
                break ;
            case 3:
                list_catenate();
                break ;
            case 4:
                list_merge() ;
                break ;
            case 5:
                start = false ;
                break ;
        }
        system("pause") ;
    }


    return 0 ;
}

void show_choices() {
    std::string choices[] = {"Add List", "Remove List", "Catenate List", "Merge List", "Exit"} ;
    for (int nums = 1 ; nums <= (sizeof(choices)/sizeof(choices[0])) ; nums++) {
        std::cout << "[" << nums << "] - " << choices[nums-1] <<  std::endl ;
    }
}

void show_lists() {
    if (num_list_size == 0) {
        std::cout << "There are no lists" << std::endl ;
    }
    else {
        for (int a = 0 ; a < num_list_size ; a++) {
            std::cout << "List " << a+1 << ": [";
            for (int b = 0 ; b < sizes[a] ; b++) {
                std::cout << num_lists[a][b] << ", " ;
            }
            std::cout << "] " << std::endl ;
        }
    }
}

void add_list() {
    int list_size, size = 0 ;
    std::cout << "Input list size: " ;
    std::cin >> list_size ;
    int created_list[10] ;

    if (sizes_size < 10) {
        for (int times = 0 ; times < list_size ; times++, size++) {
            int user_input_int ;
            std::cout << "Input number: " ;
            std::cin >> user_input_int ;
            created_list[times] = user_input_int ;
        }
        sizes[sizes_size] = size ;
        sizes_size++ ;
        num_list_size++ ;
        for (int a = 0 ; a < size ; a++) {
            num_lists[num_list_size-1][a] = created_list[a] ;
        }
    }
    else {
        std::cout << "Reached the maximum amount of list" << std::endl ;
    }

}

void remove_list() {
    int index ;
    std::cout << "Input list number: " ;
    std::cin >> index ;

    for (int a = index-1 ; a < num_list_size ; a++) {
        for (int b = 0 ; b < sizes[a+1] ; b++) {
            num_lists[a][b] = num_lists[a+1][b] ;
        }
        sizes[a] = sizes[a+1] ;
    }
    sizes_size-- ;
    num_list_size-- ;
}

void list_catenate() {
    int first_list, sec_list ;
    std::cout << "Input first list number: " ;
    std::cin >> first_list ;
    std::cout << "Input second number: " ;
    std::cin >> sec_list ;

    int new_list[sizes[first_list-1]+sizes[sec_list-1]] ;
    int size_new_list = 0 ;

    for (int a = 0 ; a < sizes[first_list-1] ; a++, size_new_list++) {
        new_list[size_new_list] = num_lists[first_list-1][a] ;
        }

    for (int b = 0 ; b < sizes[sec_list-1] ; b++, size_new_list++) {
        new_list[size_new_list] = num_lists[sec_list-1][b] ;
    }

    std::cout << "Catenated List: [" ;
    for (int c = 0 ; c < size_new_list ; c++) {
        std::cout << new_list[c] << ", " ;
    }
    std::cout << "]" << std::endl ;
}

void list_merge() {
    int first_list, sec_list ;
    std::cout << "Input first list number: " ;
    std::cin >> first_list ;
    std::cout << "Input second number: " ;
    std::cin >> sec_list ;

    int new_list[sizes[first_list-1]+sizes[sec_list-1]] ;
    int size_new_list = 0 ;

    for (int a = 0 ; a < sizes[first_list-1] ; a++, size_new_list++) {
        new_list[size_new_list] = num_lists[first_list-1][a] ;
    }

    for (int b = 0 ; b < sizes[sec_list-1] ; b++, size_new_list++) {
        new_list[size_new_list] = num_lists[sec_list-1][b] ;
    }

    for (int e = 0 ; e < size_new_list ; e++) {
        for (int d = 0 ; d < size_new_list ; d++) {
            if (d != e) {
                if (new_list[e] == new_list[d]) {
                    for (int f = d ; f < size_new_list ; f++) {
                        new_list[f] = new_list[f+1] ;
                    }
                    size_new_list-- ;
                }
            }
        }
    }

    for (int c = 0 ; c < size_new_list ; c++) {
        for (int index = c ; index < size_new_list ; index++) {
            if (new_list[c] > new_list[index]) {
                int num = new_list[c] ;
                new_list[c] = new_list[index] ;
                new_list[index] = num ;
            }
        }
    }

    std::cout << "Merged List: [" ;
    for (int d = 0 ; d < size_new_list ; d++) {
        std::cout << new_list[d] << ", " ;
    }
    std::cout << "]" << std::endl ;
}






