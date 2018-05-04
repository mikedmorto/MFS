#include <Wt/WServer>
#include <Wt/WResource>
#include <Wt/Http/Response>

#include "dbconfig.h"
#include "def.h"

using namespace Wt;


int main(int argc, char **argv)
{
    try {
        WServer server(argv[0],"fsd.cfg");
        Wt::log("info")<<APPNAME<< " version "<<GIT_VERSION;
        Wt::log("info")<<"DB version    - "<<DBVER;
        Wt::log("info")<<"API version   - "<<APIVER;
        Wt::log("info")<<"Build ts      - "<<__DATE__<<" "<<__TIME__;
        server.setServerConfiguration(argc, argv);

        // считываем конфигурацию
        std::string debugsql = "";
        std::string buffsize = "";
        MFS::DbConfig dbconfig;
        std::string rootmessage = "";


        server.readConfigurationProperty("dbaddr",dbconfig.addr);
        server.readConfigurationProperty("dbname",dbconfig.name);
        server.readConfigurationProperty("dblogin",dbconfig.login);
        server.readConfigurationProperty("dbpass",dbconfig.pass);
        server.readConfigurationProperty("debugsql",debugsql);
        server.readConfigurationProperty("rootmessage",rootmessage);
        server.readConfigurationProperty("fstmp",dbconfig.fstmp);
        server.readConfigurationProperty("fsbuff",buffsize);
        server.readConfigurationProperty("util_key",dbconfig.util_key);
        if(debugsql == "yes"){
            dbconfig.isDebugSQL = true;
        }
        dbconfig.fsbuff = std::atoi(buffsize.c_str());

        if(dbconfig.fsbuff <= 0){
            Wt::log("info")<<"fsbuff is null. Setup default value = "<<FSBUFF;
            dbconfig.fsbuff = FSBUFF;
        }

        if(dbconfig.util_key == ""){
            Wt::log("alert")<<"util_key is empty. exit";
            exit(1);
        }

        Wt::log("TEST")<<"DONE";
        
        if (server.start()) {
            WServer::waitForShutdown();
            server.stop();
        }else{
            Wt::log("error")<< "failure to start";
            exit(1);
        }
    } catch (WServer::Exception& e) {
        Wt::log("error")<< e.what();
    } catch (std::exception &e) {
        Wt::log("error")<< "exception: " << e.what();
    }
}

