#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;



// delay(5000); 


void GettingCurrentCoordinates(vector<pair <int, int>>& node, vector<double>& times)
{
    vector<double> sum_time(1);
    sum_time[0] = 0;
    for (int i = 0; i < times.size(); i++){
        sum_time.push_back(sum_time[i] + times[i]); // массив сумарного времени до каждой ноды
    }
    double current_time = 0;
    int i = 0;
    while (true){
        if (current_time >= sum_time[i]){
            //http запрос, отправляющий текущуюю координату в фронт (return node[i])
            cout << node[i].first<<" "<<node[i].second<< '\n';
            i += 1;
        }
        sleep(60);
        current_time += 60;
        if (i == sum_time.size())
            return void();
    }
}



int main()
{
    vector<pair <int, int>> a = {{1, 1}, {2, 2}, {5, 5}, {4, 4}, {3, 3}, {2, 2}, {7, 7}};
    vector<double> b = {118.2, 122, 131.22, 153, 142.2, 131.1};
    GettingCurrentCoordinates(a, b);

    return 0;
}
 