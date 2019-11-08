#include "Vk_id_list_generator_strategy.h"


vector<string> Vk_id_list_generator_strategy::generate() {
    vector<string> data=load_urls_from_disk();
    return vector<string>();
}

vector<string> Vk_id_list_generator_strategy::load_urls_from_disk(){
    return vector<string>();
}

string Vk_id_list_generator_strategy::get_path() {
    return path;
}
