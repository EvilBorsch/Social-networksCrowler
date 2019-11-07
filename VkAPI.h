#include "AbstractAPI.h"
#include "Curl.h"

class VkAPI: public AbstractAPI{
private:
    Curl curler;
    string token;
public:
    vector<string> get_photo_urls_by_id(const string& url) override ;
    void login() override;
    explicit VkAPI(const string& app_key);

};