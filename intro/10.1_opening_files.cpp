/*  
 *  10.1_opening_files.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Tue 22 Aug 2017 15:45:12 IST
 *  ver    : 
 *   
 */


#include <iostream>
#include <fstream>


void OpenCloseFilesExp()
{
    //open and close file streams explicitily

    std::ifstream ifile; //input file stream object declared for reading
    std::ofstream ofile; //output file stream object declared for writing
    std::fstream iofile; //in/output file stream object declared for reading & writing


    ifile.open("file1.dat"); //opens file1.dat for reading
    ofile.open("file2.dat"); //opens file2.dat for writing
    iofile.open("file3.dat"); //opens file3.dat for both


    ifile.close();
    ofile.close();
    iofile.close();

}

void OpenCloseFilesImp()
{
    //open and close file streams implicitily
    std::ifstream ifile("file1.dat"); //file opened implicitily by constructor
    std::ofstream ofile("file2.dat");
    std::ifstream iofile("file3.dat");


    //files closed by destructors
}

int main()
{

    OpenCloseFilesExp();
	return 0;
}
