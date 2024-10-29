#include "header.h"

void teamCallback(const bedwars_data::registrasi::ConstPtr& data) {
    ROS_INFO("Received team registration data:");
    ROS_INFO("Team Name: %s", data->teamName.c_str());
    ROS_INFO("Game Mode: %s", data->gameMode.c_str());
    for (size_t i = 0; i < data->playernames.size(); ++i) {
        ROS_INFO("Player %zu: %s, Level: %d, Rank: %s",
                 i + 1,
                 data->playernames[i].c_str(),
                 data->playerLevels[i],
                 data->playerRanks[i].c_str());
    }
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "team_subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("team_registration", 1000, teamCallback);
    ros::spin();
    return 0;
}