#include "Vk_id_list_generator_strategy.h"
#include <fstream>

std::vector<url> VkIdListGeneratorStrategy::generate() {

    url mUrl;
    std::vector<url> vec;
    for (size_t i = currentId; i < currentId + size; i++) {

        mUrl.getVkPhotosRequestUrl(token, i);
        vec.push_back(mUrl);

    }

    return vec;
}

size_t VkIdListGeneratorStrategy::getCurrentId() {
    std::ifstream fin(path);
    fin >> currentId;
    return currentId;
}









