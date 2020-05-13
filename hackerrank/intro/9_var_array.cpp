

#include <iostream>
#include <vector>


int main()
{
    int n{}, q{};

    std::cin >> n >> q;

    std::vector<std::vector<int>> v_mat(n, std::vector<int>(0));

    int m, input; //index of main vector
    for(int i = 0; i < n; i++)
    {

        std::cin >> m;
        for(int j = 0; j < m; j++)
        {
            std::cin >> input;
            v_mat[i].push_back(input);
        }

    }

    int i, j;
    for (int qi = 0; qi < q; qi++)
    {
        std::cin >> i >> j;
        std::cout << v_mat[i][j] << std::endl;

    }

    return 0;
}
