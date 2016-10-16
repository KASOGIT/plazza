/*
** Parser.cpp for cpp_plazza
**
** Made by	Julian Vives
** Login	vives_j
**
** Started on	Thu Apr 07 22:25:47 2016 Julian Vives
** Last update	Wed Apr 13 19:02:49 2016 Julian Vives
*/

#include "Parser.hpp"

Parser::Parser() {

}

Parser::~Parser() {

}

void			                    Parser::readLine() {
  std::getline(std::cin, _strToParse);
}

std::vector<std::string>			Parser::split(const std::string& s, char const delim) {
  std::vector<std::string> v;
  std::stringstream stream(s);
  std::string token;

  while (std::getline(stream, token, delim)) {
    v.push_back(token);
  }
  return v;
}

bool													Parser::getInformation(const std::string &x, int &info) {
    if (TAB_INFO.count(x) > 0) {
      info = TAB_INFO.at(x);
      return true;
    }
    return false;
}

std::vector<Order *> 					Parser::parse() {
  std::vector<std::string>		stringsToAnalyse(this->split(_strToParse, DELIM));
  std::vector<Order *>				orderArray;
  int													info = -1;
  std::vector<std::string>		fileList;
  int													i;

  for (auto &x : stringsToAnalyse) {
    i = 0;
    if (x.empty())
      continue;

    for (auto &y : this->split(x, ' ')) {
      if (y.empty())
	     continue;
      if (!this->getInformation(y, info))
	     fileList.push_back(y);
      if (i == 0 && info != -1) {
	      info = -1;
	      fileList.clear();
	      break;
      }
      i++;
    }

    if (info != -1 && !fileList.empty()) {
      Order		*toInsert = new Order;
      toInsert->infoToGet = static_cast<enum Informations>(info);
      toInsert->fileLists = fileList;
      orderArray.push_back(toInsert);
      info = -1;
      fileList.clear();
    }
  }
  return orderArray;
}
