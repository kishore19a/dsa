#include <iostream>
#include <vector>
#include <algorithm>

int activitySelection(std::vector<std::pair<int, int>>& activities)
{
    // Step 1 : Sort the activities vector in increasing order of finishing time
    std::sort(activities.begin(), activities.end(), 
                [&](const std::pair<int, int>& a, const std::pair<int, int>& b){
                        return (a.second < b.second);
                });

    int res{1};
    std::pair<int, int> selectedActivity = activities[0];

    // Greedy algorithm
    for(int i = 1; i < activities.size(); i++)
    {
        if(activities[i].first >= selectedActivity.second)
        {
            selectedActivity = activities[i];
            res++;
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<std::pair<int, int>> activities{{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    for(auto& activity : activities)
        std::cout << "(" << activity.first << ", " << activity.second << ")" << std::endl;

    std::cout << "--------------------------------" << std::endl;
    
    int res = activitySelection(activities);
    for(auto& activity : activities)
        std::cout << "(" << activity.first << ", " << activity.second << ")" << std::endl;

    std::cout << "Total number of activities that can be selected = " << res << std::endl;

    return 0;
}
