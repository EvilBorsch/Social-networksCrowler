#include "../AbstractClasses/AbstractAPI.h"
#include "../NetService/NetService.h"

#pragma once

class FacebookAPI : public AbstractAPI {
private:
    NetService curler;
    std::string token;
public:
    std::vector<url> getPhotoUrlsById(const url &url) override;

    explicit FacebookAPI(const std::string &app_key);

    void login() override;


};