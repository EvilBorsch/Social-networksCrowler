#include "../AbstractClasses/Abstract_id_list_generator_strategy.h"
#include "../url/url.h"

class VkIdListGeneratorStrategy : public AbstractIdListGeneratorStrategy {
private:
    int size;
    std::string path;
    std::string token;
    size_t currentId = 0;

public:
    VkIdListGeneratorStrategy(int m_size, const std::string &m_path, const std::string &m_token) {
        size = m_size;
        path = m_path;
        token = m_token;
        currentId = getCurrentId();

    }

    std::vector<url> generate() override;


    size_t getCurrentId();

    void save();


};
