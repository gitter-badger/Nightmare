#ifndef FILEOPERATION_H
#define FILEOPERATION_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace NAV
{
	class FileOperation
	{
	public:
		static FileOperation* getInstance();

		std::vector<std::string> listFilesInDirectory(std::string dir);
		bool checkExistence(std::string path);
		std::string runnningDir();

	private:
		FileOperation();
		~FileOperation();
	};
}
#endif
