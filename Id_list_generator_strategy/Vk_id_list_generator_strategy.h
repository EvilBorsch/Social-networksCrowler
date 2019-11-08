#include "../Abstract_id_list_generator_strategy.h"

class Vk_id_list_generator_strategy: public Abstract_id_list_generator_strategy{
private:
    int size;
    string path;
public:
    explicit Vk_id_list_generator_strategy(int m_size,const string& m_path) {
        size=m_size;
        path=m_path;
    }
    vector<string> generate() override ;
    vector<string> load_urls_from_disk() override;
    string get_path() override;
};
