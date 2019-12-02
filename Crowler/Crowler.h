#include "../AbstractClasses/AbstractAPI.h"
#include "../AbstractClasses/Abstract_id_list_generator_strategy.h"
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

class Container {

};


class Crowler {
    const int stopState = 2;
    AbstractIdListGeneratorStrategy *lg;
    boost::thread *t;

    Container getContainerFromUrls(const std::vector<url> &urls);


    AbstractAPI *api;
public:
    void startCrowl();

    void crowl();

    void stopCrowl();

    Crowler(AbstractAPI *m_api, AbstractIdListGeneratorStrategy *m_lg);

    void wait(int seconds) {
        boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
    }


};