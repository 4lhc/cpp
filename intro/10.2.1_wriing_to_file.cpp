/*  
 *  10.2.1_wriing_to_file.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Tue 22 Aug 2017 17:09:41 IST
 *  ver    : 
 *   
 */


//read the source file line by line and write it to a new file

#include <iostream>
#include <fstream>




int main()
{
    std::string src_filename{"10.2.1_wriing_to_file.cpp"};
    std::string op_filename{"out_file_file"};

    std::ifstream ifile(src_filename);


    std::string line{}; //each line of the src_filename will be read to this string

    if(ifile) //check if file could be read
    {

        int i{0}; //count line number
        std::ofstream ofile(op_filename); //Create output filestream and open op_filename
        while(std::getline(ifile, line)) //getline returns false at EOF
        {
            std::cout << "Line " << ++i << ": " << line << std::endl;
            ofile << line << std::endl;

        }

    }
    else
    {
        std::cerr << "File could not be read";

    }


	return 0;
}
