#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Runner {
public:
    string name;
    int speed;
    int run_time;
    int rest_time;

    Runner(string n, int s, int rt, int rtst) {
        name = n;
        speed = s;
        run_time = rt;
        rest_time = rtst;
    }

    int distance_after(int seconds) {
        int cycle_time = run_time + rest_time;
        int full_cycles = seconds / cycle_time;
        int remaining_time = seconds % cycle_time;
        int distance = full_cycles * run_time * speed;
        if (remaining_time > run_time) {
            distance += run_time * speed;
        }
        else {
            distance += remaining_time * speed;
        }
        return distance;
    }
};

int main() {
    vector<Runner> runners = {
        Runner("John", 10, 6, 20),
        Runner("James", 8, 8, 25),
        Runner("Jenna", 12, 5, 16),
        Runner("Josh", 7, 7, 23),
        Runner("Jacob", 9, 4, 32),
        Runner("Jerry", 5, 9, 18),
    };

    vector<int> distances;
    for (auto &runner : runners) {
        distances.push_back(runner.distance_after(1234));
    }

    int winner_distance = *max_element(distances.begin(), distances.end());
    int winner_index = distance(distances.begin(), max_element(distances.begin(), distances.end()));
    string winner_name = runners[winner_index].name;

    cout << "The winner of the race is " << winner_name << " with a distance of " << winner_distance << " meters." << endl;

    return 0;
}
