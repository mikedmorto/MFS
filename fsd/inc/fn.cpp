#include "fn.h"


bool Fn::replace(string &str, const string &from, const string &to)
{
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

void Fn::replaceAll(string &str, const string &from, const string &to)
{
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}

void Fn::safeSql(string &str)
{
    replaceAll(str,"\\","\\\\");
    replaceAll(str,"'","\\'");
    replaceAll(str,"\"","\\\"");
}

std::string Fn::safeSql(const std::string &str){
    std::string ret = str;
    replaceAll(ret,"\\","\\\\");
    replaceAll(ret,"'","\\'");
    replaceAll(ret,"\"","\\\"");
    return ret;
}

Wt::WString Fn::prepReturn(const string &str)
{
    std::string ret = str;
    replaceAll(ret,"\\'","'");
    replaceAll(ret,"\\\"","\"");
    replaceAll(ret,"\\\\","\\");
    return Wt::WString::fromUTF8(ret);
}

std::vector<std::string> Fn::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> Fn::split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


Wt::WString Fn::to_WtWstring(const unsigned long long &sum)
{
    return Wt::WString(std::to_string(sum));
}
