#include "../AbstractClasses/AbstractAPI.h"
#include "../Curl/Curl.h"

#pragma once

class OkAPI : public AbstractAPI {
private:
    Curl curler;
    std::string token;
public:
    std::vector<std::string> get_photo_urls_by_id(const std::string &url) override;

    std::vector<std::string> get_friends_urls_by_id(const std::string &url) override;

    std::vector<std::string> get_group_participants(const std::string &url) override;

    explicit OkAPI(const std::string &app_key);

};