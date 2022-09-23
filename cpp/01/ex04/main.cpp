/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haryu <haryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:24:16 by haryu             #+#    #+#             */
/*   Updated: 2022/09/24 03:02:55 by haryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief string 자료형을 활용한 ft_strlen 구현
 * 
 * @param str 
 * @return size_t 
 */
size_t	MyStrlen(const char *str) {
	std::string target(str);

	return target.size();
}

/**
 * @brief 입력받은 파일의 크기를 확인하는 함수
 * 
 * @param ifs 입력 받은 파일
 * @return int 문자열 크기
 */
int		GetStringSize(std::ifstream& ifs) {
	int	length;

	ifs.seekg(0, ifs.end);
	length = ifs.tellg();
	ifs.seekg(0, ifs.beg);
	return length;
}

/**
 * @brief s1 문장을 s2 문장으로 바꾸기 
 * 
 * @param temp 타겟이 되는 파일 string 객체
 * @param openedFile 입력받은 파일
 * @param av s1, s2 문자열
 */
void	ChangeS1toS2(std::string& temp, char *openedFile, char **av) {
	size_t	pos;

	temp.clear();
	temp.assign(openedFile);
	pos = temp.find(av[2]);
	while (pos != std::string::npos) { 
		temp.erase(pos, MyStrlen(av[2]));
		temp.insert(pos, av[3]);
		pos = temp.find(av[2]);
	}
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
		std::cout << "> ./ex04 {file} {string s1} {string s2}" << std::endl;
		return (1);
	}

	std::ifstream	ifs(av[1], std::ios_base::in);
	std::ofstream	ofs;
	std::string		temp;
	char*			openedFile;
	int				length;

	temp.assign(av[1]);
	if (ifs.is_open()) {std::cout << "File is opened : " << temp << std::endl;}
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
	length = GetStringSize(ifs);
	openedFile = new char[length];
	ifs.read(openedFile, length);
	ChangeS1toS2(temp, openedFile, av);
	ofs << temp;
	ofs.close();
	ifs.close();
	delete[] openedFile;
	return (0);
}