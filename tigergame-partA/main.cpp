#include "WeightedRecommendationSystem.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./program <inputfile>" << endl;
        return 1;
    }

    WeightedRecommendationSystem wrs;
    wrs.loadData(argv[1]);
    wrs.outputRecommendations(cout);

    return 0;
}
