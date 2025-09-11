#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <sstream>

std::string infix_to_postfix(std::string exp) ;
char operators[5] = {'^', '*', '/', '+', '-'} ;
int calculate_postfix(std::string expression) ;
double calculate_nums(int top, int bottom, std::string ope) ;
int precedence(char ope) ;

int main()
{
    std::string expression ;
    std::cout << "Input Expression: " ; 
    std::cin >> expression ;

    std::string postFix = infix_to_postfix(expression) ;
    std::cout << "POSTFIX: " << postFix << std::endl ;
    std::cout << "Answer: "  << calculate_postfix(postFix) ;

    return 0 ;
}

std::string infix_to_postfix(std::string exp)
{
    std::string postfix = "" ;
    char post_stack[exp.size()] ;
    int stack_size = -1 ;
    const char* chars = exp.c_str() ;
    for (int index = 0 ; index < exp.size() ; index++)
    {
        bool found = false ;
        if (chars[index] == '(')
        {
            stack_size++ ;
            post_stack[stack_size] = chars[index] ;
        }
        else if (chars[index] == ')')
        {
            while (stack_size > 0 && post_stack[stack_size] != '(')
            {
                if (precedence(post_stack[stack_size]) <= precedence(post_stack[stack_size-1]))
                {
                    post_stack[stack_size-1] = post_stack[stack_size] ;
                }
                postfix = postfix + " " + post_stack[stack_size] + " "  ;  
                stack_size-- ;
            }

            if (post_stack[stack_size] == '(')
            {
                stack_size-- ;
            }
        }
        else
        {
            for (int ope_index = 0 ; ope_index < 5 ; ope_index++)
            {
                if (chars[index] == operators[ope_index])
                {
                    stack_size++ ;
                    post_stack[stack_size] = operators[ope_index] ;
                    while (stack_size > 0 && precedence(post_stack[stack_size]) <= precedence(post_stack[stack_size-1]))
                    {
                        postfix = postfix + " " + post_stack[stack_size-1] + " " ;   
                        post_stack[stack_size-1] = post_stack[stack_size] ;
                        stack_size-- ;
                    }
                    found = true ;
                    break ;
                }
            }

            if (!found)
            {
                postfix = postfix + chars[index] ;
            }
            else
            {
                postfix += " " ;
            }
        }
    }

    for (int index = stack_size ; index > -1 ; index--)
    {
        if (post_stack[index] != '(' && post_stack[index] != ')')
        {
            postfix = postfix + " " +  post_stack[index] + " " ;
        }
    }
    return postfix ;
}

int precedence(char ope)
{
    int prec = 0 ;
    if (ope == '^')
    {
        prec = 3 ;
    }
    else if (ope == '*'|| ope == '/')
    {
        prec = 2 ;
    }
    else if (ope == '+' || ope == '-')
    {
        prec = 1 ;
    }
    return prec ;
}

int calculate_postfix(std::string expression)
{
    std::string stacks[expression.size()] ;
    int stack_size = -1 ;

    std::string nums[expression.size()] ;
    int size = 0 ;
    std::istringstream equation(expression) ;
    std::string exp_nums ;

    while (equation >> exp_nums)
    {
        if (exp_nums != " ")
        {
            nums[size] = exp_nums ;
            size++ ;
        }
    }

    for (int index = 0 ; index < expression.size() ; index++)
    {
        bool found = false ;
        for (int ope_index = 0 ; ope_index < 5 ; ope_index++)
        {
            std::string ope(1, operators[ope_index]) ;
            if (nums[index] == ope)
            {
                double answer = calculate_nums(std::stoi(stacks[stack_size]), std::stoi(stacks[stack_size-1]), ope) ;
                stack_size-- ;
                stacks[stack_size] = std::to_string(answer) ;
                found = true ;
                break ;
            }
        }

        if (!found)
        {
            stack_size++ ;
            stacks[stack_size] = nums[index] ;
        }
    }
    return std::stoi(stacks[0]) ;
}

double calculate_nums(int top, int bottom, std::string ope)
{
    double answer = 1 ;
    if (ope == "+"){answer = top + bottom ;}
    else if (ope == "-"){ answer = bottom - top ;}
    else if (ope == "*"){answer = top * bottom ;}
    else if (ope == "/"){answer = bottom / top ;}
    else if (ope == "^")
        for (int index = 0 ; index < top ; index++)
        {
            answer = answer * bottom ;
        }
    return answer ;
}