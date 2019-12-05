#include "NetService/NetService.h"
#include "API/VkAPI.h"
#include "Id_list_generator_strategy/Vk_id_list_generator_strategy.h"
#include "Crowler/Crowler.h"


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
    //sleep(2);
    //cr.stopCrowl();


    url m_url("id184059480", "vk");

    url temp1("https://sun9-52.userapi.com/c840232/v840232112/8561d/Y-q_hZJtpDk.jpg");
    url temp2("https://sun9-35.userapi.com/c847122/v847122689/2137f/pdHUHTavt1U.jpg");
    url temp3("https://sun9-60.userapi.com/c850224/v850224350/186544/v6ooSacR0r0.jpg");
    url temp4("https://sun9-14.userapi.com/c844321/v844321164/1e3f38/sjVui97PcoU.jpg");
    std::vector<url> vk_get_photo_ans = {temp1, temp2, temp3, temp4};

    std::vector<url> vec = vk->getPhotoUrlsById(m_url);



}