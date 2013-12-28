#include "FileOperation.h"

#ifdef _MSC_VER
  #include <direct.h>
  #define GetCurrentDir _getcwd
#endif

#ifdef __linux
  #include <unistd.h>
  #define GetCurrentDir getcwd
#endif

#include <dirent.h>

#include <sys/stat.h>

#include "Game/Excpetion.h"

namespace NAV
{
	FileOperation::FileOperation() { }

	FileOperation::~FileOperation() { }

	bool FileOperation::checkExistence(std::string path)
	{
		struct stat buf;
		if (stat(path.c_str(), &buf) != -1)
		{
		    return true;
		}
		return false;

	}

	std::string FileOperation::runnningDir()
	{
		char cCurrentPath[500];

		if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
			throw NAV::Exception("Running Path not found");

		cCurrentPath[sizeof(cCurrentPath) - 1] = '\0';
		
		return std::string(cCurrentPath);
	}

	std::vector<std::string> FileOperation::listFilesInDirectory(std::string dir)
	{
		DIR *dp;
		struct dirent *dirp;
		std::vector<std::string> files;
		if ((dp = opendir(dir.c_str())) == NULL)
		{
			std::string erro;
			erro = ("Error opening " + dir);

			std::cout << erro << std::endl;

			throw NAV::Exception(erro);
		}

		while ((dirp = readdir(dp)) != NULL)
		{
			std::string textureName(dirp->d_name);
			if (!(textureName == "." || textureName == ".."))
				files.push_back(std::string(dirp->d_name));
		}
		closedir(dp);

		return files;
	}

	FileOperation* FileOperation::getInstance()
	{
		static FileOperation Instance;

		return &Instance;
	}

}
