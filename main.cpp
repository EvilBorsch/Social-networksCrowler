#include "NetService/NetService.h"
#include "API/VkAPI.h"
#include "Id_list_generator_strategy/Vk_id_list_generator_strategy.h"
#include "Crowler/Crowler.h"
#include "Api/FacebookAPI.h"

int main(int argc, char *argv[]) {







    /*
    url m_url;
    m_url.vkStyle(
            "/method/photos.get?owner_id=184059480&album_id=profile&access_token=af2d806eaf2d806eaf2d806e66af40fd7daaf2daf2d806ef28431079864b75a45b322d9&v=5.103");

    std::vector<url> res=vk.getPhotoUrlsById(m_url);

    for (auto lol : res){
        std::cout<< lol.toStr() << std::endl;
    }
     */




    std::shared_ptr<VkAPI> vk = std::make_shared<VkAPI>("asd");
    vk->login();

    std::shared_ptr<VkIdListGeneratorStrategy> vkId = std::make_shared<VkIdListGeneratorStrategy>(6,
                                                                                                  "/Users/dmitrijgulacenkov/CrowlerDump/vkId.txt"
                                                                                                  );

    /*
    std::vector<url> vec = vkId.generate();
    for (auto test :vec) {
        std::cout << test.toStr() << std::endl;
        std::vector<url> res2 = vk.getPhotoUrlsById(test);
        for (auto lol : res2) {
            std::cout << lol.toStr() << std::endl;
        }
        vkId.save();
    }
     */







    //Crowler cr(vk, vkId);
    //cr.startCrowl();
    //sleep(100);
    //cr.stopCrowl();



    std::shared_ptr<FacebookAPI> facebook = std::make_shared<FacebookAPI>("579642939271889",
                                                                          "54350e9fd703fa4510992914b7907d31");
    facebook->login();
    url mUrl("id=100043040207420", "facebook");
    std::vector<url> vec = facebook->getPhotoUrlsById(mUrl);
    std::cout << vec[0].toStr();


}