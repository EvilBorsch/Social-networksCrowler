#include "../API/VkAPI.h"
#include "../API/OkAPI.h"
#include "../API/FacebookAPI.h"
#include "../Id_list_generator_strategy/Vk_id_list_generator_strategy.h"
#include "../Id_list_generator_strategy/Ok_id_list_generator_strategy.h"
#include "../Id_list_generator_strategy/Facebook_id_list_generator_strategy.h"
#include "../Crowler/Crowler.h"
#include "../Id_list_generator_strategy/Ok_id_list_generator_strategy_friends_method.h"
#include <iostream>
#include "../url/url.h"


#include "gtest/gtest.h"
#include <fstream>


using std::vector, std::string;

class TestAPI : public ::testing::Test {
protected:

    void SetUp() override {
        vk = new VkAPI("7175443");
        vk->login();
        ok = new OkAPI("512000155176");
        facebook = new FacebookAPI("424256728258093");
    }

    void TearDown() override {
        delete vk;
        delete ok;
        delete facebook;
    }

    VkAPI *vk{};
    OkAPI *ok{};
    FacebookAPI *facebook{};


};


TEST_F(TestAPI, testvk) {
    url m_url;
    m_url.getVkPhotosRequestUrl(vk->getToken(), "184059480");

    url temp1("https://sun9-52.userapi.com/c840232/v840232112/8561d/Y-q_hZJtpDk.jpg");
    url temp2("https://sun9-35.userapi.com/c847122/v847122689/2137f/pdHUHTavt1U.jpg");
    url temp3("https://sun9-60.userapi.com/c850224/v850224350/186544/v6ooSacR0r0.jpg");
    url temp4("https://sun9-14.userapi.com/c844321/v844321164/1e3f38/sjVui97PcoU.jpg");
    vector<url> vk_get_photo_ans = {temp1, temp2, temp3, temp4};

    std::vector<url> vec=vk->getPhotoUrlsById(m_url);

    EXPECT_EQ(vk->getPhotoUrlsById(m_url), vk_get_photo_ans);

    url temp5("/sergeiptrnk", "vk");
    url temp6("/id358547266", "vk");
    url temp7("/nukenova2016", "vk");
    url temp8("/id399688365", "vk");
    url temp9("/id418671513", "vk");

    vector<url> vk_get_friends_ans = {temp5};
    vector<url> vk_get_group_ans = {temp6, temp7, temp8, temp9};

    url photoId("id184059480");
    url friendsId("id289472284");
    url groupId("club143457610");


    EXPECT_EQ(vk->getFriendsUrlsById(friendsId), vk_get_friends_ans);
    EXPECT_EQ(vk->getGroupParticipants(groupId), vk_get_group_ans);

    url photoId2("id289472284");
    url friendsId2("id12313");
    url groupId2("a_4_autism");


    EXPECT_EQ(vk->getFriendsUrlsById(friendsId2), vector<url>());
    EXPECT_EQ(vk->getGroupParticipants(groupId2), vector<url>());
    EXPECT_EQ(vk->getPhotoUrlsById(photoId2), vector<url>());


    url photoId3("id1askdhjaskljh2313");
    url friendsId3("a_asdjkhaskjdh4_autism");
    url groupId3("id2894asjdhgaskjdh72284");


    EXPECT_EQ(vk->getFriendsUrlsById(friendsId3), vector<url>());
    EXPECT_EQ(vk->getGroupParticipants(groupId3), vector<url>());
    EXPECT_EQ(vk->getPhotoUrlsById(photoId3), vector<url>());

}


TEST_F(TestAPI, testok) {
    url temp1("575941399764/pphotos/879711732436");
    url temp2("593221215274/pphotos/889758673450");
    url temp3("593221211482");
    url temp4("593221215274");

    vector<url> ok_get_photo_ans = {temp1, temp2};
    vector<url> ok_get_friends_ans = {temp3};
    vector<url> ok_get_group_ans = {temp4};


    url photoId("593221215274");
    url friendsId("593221215274");
    url groupId("61557801746474");


    EXPECT_EQ(ok->getPhotoUrlsById(photoId), ok_get_photo_ans);
    EXPECT_EQ(ok->getFriendsUrlsById(friendsId), ok_get_friends_ans);
    EXPECT_EQ(ok->getGroupParticipants(groupId), ok_get_group_ans);

    url photoId2("593221215274");
    url friendsId2("593221215274");
    url groupId2("61557801746474");


    EXPECT_EQ(ok->getFriendsUrlsById(friendsId2), vector<url>());
    EXPECT_EQ(ok->getGroupParticipants(groupId2), vector<url>());
    EXPECT_EQ(ok->getPhotoUrlsById(photoId2), vector<url>());


}

