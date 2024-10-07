#include<iostream>
#include<chrono>

using namespace std;
using namespace chrono;
typedef high_resolution_clock hc;

int main() {
    time_point<hc> start = hc::now();

    //code here

    time_point<hc> end = hc::now();

    cout << "process time: " << duration_cast<microseconds>(end - start).count() / 1000.0 << "ms\n";
    return 0;
}

