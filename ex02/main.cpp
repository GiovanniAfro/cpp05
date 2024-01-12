/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:04:27 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/12 15:57:28 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

int main()
{
    Bureaucrat br1("Silvio", 50);
    Bureaucrat br2("Ascano", 1);

    AForm form("tasse", 40, 30);

    std::cout << "before signing:\n" << form << "\n\n";
    
    try
    {
        //form.beSigned(br1);
        form.beSigned(br2);

        std::cout << "After signing:\n" << form << "\n";
    }

    catch (const std::exception &e)
    {
        std::cerr << "Exeption caught in main: " << e.what() << std::endl;
    }

    return 0;
}