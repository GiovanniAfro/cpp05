/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:04:27 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/13 18:22:10 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // Creazione di un Bureaucrat
    Bureaucrat bureaucrat("Silvio", 50);

    // Creazione di alcune forme
    ShrubberyCreationForm shrubberyForm("Garden");
    RobotomyRequestForm robotomyForm("Target");
    PresidentialPardonForm pardonForm("Person");

    // Firma delle forme
    try
    {
        shrubberyForm.beSigned(bureaucrat);
        robotomyForm.beSigned(bureaucrat);
        pardonForm.beSigned(bureaucrat);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught during signing: " << e.what() << std::endl;
    }

    // Tentativo di esecuzione delle forme
    try
    {
        bureaucrat.executeForm(shrubberyForm);
        bureaucrat.executeForm(robotomyForm);
        bureaucrat.executeForm(pardonForm);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught during form execution: " << e.what() << std::endl;
    }

    return 0;
}
