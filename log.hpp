#pragma once
#include<iostream>
#include<string>
std::string aiyen = "[Log] ";
void LOG(std::string str)
{
    std::cout<< aiyen << str << std::endl;
}
void LOG(int a)
{
    std::cout << a << std::endl;
}

//idk what i was thinking 'bout when i wrote this header file