#include "Crowler.h"
#include <iostream>


Container Crowler::getContainerFromUrls(const std::vector<url> &urls) {
    return {};
}


Crowler::Crowler(AbstractAPI *m_api, AbstractIdListGeneratorStrategy *m_lg) {
    api = m_api;
    lg = m_lg;
}

void add(Container cont) {

}


void Crowler::startCrowl() {
    t = new boost::thread(boost::bind(&Crowler::crowl, this));

}


void save() {
    std::cout << "zaseyvil"; //TODO save v BD
}


void Crowler::stopCrowl() {
    t->interrupt();

}

void Crowler::crowl() {

    while (true) {
        try {
            std::vector<url> id_list = lg->generate();
            for (const auto &id: id_list) {
                std::vector<url> photoUrls = api->getPhotoUrlsById(id);
                for (auto &data: photoUrls) {
                    std::cout << data.toStr() << std::endl;
                }

            }
        }
        catch (boost::thread_interrupted &) {
            save();
        }
    }

}
