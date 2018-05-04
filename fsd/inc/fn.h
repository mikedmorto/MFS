#ifndef FN_H
#define FN_H

#include <string>
#include <Wt/Utils>
#include <Wt/WString>
#include <iostream>
#include <fstream>
#include <dlfcn.h>
#include <string>
#include <sstream>
#include <vector>

#include "def.h"

using namespace std;

class Fn{
public:
    static bool replace(std::string& str, const std::string& from, const std::string& to);
    static void replaceAll(std::string& str, const std::string& from, const std::string& to);
    static void safeSql(std::string& str);
    static std::string safeSql(const std::string &str);
    static Wt::WString prepReturn(const std::string &str);
    static std::vector<std::string> split(const std::string &s, char delim, std::vector<std::string> &elems);
    static std::vector<std::string> split(const std::string &s, char delim);
    static Wt::WString to_WtWstring(const long long unsigned int &sum);

};

#endif
