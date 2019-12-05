#include "../AbstractClasses/AbstractAPI.h"
#include "../NetService/NetService.h"

#pragma once

class FacebookAPI : public AbstractAPI {
private:
    NetService curler;
    std::string token;
public:
    std::vector<url> getPhotoUrlsById(const url &url) override;

    std::vector<url> getFriendsUrlsById(const url &url) ;

    std::vector<url> getGroupParticipants(const url &url) ;

    explicit FacebookAPI(const std::string &app_key);

    void login() override;


};