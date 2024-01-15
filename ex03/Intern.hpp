/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:00:05 by gcavanna          #+#    #+#             */
/*   Updated: 2024/01/15 18:15:40 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const std::string &target);
    ~Intern();

    Intern  &operator=(const Intern &other);

    AForm *makeForm(const std::string &formName, const std::string &target);

private:
    typedef AForm *(Intern::*createFormFunction)(const std::string &);
    
    struct FormInfo
    {
        const char *name;
        createFormFunction creator;
    };

    AForm *createPresidentialPardon(const std::string &target);
    AForm *createRobotomyRequest(const std::string &target);
    AForm *createShrubberyCreation(const std::string &target);
};

#endif 
