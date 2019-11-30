#include <map>
#include <boost/property_tree/ptree.hpp>
#include "../url/url.h"

class response {
private:
    //std::map<std::string, std::string> mp;
    boost::property_tree::ptree pt;
public:

    void parse(const std::string &st);

    std::string get_body();

    explicit response(const std::string &st) {
        parse(st);
    }

    boost::property_tree::ptree getData() {
        return pt;
    }

    std::vector<std::string> getByKey(const std::string &key);
};
