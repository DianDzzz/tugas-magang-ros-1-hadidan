#include "ros/ros.h"
#include "bedwars_data/registrasi.h"

int main(int argc, char **argv) {
    ros::init(argc, argv, "team_publisher");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<bedwars_data::registrasi>("team_registration", 1000);
    ros::Rate loop_rate(1);  

    bedwars_data::registrasi team_data;
    team_data.teamName = "Warriors Keputih";
    team_data.gameMode = "Squad";
    team_data.playernames = {"Marvel", "Xayon", "Peylang", "David"};
    team_data.playerLevels = {10, 20, 15, 18};
    team_data.playerRanks = {"Gold", "Gold", "Bronze", "Silver"};

    while (ros::ok()) {
        ROS_INFO("Publishing team data: %s", team_data.teamName.c_str());
        pub.publish(team_data);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}