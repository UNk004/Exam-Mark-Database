#include<iostream>
#include<fstream>
#include<filesystem>
#include "log.hpp"

std::fstream theFile;
std::string success = "File opened successfully";
std::string failed = "File does not exist. Creating the file ...\n";
std::string userQuery[] = {"\nEnter exam's name -> ", "Enter obtained marks -> ", "Enter exam's highest number -> ", "Enter the exam full marks -> "};
std::string dataInput[4];
std::string exmNamR;

int examNum=3;
bool checkFile();
void dataEntry(std::string data[]);
void examName(std::string exmNam);

int main()
{   
    LOG("Getting ready...\n");
    examName(exmNamR);
    
    if(checkFile) {
        for(int i=0;i<examNum;i++)
        {
            dataEntry(dataInput);
        }
        std::ofstream theFile("dataFile.txt", std::ios::app);
        theFile <<"--------------------------------------------------------------------------\n";
    }else return 40;
    
}


bool checkFile()
{
    std::fstream theFile("dataFile.txt");
    if(theFile.is_open())
    {
        LOG(success);
        std::ofstream theFile("dataFile.txt", std::ios::app);
        return true;
        
    }else
    {
        LOG(failed);
        std::ofstream("dataFile.txt");
        std::cout << "[Log] File created successfully \n";
        return false;
    }
}



void dataEntry(std::string data[])
{
    std::ofstream theFile("dataFile.txt", std::ios::app);
    for(int i = 0; i <= 3 ; i++)
    {   std::cout << userQuery[i];
        getline(std::cin, data[i]);
        theFile <<std::left<<std::setw(20) <<data[i]; //<< "\t \t";
        std::cout << "\n";
    }
    theFile << "\n";
    theFile.close();
}


void examName(std::string exmNam)
{
    std::cout << "Enter the name of the exam -> ";
    getline(std::cin, exmNam);
    std::ofstream theFile("dataFile.txt", std::ios::app);
    theFile <<"--------------------------------------------------------------------------\n";
    theFile <<std::right<<std::setw(37) <<exmNam <<" : " << "\n";
    theFile <<"--------------------------------------------------------------------------\n";
    theFile << std::left<<std::setw(20)<<"Subject" << std::left<<std::setw(20)  << "Obtained Marks"<< std::left<<std::setw(20) << "Highest Marks"<< std::left<<std::setw(20) << "Total Marks" << "\n";
    theFile <<"--------------------------------------------------------------------------\n";
    std::cout << "Enter the number of exams: ";
    std::string input;
    getline(std::cin,input);
    try
    {
    examNum = std::stoi(input);
    if (examNum <= 0) {
            std::cerr << "Invalid number of exams." << std::endl;
            examNum = 3;
        }
    } catch (const std::invalid_argument&) {
        std::cerr << "Invalid input." << std::endl;
        examNum = 3;
    } catch (const std::out_of_range&) {
        std::cerr << "Number is out of range." << std::endl;
        examNum = 3;
    }
    }