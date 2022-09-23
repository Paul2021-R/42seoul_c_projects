/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:24:16 by haryu             #+#    #+#             */
/*   Updated: 2022/09/23 17:01:33 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

size_t	ft_strlen(const char *str) {
	std::string target(str);

	return target.size();
}

/**
 * @brief 파일명, 스트링 s1, 스트링 s2를 받고 파일명으로 파일을 연 뒤 파일의 내용 중 s1을 수정하여 s2로 바꾼뒤 `파일명.replace`의 파일을 생성해라. 단 string 클래스의 replace 사용을 금한다. 
 * 
 * @param ac 
 * @param av 파일명, string s1, s2
 * @return int 
 */
int main(int ac, char **av) {
	if (ac != 4) {
		std::cout << "Please, type 3 arguments for proper execution." << std::endl;
		std::cout << "> ex04 {file} {string s1} {string s2}" << std::endl;
		return (1);
	}

	std::ifstream	ifs(av[1], std::ios_base::in);
	std::ofstream	ofs;
	std::string		temp;
	char*			openedFile;
	int				length;
	size_t			pos;

	temp.assign(av[1]);
	if (ifs.is_open()) {
		std::cout << "File is opened : " << temp << std::endl;
	}
	else {
		std::cerr << "Their is no file : " << temp << std::endl;
		return (1);
	}
	temp.append(".replace");
	ofs.open(temp.c_str(), std::ios_base::out | std::ios_base::trunc);
	if (!ofs.is_open()) {
		std::cerr << "Making replacement is failed : " << temp << std::endl;
		return (1);
	}
	std::cout << "Replacement is ready : " << temp << std::endl;
	ifs.seekg(0, ifs.end);
	length = ifs.tellg();
	ifs.seekg(0, ifs.beg);
	openedFile = new char[length];
	ifs.read(openedFile, length);
	temp.clear();
	temp.assign(openedFile);
	pos = temp.find(av[2]);
	while (pos != std::string::npos) { 
		temp.erase(pos, ft_strlen(av[2]));
		temp.insert(pos, av[3]);
		pos = temp.find(av[2]);
	}
	ofs << temp;
	ofs.close();
	ifs.close();
	delete[] openedFile;
	return (0);
}