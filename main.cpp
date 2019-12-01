#include "NetService/NetService.h"
#include "API/VkAPI.h"
#include "Id_list_generator_strategy/Vk_id_list_generator_strategy.h"


int main(int argc, char *argv[]) {

    VkAPI vk("asd");
    vk.login();




    /*
    url m_url;
    m_url.vkStyle(
            "/method/photos.get?owner_id=184059480&album_id=profile&access_token=af2d806eaf2d806eaf2d806e66af40fd7daaf2daf2d806ef28431079864b75a45b322d9&v=5.103");

    std::vector<url> res=vk.getPhotoUrlsById(m_url);

    for (auto lol : res){
        std::cout<< lol.toStr() << std::endl;
    }
     */





    VkIdListGeneratorStrategy vkId(6, "/Users/dmitrijgulacenkov/CrowlerDump/vkId.txt", vk.getToken());
    std::vector<url> vec = vkId.generate();
    for (auto test :vec) {
        std::cout << test.toStr() << std::endl;
        std::vector<url> res2 = vk.getPhotoUrlsById(test);
        for (auto lol : res2) {
            std::cout << lol.toStr() << std::endl;
        }
        vkId.save();
    }


}