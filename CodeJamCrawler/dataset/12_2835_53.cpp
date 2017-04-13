#ifndef _SHARED_JAM_2012
#define _SHARED_JAM_2012

#include <string>
#include <vector>

// text processing
void Split(const std::string& rsIn, const char* psDelimit, std::vector<std::string>& rvOut);
void Split(const std::string& rsIn, const char* psDelimit, std::vector<int>& rvOut);
void Split(const std::string& rsIn, const char* psDelimit, std::vector<unsigned int>& rvOut);

std::string ToString(unsigned int i);
unsigned int ToUInt(const char* ps);

#endif