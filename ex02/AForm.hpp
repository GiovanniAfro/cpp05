/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:57:37 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/12 14:34:42 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat; //La forward declaration (dichiarazione anticipata),è utilizzata per informare il compilatore che esiste una classe chiamata Bureaucrat, anche se i dettagli completi della sua implementazione non sono ancora noti a questo punto.

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        class GradeTooHighExeption : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowExeption : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        AForm();
        AForm(const std::string &name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        virtual ~AForm();

        AForm &operator=(const AForm &other);

        const std::string &getName() const;
        bool getSigned() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;

        void beSigned(const Bureaucrat &br);
        virtual void execute(const Bureaucrat &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif