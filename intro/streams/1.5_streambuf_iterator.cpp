/*  
 *  1.5_streambuf_iterator.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Tue 24 Apr 2018 07:27:17 IST
 *  ver    : 
 *   
 */


#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
    using std::istreambuf_iterator;
    using std::ostreambuf_iterator;


    istreambuf_iterator<char> isbuf(std::cin);
    ostreambuf_iterator<char> osbuf(std::cout);

    std::copy()



	return 0;
}
