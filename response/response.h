#include <boost/property_tree/ptree.hpp>
#include "../url/url.h"
#include <boost/property_tree/json_parser.hpp>

class response {
private:
    //std::map<std::string, std::string> mp;
    boost::property_tree::ptree pt;
public:

    void parse(const std::string &st){
        std::stringstream ss(st);
        boost::property_tree::read_json(ss, pt);
    };

    explicit response(const std::string &st) {
        parse(st);
    }

    boost::property_tree::ptree getData() {
        return pt;
    }


};
