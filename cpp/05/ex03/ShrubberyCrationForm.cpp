/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCrationForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 01:52:42 by haryu             #+#    #+#             */
/*   Updated: 2022/10/28 00:23:35 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCrationForm.hpp"

// OCCF
ShrubberyCrationForm::ShrubberyCrationForm(void):
	Form("ShrubberyCration", 145, 137), target("none") {}
ShrubberyCrationForm::ShrubberyCrationForm(const std::string& target):
	Form("ShrubberyCration", 145, 137), target(target) {
}
ShrubberyCrationForm::ShrubberyCrationForm(const ShrubberyCrationForm& target):
	Form(target.getName(), target.getGrade(0), target.getGrade(1)), target(target.target) {}

ShrubberyCrationForm::~ShrubberyCrationForm(void) {}

ShrubberyCrationForm& ShrubberyCrationForm::operator=(const ShrubberyCrationForm& target) {
	this->target = target.target;
	return *this;
}

/* ************************************************************************** */
// execute

void	ShrubberyCrationForm::execute(const Bureaucrat & Executor) const {
	std::ofstream	berry;
	std::ifstream	tree;
	std::string		filename = target;

	filename.append("_shrubbery");
	berry.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);

	tree.open("ascii-art.txt", std::ifstream::in);
	while (true) {
		char *buffer = new char [101];
		buffer[100] = 0;
		tree.read(buffer, 100);
		berry << buffer;
		delete[] buffer;
		if (tree.eof())
			break ;
	}
	tree.close();
	berry.close();
	std::cout << "[Forms] " <<  "Making Shrubbery cration is completed. : " << Executor.getName() << std::endl;
}