TEST_F(TestAPI, test_facebook) {
    url temp1("113498916761448&set=a.113453566765983&type=3&theater");
    url temp2("113453540099319&set=a.113453566765983&type=3&theater");
    vector<url> facebook_get_photo_ans = {temp1, temp2};


    url photoId("100043040207420");
    url friendsId("100043040207420");
    url groupId("2558160454233543");

    url temp3("100026228050639");
    url temp4("100026228050639");

    vector<url> facebook_get_friends_ans = {temp3};
    vector<url> facebook_get_group_ans = {temp4};


    EXPECT_EQ(facebook->getPhotoUrlsById(photoId),
              facebook_get_photo_ans);
    EXPECT_EQ(facebook->getFriendsUrlsById(friendsId),
              facebook_get_friends_ans);
    EXPECT_EQ(facebook->getGroupParticipants(groupId),
              facebook_get_group_ans);


    url photoId2("100043040207420ahsjdhja");
    url friendsId2("551899082309567");
    url groupId2("55189908230956asdjhasjdhj7");

    EXPECT_EQ(facebook->getFriendsUrlsById(friendsId2),
              vector<url>());
    EXPECT_EQ(facebook->getGroupParticipants(groupId2), vector<url>());

    EXPECT_EQ(facebook->getPhotoUrlsById(photoId2), vector<url>());

}


class TestListGenerator : public ::testing::Test {
protected:

    void SetUp() override {

        vk_lg = new VkIdListGeneratorStrategy(5, pathvk,
                                              "af2d806eaf2d806eaf2d806e66af40fd7daaf2daf2d806ef28431079864b75a45b322d9");
        ok_lg = new OkIdListGeneratorStrategy(5, pathok);
        facebook_lg = new FacebookIdListGeneratorStrategy(5, pathfacebook);
        ok_lg_friends = new OkIdListGeneratorStrategyFriends(3, pathokfriends);
    }

    void TearDown() override {
        delete vk_lg;
        delete ok_lg;
        delete facebook_lg;
    }

    string pathvk = "/Users/dmitrijgulacenkov/CrowlerDump/CrowlerTest/vkId.txt";

    string pathok = "../../test_ok.txt";

    string pathfacebook = "../../test_facebook.txt";


    string pathokfriends = "../../test_ok_friends.txt";
    VkIdListGeneratorStrategy *vk_lg;
    OkIdListGeneratorStrategy *ok_lg;
    FacebookIdListGeneratorStrategy *facebook_lg;
    OkIdListGeneratorStrategyFriends *ok_lg_friends;
};


TEST_F(TestListGenerator, test_vk_lg) {



    std::vector<url> vec = vk_lg->generate();

    std::vector<url> res={url("id=1235","vk"),
                          url("id=1236","vk"),
                          url("id=1237","vk"),
                          url("id=1238","vk"),
                          url("id=1239","vk")};

    EXPECT_EQ(vec,res);



}

TEST_F(TestListGenerator, test_ok_lg) {
    vector<url> vec = {url("593221211482"), url("593221211483"), url("593221211484"), url("593221211485"),
                       url("593221211486")};

    std::ofstream fout(pathok, std::ios_base::out);

    for (auto &el:vec) {
        fout << el.toStr();
    }
    fout.close();

    vector<url> data = ok_lg->loadUrls(pathok);
    EXPECT_EQ(data, vec);

    vector<url> generate_data = {url("593221211487"), url("593221211482"), url("493221211482"), url("593221211490"),
                                 url("123221211482")};

    EXPECT_EQ(ok_lg->generate(), generate_data);
}

TEST_F(TestListGenerator, test_facebook_lg) {
    vector<url> vec = {url("100026228050631"), url("100026228050632"), url("100026228050633"), url("100026228050634"),
                       url("100026228050635")};

    std::ofstream fout(pathfacebook, std::ios_base::out);

    for (auto &el:vec) {
        fout << el.toStr();
    }
    fout.close();

    vector<url> data = facebook_lg->loadUrls(pathfacebook);
    EXPECT_EQ(data, vec);

    vector<url> generate_data = {url("100026228050636"), url("100026228050637"), url("100026228050638"),
                                 url("100026228050639"), url("100026228050640")};

    EXPECT_EQ(facebook_lg->generate(), generate_data);
}


TEST_F(TestListGenerator, test_ok_friends_lg) {
    vector<url> generate_data = {url("467533400550"), url("358288531616"), url("571622183720")};

    EXPECT_EQ(ok_lg_friends->generate(), generate_data);
}


TEST(CurlTests, Curltest) {
    NetService curler;
    response m_response = curler.request(
            url("https://api.vk.com/method/users.get?user_ids=210700286&fields=bdate&access_token=533bacf01e11f55b536a565b57531ac114461ae8736d6506a3&v=5.103"));

    string right_answer = R"({"error":{"error_code":5,"error_msg":"User authorization failed: invalid access_token (4).","request_params":[{"key":"user_ids","value":"210700286"},{"key":"fields","value":"bdate"},{"key":"v","value":"5.103"},{"key":"method","value":"users.get"},{"key":"oauth","value":"1"}]}})";

    ASSERT_EQ(right_answer, m_response.get_body());

    ASSERT_EQ("", curler.request(url("asd")).get_body());

}
