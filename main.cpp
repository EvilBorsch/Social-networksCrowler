#include "NetService/NetService.h"
#include "API/VkAPI.h"


int main(int argc, char *argv[]) {
    NetService curl;
    VkAPI vk("asd");
    url m_url;
    m_url.vkStyle(
            "/method/photos.get?owner_id=217760896&album_id=profile&access_token=af2d806eaf2d806eaf2d806e66af40fd7daaf2daf2d806ef28431079864b75a45b322d9&v=5.103");
    vk.getPhotoUrlsById(m_url);


}