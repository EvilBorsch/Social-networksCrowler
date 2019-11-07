#include <iostream>
#include "Crowler.h"
#include "VkAPI.h"
#include "Vk_id_list_generator_strategy.h"


int main() {
    VkAPI vk_api("asd");
    Vk_id_list_generator_strategy id_generator(2);
    Crowler cr(&vk_api,&id_generator);
    cr.start_crowl();

}