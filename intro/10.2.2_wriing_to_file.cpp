/*
 *  10.2.2_wriing_to_file.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Tue 22 Aug 2017 17:43:04 IST
 *  ver    :
 *
 *   A program to read a CSV file with special headers.
 *
 *
 *  input file:
 *
 *  start_line(int) end_line(int) tax_perc(double) Product_name(string)
 *  Transaction_date,Product,Price,Payment_Type,Name,City,State,Country,Account_Created,Last_Login,Latitude,Longitude
 *  1/2/09 6:17,Product1,1200,Mastercard,carolina,Basildon,England,United Kingdom,1/2/09 6:00,1/2/09 6:08,51.5,-1.1166667
 *  .
 *  .
 *  .
 *
 *  Objectives:
 *  Create a Transaction Class
 *  Compute Tax based on tax price
 *  Replace all occurances of "Product1" with Product_name from the first line
 *  Output Lines from Start to End to new file in table format
 *  Output only columns: Transaction_date, Product, Price+taxes, Name
 *
 *
 *
 */


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

class Transaction
{
    private:
        std::string _transaction_date{}, _product{}, _payment_type{}, _name{};
        std::string _city{}, _state{}, _country{}, _accnt_create_date{}, _last_login_date{};
        double _latitude{}, _longitude{}, _price{};

    public:
        Transaction(std::string &get_string);
        ~Transaction(){};

        void ReplaceProductName(std::string &pname);
        void CalculateTaxes(double tax_perc);
        static std::string HeaderPrint(int col_width);
        static void Pad(std::string &s, int col_width);
        static std::string DrawHrLine(int col_width);
        std::string TablePrint(int col_width);


};

Transaction::Transaction(std::string &get_string)
{
    //Transaction_date,Product,Price,Payment_Type,Name,City,State,Country,Account_Created,Last_Login,Latitude,Longitude

    std::string token{};
    std::stringstream get_ss(get_string);
    std::stringstream set_ss;

    while (std::getline(get_ss, token, ','))
    {
        std::replace (token.begin(), token.end(), ' ', '-'); //repalce spaces
        set_ss << token << " ";

    }
    set_ss >> _transaction_date >> _product >> _price >> _payment_type >> _name >> _city
        >> _state >> _country >> _accnt_create_date >> _last_login_date
        >> _latitude >> _longitude;
}

void Transaction::ReplaceProductName(std::string &pname)
{

    _product = pname;
}

void Transaction::CalculateTaxes(double tax_perc)
{

    _price += _price*(tax_perc/100);

}

void Transaction::Pad(std::string& s, int col_width)
{
    s.insert(s.begin(), (col_width - s.size())/2, ' ');
    s.insert(s.end(), (col_width - s.size())/2, ' ');

}

std::string Transaction::DrawHrLine(int col_width)
{

    int hr_line_len = col_width + 2;
    std::stringstream ss;
    ss << " |" << std::string(hr_line_len , '-') << "|"
       << std::string(hr_line_len , '-') << "|"
       << std::string(hr_line_len , '-') << "|"
       << std::string(hr_line_len , '-') << "|" << std::endl;

    return ss.str();
}

std::string Transaction::HeaderPrint(int col_width=20)
{

    int hr_line_len = col_width * 4 + 11; // 13 is the width due to " | "
    std::string c1{"Date"}, c2{"Product"}, c3{"Price"}, c4{"Name"};
    Pad(c1, col_width);
    Pad(c2, col_width);
    Pad(c3, col_width);
    Pad(c4, col_width);

    std::stringstream ss;
    ss << "  " << std::string(hr_line_len, '_') << std::endl
       << " | " << std::setw(col_width) << std::left << c1
       << " | " << std::setw(col_width) << std::left << c2
       << " | " << std::setw(col_width) << std::left << c3
       << " | " << std::setw(col_width) << std::left << c4 << " | " << std::endl
       << DrawHrLine(col_width);

    return ss.str();
}

std::string Transaction::TablePrint(int col_width=20)
{
    //Output only columns: Transaction_date, Product, Price+taxes, Name
    // _______________________________
    //| Date | Product | Price | Name |
    //|------|---------|-------|------|

    std::stringstream ss;
    ss << " | " << std::setw(col_width) << std::left << _transaction_date
       << " | " << std::setw(col_width) << std::left << _product
       << " | " << std::setw(col_width) << std::left << _price
       << " | " << std::setw(col_width) << std::left << _name << " | " << std::endl
       << DrawHrLine(col_width);

    return ss.str();

}


int main()
{



    int col_width{20};
    int start_line{}, end_line{};
    double tax_perc{};
    std::string product_name{};
    std::string in_filename{"sales.csv"}, line{}, out_filename{"out.tb"};

    std::ifstream ifile(in_filename);
    std::ofstream ofile(out_filename); //the table file is binary

    if (ifile) //check if file is readable
    {
        std::getline(ifile, line); //read the first line
        std::stringstream ss(line); //creat stringstream with the first line
        ss >> start_line >> end_line >> tax_perc >> product_name;

        int counter = 0;
        while (++counter < start_line) std::getline(ifile, line); //Do nothing

        ofile << Transaction ::HeaderPrint(col_width);

        while(++start_line <= end_line)
        {

            std::getline(ifile, line);
            Transaction t(line);
            t.ReplaceProductName(product_name);
            t.CalculateTaxes(tax_perc);
            ofile << t.TablePrint(col_width);
        }
        //std::cout << ss.str();
        //ofile << ss.str();

    }




    return 0;
}

