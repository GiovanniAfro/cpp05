/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:22:28 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/12 14:40:46 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _signed(false), _gradeToSign(1), _gradeToExecute(1){}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    try
    {
        if (gradeToSign < 0 || gradeToExecute < 0)
            throw GradeTooHighExeption();
        else if (gradeToSign > 150 || gradeToExecute > 150)
            throw GradeTooLowExeption();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught in AForm constructor: " << e.what() << std::endl;
        throw;
    }
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm::~AForm()
{
    std::cout << "Default AForm destrcutor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        _signed = other._signed;
    }
    return *this;
}

const std::string &AForm::getName() const
{
    return _name;
}

bool AForm::getSigned() const
{
    return _signed;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &br)
{
    try
    {
        if (br.getGrade() <= _gradeToSign)
            _signed = true;
        else
            throw GradeTooLowExeption();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception caught in beSigned: " << e.what() << std::endl;
        throw;
    }
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "AForm: " << form.getName()
       << ", Grade to sign: " << form.getGradeToSign()
       << ", Grade to execute: " << form.getGradeToExecute()
       << ", Signed: " << (form.getSigned() ? "Yes" : "No");

    return os;
}

const char *AForm::GradeTooHighExeption::what() const throw()
{
    return "Grade is too high, you fool";
}

const char *AForm::GradeTooLowExeption::what() const throw()
{
    return "Grade is too low, you fools";
}