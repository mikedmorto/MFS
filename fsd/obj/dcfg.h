#ifndef DCFG_H
#define DCFG_H

#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/collection>
#include <Wt/Dbo/ptr>

namespace MFS {

class Dcfg
{
public:
    std::string key;
    std::string value;
    std::string info;
    static const std::string tableName;

    template<class Action>
    void persist(Action &a){
        Wt::Dbo::field(a, key, "key");
        Wt::Dbo::field(a, value, "value");
        Wt::Dbo::field(a, info, "info");
    }

};
typedef Wt::Dbo::collection< Wt::Dbo::ptr<Dcfg> > DcfgColl;
}
#endif // DCFG_H
