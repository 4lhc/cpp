/*
 *  10.3_shake_insult.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Fri 25 Aug 2017 07:14:25 IST
 *  ver    :
 *
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>


int NumberOfLines(std::ifstream &ifs)
{
    int number_of_lines{0};
    std::string line{};
    while (std::getline(ifs, line))
    {
        number_of_lines++;
    }
    std::cout << "number_of_lines = " << number_of_lines << std::endl;
    return number_of_lines;
}

std::string GenerateInsult(std::ifstream &ifs, int number_of_lines)
{
    srand(time(NULL));
    int random1 = rand() % number_of_lines;
    int random2 = rand() % number_of_lines;
    int random3 = rand() % number_of_lines;
    int line_number{0};

    std::vector<std::string> insult(number_of_lines);
    std::string part1{}, part2{}, part3{};

    std::string line{};
    std::stringstream ss, ss_result;
    //std::getline(ifs, line);

    while (line_number < number_of_lines)
    {
        std::getline(ifs, line);
        if (line_number == random1)
        {
            ss << line;
            ss >> part1 >> part2 >> part3;
            insult[0] = part1;
            ss.clear();
        }
        if (line_number == random2)
        {
            ss << line;
            ss >> part1 >> part2 >> part3;
            insult[1] = part2;
            ss.clear();
        }

        if (line_number == random3)
        {
            ss << line;
            ss >> part1 >> part2 >> part3;
            insult[2] = part3;
            ss.clear();
        }
        line_number++;
    }

    ss_result << "Thou " << insult[0] << " " << insult[1] << " " << insult[2]
              << "!" << std::endl;
    return ss_result.str();

}

int main()
{
    std::string filename{"shake_spear_insults.txt"};

    std::ifstream ifs(filename);
    std::string line{};
    if (ifs.is_open())
    {
        std::cout << GenerateInsult(ifs, 60);
        //std::cout << GenerateInsult(ifs, NumberOfLines(ifs));
    }
    return 0;
}
