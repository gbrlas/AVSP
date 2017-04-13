#include <iostream>

double calculate_time(double c, double f, double x)
{
    double rate = 2.0;
    double time = 0.0;

    while (true)
    {
        double wait = x / rate;
        double build = c / rate;
        double build_and_wait = build + x / (rate + f);

        //std::cout << "time: " << time << "\trate: " << rate << "\twait: " << wait << "\tbuild: " << build << "\tbulid_and_wait: " << build_and_wait << std::endl;

        if (wait < build_and_wait)
            return time + wait;
        time += build;
        rate += f;
    }

    return 0.0;
}

void solve(int case_no)
{
    double c;
    double f;
    double x;

    std::cin >> c >> f >> x;

    double time = calculate_time(c, f, x);

    std::cout.precision(15);
    std::cout << "Case #" << case_no << ": " << time << std::endl;
}

int main()
{
    int test_cases;
    std::cin >> test_cases;

    for (int i = 1; i <= test_cases; ++i)
        solve(i);
}