#include <iostream>

struct Node
{
    int data ;
    struct Node* next;
} ;

Node list_node[10] ;
int node_size = 0 ;
void insert(int number, Node* node) ;
void show_list() ;
int check_next(int index) ;
void remove(int index) ;


 
int main()
{
    std::string options[] = {"Insert", "Delete", "Check Next", "Exit"} ;
    
    while (true)
    {
        int number = 0 ;
        std::cout << "List: \n[" ; show_list() ;std::cout << "]" << std::endl ;
        for (int index = 0 ; index < (sizeof(options)/sizeof(options[0])) ; index++)
        {
            std::cout << "[" << index+1 << "] - " << options[index] << std::endl ; 
        }
        std::cout << "> " ; std::cin >> number ;

        switch (number)
        {
            case 1:
                int insert_user_input ;
                std::cout << "Input Number: " ; std::cin >> insert_user_input ;
                insert(insert_user_input, &list_node[node_size]) ;
                break ;
            case 2:
                int remove_user_input ;
                std::cout << "Input index: " ; std::cin >> remove_user_input ;
                remove(remove_user_input) ;
                break ;
            case 3:
                int check_user_input ;
                std::cout << "Input Index: " ; std::cin >> check_user_input ;
                std::cout << "Next data: " << check_next(check_user_input) << std::endl ;
                break ;
        }
    }

    
    return 0 ;
}

void insert(int number, Node* node)
{
    list_node[node_size-1].next = &list_node[node_size] ;
    node->data = number ;
    node_size++ ;
}

void show_list()
{
    for (int index = 0 ; index < node_size ; index++)
    {
        std::cout << list_node[index].data << ", " ;
    }
}

void remove(int index)
{
    for (int list_index = index ; list_index < (sizeof(list_node)/sizeof(list_node[0])) ; list_index++)
    {
        list_node[list_index].data = list_node[list_index+1].data ;
        list_node[list_index-1].next = &list_node[list_index] ;
    }
    node_size-- ;
}

int check_next(int index)
{
    return list_node[index].next->data ;
}