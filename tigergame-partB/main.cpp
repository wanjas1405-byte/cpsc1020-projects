#include "RecommendationSystem.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./program <inputfile>" << endl;
        return 1;
    }

    RecommendationSystem rs;
    rs.loadData(argv[1]);
    rs.outputRecommendations(cout);

    return 0;
}
