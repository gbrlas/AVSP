/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file b.cpp
 * @author wuyuliang(wuyuliang@baidu.com)
 * @date 2014/04/12 13:14:26
 * @version $Revision$ 
 * @brief 
 *  
 **/
#include <iostream>
#include <iomanip>

double min(double a, double b)
{
    return a > b? b : a;
}
int main()
{
    double C, F, X;
    int t, testcase = 1;

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w+", stdout);
    std::cin >> t;
    while (t--)
    {
        std::cin >> C >> F >> X;
        double day = 2.0, time = min(X, C) / day, x = X - min(X, C);
        while (x / day * F > C)
        {
            x += C;
            day += F;
            time += min(x, C) / day;
            x = x - min(x, C);
        }
        time += x / day;
        std::cout << "Case #" << testcase++ << ": ";
        std::cout.setf(std::ios::fixed);
//        std::cout.setf(std::ios::showpoint);
        std::cout.precision(7);
        std::cout << time << std::endl;
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
