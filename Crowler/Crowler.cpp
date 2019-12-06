#include "Crowler.h"
#include <iostream>
#include <utility>




std::atomic<bool> thread_must_end(false);

Container Crowler::getContainerFromUrls(const std::vector<url> &urls) {
    return {};
}


void add(Container cont) {

}




Crowler::Crowler(std::shared_ptr<AbstractAPI> m_api, std::shared_ptr<AbstractIdListGeneratorStrategy> m_lg) {
    api = std::move(m_api);
    lg = std::move(m_lg);
};


void Crowler::startCrowl() {
    t = new std::thread(std::bind(&Crowler::crowl, this));

}

void Crowler::stopCrowl() {
    thread_must_end.store(true);

}

void Crowler::crowl() {

    while (true) {

        std::vector<url> id_list = lg->generate();
        for (const auto &id: id_list) {
            std::vector<url> photoUrls = api->getPhotoUrlsById(id);
            for (auto &data: photoUrls) {
                std::cout << data.toStr() << std::endl;
            }

        }

        if (thread_must_end.load()) break;
        lg->save();

    }

}
