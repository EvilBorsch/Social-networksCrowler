#include "AbstractAPI.h"
#include "Abstract_id_list_generator_strategy.h"

class Container {

};


class Crowler {
    bool state = true;
    AbstractAPI *api;
    Abstract_id_list_generator_strategy *lg;
    vector<string> id_list;
    Container get_container_from_urls(const vector<string> &urls);

    int *fd;

public:
    void start_crowl();

    void stop_crowl_and_save_id_list();

    Crowler(AbstractAPI *m_api, Abstract_id_list_generator_strategy *m_lg, int *fd);

    void set_api_and_id_generator_strategy(AbstractAPI *m_api, Abstract_id_list_generator_strategy *m_lg);

};