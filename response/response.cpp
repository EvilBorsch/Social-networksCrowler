//
// Created by Дмитрий Гуляченков on 29.11.2019.
//

#include "response.h"


#include <boost/property_tree/json_parser.hpp>
#include <sstream>

void response::parse(const std::string &st) {
    std::stringstream ss(st);
    boost::property_tree::read_json(ss, pt);

}

std::string response::get_body() {
    return std::string();
}

std::vector<std::string> response::getByKey(const std::string &key) {
    std::vector<std::string> result;
    auto response = pt.get_child("response.items");
    for (const auto &test:response) {
        result.push_back(test.second.get<std::string>("id"));
    }
    return result;
}





