#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

std::string get_answer_line()
{
    int answer;
    std::cin >> answer;

    std::string answer_line;
    std::getline(std::cin, answer_line);
    for (int i = 1; i <= 4; ++i)
    {
        std::string line;
        std::getline(std::cin, line);
        if (i == answer)
        {
            answer_line = line;
        }
    }

    return answer_line;
}

std::vector<int> parse_row(const std::string& row)
{
    std::vector<int> result;

    std::istringstream is(row);

    while (!is.eof())
    {
        int n;
        is >> n;
        result.push_back(n);
    }
    return result;
}

std::vector<int> intersect(std::vector<int>& first, std::vector<int>& second)
{
    std::vector<int> result;
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());
    std::set_intersection(first.begin(), first.end(), second.begin(), second.end(), std::back_inserter(result));
    return result;
}

void solve(int case_no)
{
    std::string first_answer = get_answer_line();
    std::string second_answer = get_answer_line();

    std::vector<int> first_row = parse_row(first_answer);
    std::vector<int> second_row = parse_row(second_answer);

    std::vector<int> intersection = intersect(first_row, second_row);

    std::cout << "Case #" << case_no << ": ";
    if (intersection.empty())
    {
        std::cout << "Volunteer cheated!";
    }
    else if (intersection.size() == 1)
    {
        std::cout << intersection[0];
    }
    else
    {
        std::cout << "Bad magician!";
    }
    std::cout << std::endl;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    for (int i = 1; i <= test_cases; ++i)
        solve(i);
}