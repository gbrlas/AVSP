/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
 /**
 * @file a.cpp
 * @author wuyuliang(wuyuliang@baidu.com)
 * @date 2014/04/12 13:53:38
 * @version $Revision$ 
 * @brief 
 *  
 **/
#include <iostream>

int main()
{
    int t, test_case = 1;

    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w+", stdout);
    std::cin >> t;
    while (t--)
    {
        int first[4][4], second[4][4], first_index, second_index;
        std::cin >> first_index;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                std::cin >> first[i][j];
            }
        }
        std::cin >> second_index;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                std::cin >> second[i][j];
            }
        }

        first_index--, second_index--;
        int k = 0, num;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (first[first_index][i] == second[second_index][j])
                {
                    k++;
                    num = first[first_index][i];
                }
            }
        }
        std::cout << "Case #" << test_case++ << ": ";
        if (k > 1)
        {
            std::cout << "Bad magician!" << std::endl;
        }
        else if (k == 1)
        {
            std::cout << num << std::endl;
        }
        else
        {
            std::cout << "Volunteer cheated!" << std::endl;
        }
    }
    return 0;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 */
