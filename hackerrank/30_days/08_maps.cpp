
#include <iostream>
#include <map>


using std::cout;
using std::cin;
using std::endl;

int main()
{

    std::map<std::string, std::string> phonebook;
    std::string name{}, phonenumber{};

    int n{};
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> name >> phonenumber;
        phonebook[name] = phonenumber;
    }

    cin.ignore();
    while(std::getline(cin, name))
    {
        std::map<std::string, std::string>::iterator it = phonebook.find(name);
        //auto it = phonebook.find(name);
        if (it != phonebook.end())
            cout << it->first << "=" << it->second << endl; // first is key, second is value
        else
            cout << "Not found" << endl;
    }

    return 0;
}
