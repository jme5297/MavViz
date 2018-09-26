#include "MVIO.h"

int MavViz::IO::loadShaderSource(const char * fname, GLchar* source)
{
	std::string content;
	std::ifstream fileStream(fname, std::ios::in);

	if (!fileStream.is_open())
	{
		std::cerr << "Cout not read file " << fname << ". File does not exist." << std::endl;
		return -1;
	}

	std::string line = "";
	while (!fileStream.eof())
	{
		std::getline(fileStream, line);
		content.append(line + "\n");
	}

	fileStream.close();
	std::cout << content << std::endl;
	source = (GLchar*)content.c_str();

	return 0;
}