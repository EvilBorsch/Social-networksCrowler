#include <string>
#include <vector>

#pragma once


class AbstractAPI {
public:
    virtual std::vector<std::string> get_photo_urls_by_id(const std::string &url) = 0;

    virtual std::vector<std::string> get_friends_urls_by_id(const std::string &url) = 0;

    virtual std::vector<std::string> get_group_participants(const std::string &url) = 0;

    virtual ~AbstractAPI() = default;


};