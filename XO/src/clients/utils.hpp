#include <vector>
#include <algorithm>

using namespace std;

struct PlayeScore
{
    short int wins;
    short int losses;
    short int ties;
};

vector<int> get_available_spots(const vector<int> &all_played_spots)
{
    vector<int> available_spots;
    for (int i = 1; i <= 9; i++)
    {
        if (find(all_played_spots.begin(), all_played_spots.end(), i) == all_played_spots.end())
        {
            available_spots.push_back(i);
        }
    }
    return available_spots;
}

vector<int> merge_vector(vector<int> vec1, vector<int> vec2)
{
    vector<int> played_spots(vec1.size() + vec2.size());

    copy(vec1.begin(), vec1.end(), played_spots.begin());
    copy(vec2.begin(), vec2.end(), played_spots.begin() + vec1.size());

    return played_spots;
}