/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:04:27 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/15 17:17:51 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"

#include <iostream>
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;

    try
    {
        AForm *rrf = someRandomIntern.makeForm("robotomy request", "Bender");

        Bureaucrat br("NOTSilvio", 50);
        br.signForm(*rrf);
        br.executeForm(*rrf);
        delete rrf;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

