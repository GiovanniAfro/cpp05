/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:33:57 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/13 14:21:34 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 147, 137), _target("ShrubberyCreationForm") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation", 145, 137), _target(_target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != other)
        AForm::operator=(other)
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Default destrcuto of SHrubbery called" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if(!getSigned())
    {
        std::cout << "Warning: ShrubberyCreationForm is not signed. Cannot execute." << std::endl;
        return;
    }

    if (executor.getGrade() > getGradeToExecute()) 
        throw GradeTooLowException();

    std::ofstream outfile(_tearget + "_shrubbery");
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