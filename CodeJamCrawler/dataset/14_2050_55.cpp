#include <algorithm>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    ifstream reader("input.txt");
	ofstream writer("output.txt");
	int T, N, OptNaomi, DectNaomi;
    double temp;
    reader >> T;
    for(int i = 0; i < T; i++) {
        vector<double> naomi, naomi1;
        vector<double> ken, ken1;
        vector<double>::iterator naomiIt;
        vector<double>::iterator kenIt;
        reader >> N;
        OptNaomi = DectNaomi = 0;
        for(int j = 0; j < N; j++) {
            reader >> temp;
            naomi.push_back(temp);
            naomi1.push_back(temp);
        }
        for(int j = 0; j < N; j++) {
            reader >> temp;
            ken.push_back(temp);
            ken1.push_back(temp);
        }
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());
        sort(naomi1.begin(), naomi1.end());
        sort(ken1.begin(), ken1.end());
        for(int j = 0; j < N; j++) {
            naomiIt = naomi.end() - 1;
            kenIt = ken.end() - 1;
            if(*naomiIt > *kenIt) {
                OptNaomi++;
                naomi.erase(naomi.end() - 1);
                ken.erase(ken.begin());
            }
            else {
                naomi.erase(naomi.end() - 1);
                ken.erase(ken.end() - 1);
            }
        }
        for(int j = 0; j < N; j++) {
            naomiIt = naomi1.begin();
            kenIt = ken1.begin();
            if(*naomiIt > *kenIt) {
                DectNaomi++;
                naomi1.erase(naomi1.begin());
                ken1.erase(ken1.begin());
            }
            else {
                naomi1.erase(naomi1.begin());
                ken1.erase(ken1.end() - 1);
            }
        }
    writer << "Case #" << i + 1 << ": " << DectNaomi << " " << OptNaomi << endl;
    }
    return 0;
}
















