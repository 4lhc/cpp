/*
 *  03-JobSeq.cpp
 *
 *  author : Sreejith S
 *  email  : echo $(base64 -d <<< NDQ0bGhjCg==)@gmail.com
 *  date   : Sat 09 May 2020 23:35:54 IST
 *  ver    :
 *  compile:
 *  g++ -Wall -Wextra -pedantic -g -std=c++14 -o test  03-JobSeq.cpp
 */


#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cout;
using std::cin;


struct Job
{
    int job_id;
    int profit;
    int deadline;

    Job(int j, int p, int d): job_id(j), profit(p), deadline(d) {}

    bool operator < (const Job& j) const //const funct
    {
        return (profit > j.profit);
    }
};


int main()
{

    vector<Job> job_list;
    job_list.push_back(Job(1, 100, 2));
    job_list.push_back(Job(2, 10, 1));
    job_list.push_back(Job(3, 15, 2));
    job_list.push_back(Job(4, 27, 1));
    int slots = 2;
    vector<int> seq(slots, -1);

    std::sort(job_list.begin(), job_list.end());

    for(auto j:job_list)
    {
        for(int i = std::min(slots, j.deadline)-1; i >= 0; i--)
        {
            if (seq[i] == -1)
            {
                seq[i] = j.job_id;
                break;
            }
        }
        cout << j.job_id << " | " << j.profit << " | " << j.deadline << "\n";
    }
    cout << "Job Seq: { ";
    for(auto s:seq)
    {
        cout << s << " ";
    }
    cout << "}\n";

	return 0;
}
