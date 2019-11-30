#include "VkAPI.h"


using std::vector, std::string;


void getPhotosBySizeInResponseData(boost::property_tree::ptree const &pt, std::vector<url> &vec,
                                   const std::string &size = "z") {
    using boost::property_tree::ptree;
    ptree::const_iterator end = pt.end();


    for (ptree::const_iterator it = pt.begin(); it != end; ++it) {
        if (it->first == "type" && it->second.get_value<std::string>() == size) {
            it++;
            vec.push_back(url(it->second.get_value<std::string>()));
            continue;
        }
        getPhotosBySizeInResponseData(it->second, vec, size);

    }
}

vector<url> VkAPI::getPhotoUrlsById(const url &m_url) {
    response resp = net.request(m_url);
    std::vector<url> vec;
    getPhotosBySizeInResponseData(resp.getData(), vec);

    return vec;

}


VkAPI::VkAPI(const string &app_key) {

}

vector<url> VkAPI::getFriendsUrlsById(const url &url) {
    return {};
}

vector<url> VkAPI::getGroupParticipants(const url &url) {
    return {};
}

void VkAPI::login(std::string app_key) {

}
