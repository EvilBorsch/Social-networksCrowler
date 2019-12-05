#include "../AbstractClasses/AbstractAPI.h"
#include "../NetService/NetService.h"

#pragma once

class VkAPI : public AbstractAPI {
private:
    NetService net;
    std::string token;
    std::string app_key;
public:
    [[nodiscard]] const std::string &getToken() const;

    std::vector<url> getPhotoUrlsById(const url &url) override;

    std::vector<url> getFriendsUrlsById(const url &url) ;

    std::vector<url> getGroupParticipants(const url &url) ;

    explicit VkAPI(const std::string &app_key);


    void login() override;

};