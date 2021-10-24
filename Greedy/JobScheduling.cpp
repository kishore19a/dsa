#include <iostream>
#include <vector>
#include <algorithm>

int scheduleForMaximumProfit(std::vector<std::pair<int, int>>& jobs)
{
    std::sort(jobs.begin(), jobs.end(), 
            [&](const std::pair<int, int>& a, const std::pair<int, int>& b){
                if(a.first < b.first)
                    return true;
                else if(a.first == b.first)
                {
                    if(a.second > b.second)
                        return true;
                    else
                        return false;
                }
                else 
                    return false;
            });

    int time{0}, res{0};
    for(int i = 0; i < jobs.size(); i++)
    {
        if(jobs[i].first > time)
        {
            res += jobs[i].second;
            time++;
        }
    }

    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<std::pair<int, int>> jobsWithDeadlineAndProfit{{3, 20}, {2, 60}, {3, 30}, {2, 50}};
    for(auto& job : jobsWithDeadlineAndProfit)
        std::cout << "(" << job.first << ", " << job.second << ")" << std::endl;

    std::cout << "--------------------------------" << std::endl;

    int res = scheduleForMaximumProfit(jobsWithDeadlineAndProfit);
    for(auto& job : jobsWithDeadlineAndProfit)
        std::cout << "(" << job.first << ", " << job.second << ")" << std::endl;

    std::cout << "Maximum profit = " << res << std::endl;

    return 0;
}
