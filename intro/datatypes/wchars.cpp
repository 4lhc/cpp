#include <iostream>



int main()
{
    wchar_t name[] = L"മലയാളം ";

    std::locale::global (std::locale ("en_US.UTF-8"));
    std::wcout << name;
}
