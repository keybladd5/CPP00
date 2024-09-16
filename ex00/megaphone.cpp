/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meaphone.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:26:34 by polmarti          #+#    #+#             */
/*   Updated: 2024/09/13 19:26:36 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; argv[i]; i++)
        {
            for (int x = 0; argv[i][x]; x++)
                std::cout << (char)std::toupper(argv[i][x]);
        }
        std::cout << std::endl;
    }
    return (0);
}

