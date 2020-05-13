/*
 *  8.1_compound_types_references.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Tue 08 Aug 2017 03:49:22 IST
 *  ver    :
 *
 */


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>


class HugeMatrixClass
{

    public:
        void PopulateMat();
        void PrintMat();

        HugeMatrixClass(int &ref_rows, int &ref_cols) :
            _matrix(ref_rows , std::vector<int>(ref_cols, 0)) //intializing with 0s
             {}


    private:
        //the commented code below doesn't work (?)
        //std::vector < std::vector <int> > _Mat (3, std::vector<int>(3, 0));
        std::vector<std::vector<int>> _matrix; //declaring vector of vector
};


void HugeMatrixClass::PopulateMat()
{
    //populate with random elements
    srand(time(NULL));
    for(unsigned int i = 0; i<_matrix.size(); i++)
    {
        for(unsigned int j = 0; j<_matrix[i].size(); j++)
            _matrix[i][j] = rand() % 10;
    }


}

void HugeMatrixClass::PrintMat()
{
    for(unsigned int i = 0; i<_matrix.size(); i++)
    {
        for(unsigned int j = 0; j<_matrix[i].size(); j++)
            std::cout << _matrix[i][j] << " ";
        std::cout << std::endl;
    }
}



int main()
{
    //A reference is an alternate name to an object
    //An Alias
    int num{10};
    int &refnum = num; //intializing refnum to num "&" is the declarator
    //A reference is not an object, but just another name for the obj
    refnum--;   //operation on reference
    std::cout << num << std::endl ; //outputs 9

    //int another_num{10};
    //int &refnum = another_num; //refernce CANNOT be rebind to another object

    //double &ref_another_name = another_num; //reference must be declared with the same type

    //real practical use of referenes can be to send class objects to functions
    //without the overhead of copying one obj to another when send as value

    //Creating a vector of vectors
    //vector< vector<int> > matrix(3, vector<int>(3));
    // vector < vector<int> > matrix(rows, vector<int>(cols, 0));
    //   |         |    |       |     |          |      |    |
    // vector   of  vectors|   var
    // vector<int>(cols, 0) creats an int vector of "cols" number of elements
    // fill it with "0"s
    //

    int rows{3}, cols{3};
    HugeMatrixClass mat(rows, cols);
    mat.PrintMat();
    std::cout << "PopulateMat...\n";
    mat.PopulateMat();
    mat.PrintMat();



	return 0;
}
