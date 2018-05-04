#include "dbconfig.h"

using namespace MFS;

void DbConfig::updateConfig(DcfgColl cfgs)
{
    for(DcfgColl::iterator i = cfgs.begin(); i != cfgs.end(); ++i){
        std::string key = (*i)->key;
        if(key == "dbver"){
            this->dbver = (*i)->value;
            continue;
        }
        if(key == "session_timeout"){
            this->session_timeout = stoi((*i)->value);
            continue;
        }
    }
}
