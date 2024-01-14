/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:33:57 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/14 19:24:25 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 147, 137), _target("ShrubberyCreationForm") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        // Copia gli attributi necessari, ad esempio _target
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Default destrcuto of SHrubbery called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    AForm::execute(executor);

    std::ofstream outfile((_target + "_shrubbery").c_str());
    if (outfile.is_open())
    {
        outfile << "    *\n";
        outfile << "   ***\n";
        outfile << "  *****\n";
        outfile << " *******\n";
        outfile << "*********\n";
        outfile << "    |\n";
        outfile.close();
    } 
    else
    {
        std::cout << "Warning: Unable to open file for ShrubberyCreationForm" << std::endl;
    }
}