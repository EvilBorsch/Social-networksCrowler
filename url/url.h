//
// Created by Дмитрий Гуляченков on 16.11.2019.
//
#include <iostream>

#ifndef KURSACH_FINAL_URL_H
#define KURSACH_FINAL_URL_H

class url {

    std::string base_url = "";

    std::string protocol = "";
    std::string host = "";

    void parse(const std::string &mUrl) {

        if (mUrl[6] == '/' && mUrl[7] == '/') {
            for (const char &ch:mUrl) {
                if (ch == '/') break;
                protocol += ch;
            }
            protocol += "//";
        } else {
            throw "not supported protocol";
        }
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

    explicit url(const std::string &st) {
        parse(st);
    }


    std::string toStr() {
        return protocol + host + base_url;
    }


    void vkStyle(std::string m_url) {
        protocol = "https://";
        host = "api.vk.com";
        base_url = m_url;
    }


    friend bool operator==(const url &m_url1, const url &m_url) {
        return true;
    }


    url() = default;

};

#endif //KURSACH_FINAL_URL_H
