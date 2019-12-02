//
// Created by Дмитрий Гуляченков on 16.11.2019.
//
#include <iostream>

#ifndef KURSACH_FINAL_URL_H
#define KURSACH_FINAL_URL_H

class url {

public:
    const std::string &getBaseUrl() const {
        return base_url;
    }

    const std::string &getProtocol() const {
        return protocol;
    }

    const std::string &getHost() const {
        return host;
    }

private:

    std::string base_url = "";
    std::string protocol = "";
    std::string host = "";

    void parse(const std::string &mUrl) {

        std::copy(mUrl.begin(), mUrl.begin() + 8, std::back_inserter(protocol)); //TODO дописать все через copy в url


        std::string temp_data = "";
        size_t baseUrlIndex = 0;
        for (size_t i = 8; i < mUrl.length(); i++) {
            baseUrlIndex = i;
            char ch = mUrl[i];
            if (ch == '/') {
                host = temp_data;
                break;
            }
            temp_data += ch;
        }
        for (size_t i = baseUrlIndex; i < mUrl.length(); i++) {
            base_url += mUrl[i];
        }

    };


public:

    explicit url(const std::string &st, const std::string type = "full") {
        if (type == "vk") {
            protocol = "https://";
            host = "vk.com";
            base_url = "/" + st;
        } else if (type == "ok") {
            protocol = "https://";
            host = "ok.ru";
            base_url = "/" + st;
        } else if (type == "facebook") {
            protocol = "https://";
            host = "ok.ru";
            base_url = "/" + st;
        } else {
            parse(st);
        }
    }


    std::string toStr() {
        return protocol + host + base_url;
    }


    void vkStyle(std::string m_url) {
        protocol = "https://";
        host = "api.vk.com";
        base_url = m_url;
    }


    void vkStyleId(std::string id) {
        protocol = "https://";
        host = "vk.com";
        base_url = "/id" + id;
    }


    std::string getVkId() const {
        std::string id = "";
        for (int i = 3; i < base_url.size(); i++) {
            id += base_url[i];
        }
        return id;
    }

    void getVkPhotosRequestUrl(std::string token, std::string id) {
        protocol = "https://";
        host = "api.vk.com";

        base_url = "/method/photos.get?owner_id=" + id + "&album_id=profile&access_token=" + token +
                   "&v=5.103";
    }


    void getVkLoginRequestUrl(std::string app_key) {
        protocol = "https://";
        host = "oauth.vk.com";
        base_url = "/authorize?client_id=" + app_key +
                   "&display=page&redirect_uri=https://oauth.vk.com/blank.html&scope=friends&response_type=token&v=5.52";

    }


    friend bool operator==(const url &m_url1, const url &m_url2) {
        if (m_url1.base_url == m_url2.base_url && m_url1.host == m_url2.host &&
            m_url1.protocol == m_url2.protocol)
            return true;
        return false;
    }


    url() = default;

};

#endif //KURSACH_FINAL_URL_H
