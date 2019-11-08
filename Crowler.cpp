#include "Crowler.h"
#include <iostream>

Container Crowler::get_container_from_urls(const vector<string> &urls) {
    return Container();
}


Crowler::Crowler(AbstractAPI *m_api, Abstract_id_list_generator_strategy *m_lg) {
    api = m_api;
    lg = m_lg;
}

void add(Container cont) {

}

void Crowler::start_crowl() {
    while (state) {
        id_list = lg->generate();
        for (const auto &id: id_list) {
            vector<string> photo_urls = api->get_photo_urls_by_id(id);
            Container cont = get_container_from_urls(photo_urls);
            add(cont);
        }
    }

}

void Crowler::stop_crowl_and_save_id_list() {

}

void Crowler::set_api_and_id_generator_strategy(AbstractAPI *m_api, Abstract_id_list_generator_strategy *m_lg) {
    api = m_api;
    lg = m_lg;
}
