//
// Crypt.hpp for $ in /home/kaso/Documents/rendu/EPITECH/YEAR2/PROJECT/cpp_plazza/src/Crypt
// 
// Made by 
// Login   <@epitech.net>
// 
// Started on  Thu Apr  7 00:01:27 2016 
// Last update Fri Apr 15 18:27:13 2016 
//

#ifndef ACRYPT_HPP_
#define ACRYPT_HPP_

#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <algorithm>

class	ACrypt
{
public:
  ACrypt(const std::string &fileName);
  ACrypt() {};
  virtual ~ACrypt() {};
  /**
   * @brief	Does a file decrypt
   * @param	void
   * @return	void
   */
  virtual void	decrypt(void) = 0;
  /**
   * @brief	Gets the decrypt data
   * @param	void
   * @return	const std::string &
   */
  const std::string &getDecryptData(void) const;
  /**
   * @brief	Sets the file to decrypt
   * @param	const std::string &
   * @return	void
   */  
  void	setFileToDecrypt(const std::string &fileName);
  /**
   * @brief	Resets his private data
   * @param	void
   * @return	void
   */  
  void	reset(void);

protected:
  /**
   * @brief	Fills _fileData
   * @param	void
   * @return	void
   */
  void fillFileData(void);
  /**
   * @brief	decrypt one char
   * @param	char c
   * @return	char
   */
  virtual char  decryptChar(char c) = 0;

protected:
  std::string _fileName;
  std::string _fileData;
  std::string _decryptData;
  
};

#endif /* !CRYPT_HPP_ */
