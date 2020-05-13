/*
 *  10.2_writing_text_to_file.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Tue 22 Aug 2017 16:40:09 IST
 *  ver    :
 *
 */


#include <iostream>
#include <fstream>
#include <string>


int main()
{

    std::string filename = "out_file.txt";

    std::ofstream ofile(filename);

    if (ofile) //Checks if file could be opened same as{?} ofile.is_open()
    {

        for(int i = 0; i <= 10; i++)
        {

            ofile << i << " Hello!" << std::endl;
        }
    }
    else
    {

        std::cerr << "File could not be opened!" << std::endl;
    }

    return 0;
}
