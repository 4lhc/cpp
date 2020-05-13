

#include <iostream>
#include <vector>


using std::cout;
using std::cin;
using std::endl;

template <typename T>
class Matrix
{
    private:
        int rows{}, cols{};
        std::vector<std::vector<T> > mat;
    public:
        Matrix();
        Matrix(int rows, int cols);
        ~Matrix(){};
        T ISum(int i, int j);
        void PopulateMat();

};

    template <typename T>
Matrix<T>::Matrix()
    : mat(0, std::vector<T>(0, 0)) //field intialize a zero mat of zero size
{}

    template <typename T>
Matrix<T>::Matrix(int in_rows, int in_cols)
    : rows(in_rows), cols(in_cols), mat(rows, std::vector<T>(cols, 0)) //field intialize a zero mat of rowsxcols
{}


//return the sum of hourglass -- accepts the web i,j as argument
    template <typename T>
T Matrix<T>::ISum(int i, int j)
{

    T sum{mat[i][j]}; //intialize sum with web element

    //for(int di = 0; di < 6; di++) { for(int dj = 0; dj < 6; dj++) { cout << mat[di][dj] << " "; } cout << endl; }

    for(int di = -1; di <= 1; di++)
    {
        if ( di != 0)
        {
            for(int dj = -1; dj <=1; dj++)
            {
                sum += mat[i+di][j+dj];
                //cout << i+di << ", " << j+dj <<  ": " << mat[i+di][j+dj] << endl;
            }
        }
    }
    return sum;
}

template <typename T>
void Matrix<T>::PopulateMat()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> mat[i][j];
        }
    }
}

int main()
{

    int c{6}, r{6}; //intialize rows and cols size
    Matrix<int> m1(r, c);
    m1.PopulateMat();
    //loop to read all possible I's
    int largest_I{-64}; //since problem states input in range (-9, 9)
    // the max sum of 7 elements of I won't exceed 63
    int sum_of_I{0};
    for(int i = 1; i < r-1; i++)
    {
        for(int j = 1; j < c-1; j++)
        {
            sum_of_I = m1.ISum(i, j);
            if ( sum_of_I > largest_I)
            {
                largest_I = sum_of_I;
            }
            cout << i << ", " << j << ": " << sum_of_I << endl;
        }
    }

    cout << largest_I << endl;
    return 0;
}
