#include "MVIO.h"

GLchar* MavViz::IO::loadShaderSource(const char * fname)
{
	std::ifstream file;
	file.open(fname, std::ios::in); // opens as ASCII!
	if (!file) return NULL;
	if (!file.good()) return NULL;

	unsigned long pos = file.tellg();
	file.seekg(0, std::ios::end);
	unsigned long len = file.tellg();
	file.seekg(std::ios::beg);
	if (len == 0) return NULL;   // Error: Empty File 

	GLchar* srctxt = (GLchar*) new char[len + 1];
	if (srctxt == 0) return NULL;   // can't reserve memory

	// len isn't always strlen cause some characters are stripped in ascii read...
	// it is important to 0-terminate the real length later, len is just max possible value... 
	srctxt[len] = 0;

	unsigned int i = 0;
	while (file.good())
	{
		srctxt[i] = file.get();       // get character from file.
		if (!file.eof())
			i++;
	}

	srctxt[i] = 0;  // 0-terminate it at the correct position
	file.close();

	return srctxt;
}