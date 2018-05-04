#ifndef DBCONFIG_H
#define DBCONFIG_H

#include <iostream>
#include <fstream>
#include <dlfcn.h>
#include "def.h"
#include "dcfg.h"

namespace MFS {


class DbConfig
{
public:
    ////////////////
    std::string addr;
    std::string name;
    std::string login;
    std::string pass;
    bool isDebugSQL;
    ////////////////
    /// internal configuration into databse
    std::string dbver;
    int session_timeout;

    // FS configuration:
    // fs tmp directory
    std::string fstmp;
    // fs buffer size
    int fsbuff;
    // util_key is key for access to utilisation algorithms
    std::string util_key;

    DbConfig(){
        this->isDebugSQL = false;
        this->session_timeout = DEFSEST;
        this->fstmp = FSTMP;
        this->fsbuff = FSBUFF;
        this->util_key = "";
    }
    void updateConfig(DcfgColl cfgs);
};
}

#endif // DBCONFIG_H
