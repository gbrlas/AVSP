#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;

template <typename T>
T CastLine(std::istream &str)
{
    // Read the line in
    string dummy;
    getline(str, dummy);

    // Cast to our desired type
    T            ret;
    stringstream ss(dummy);
    ss >> ret;

    // Return it
    return ret;
}

struct Trip
{
    bool from_a;
    int  start;
    int  end;

    Trip(bool a, string s)
    {
        replace(s.begin(), s.end(), ':', ' ');
        stringstream ss(s);

        int hs, ms, he, me;
        ss >> hs >> ms >> he >> me;

        from_a = a;
        start  = hs * 60 + ms;
        end    = he * 60 + me;
    }

    bool operator<(const Trip &other) const
    {
        return start < other.start;
    }
};

struct Train
{
    bool origin_a;
    bool at_a;
    int  available;

    Train(bool a)
    {
        origin_a = a;
    }
};

int main()
{
    int num = CastLine<int>(cin);
    for(int i = 0; i < num; ++i)
    {
        int t = CastLine<int>(cin);

        string dummy;
        getline(cin, dummy);
        stringstream ss(dummy);

        int na, nb;
        ss >> na >> nb;

        vector<Trip> trips;
        for(int j = 0; j < na; ++j)
        {
            getline(cin, dummy);
            trips.push_back(Trip(true, dummy));
        }
        for(int j = 0; j < nb; ++j)
        {
            getline(cin, dummy);
            trips.push_back(Trip(false, dummy));
        }
        sort(trips.begin(), trips.end());

        vector<Train> trains;
        for(size_t j = 0; j < trips.size(); ++j)
        {
            // Look for a train that can service this
            size_t found = 0;
            for(; found < trains.size(); ++found)
            {
                if((trains[found].at_a == trips[j].from_a) && (trains[found].available <= trips[j].start))
                    break;
            }

            // Reuse, else create
            if(found == trains.size())
                trains.push_back(Train(trips[j].from_a));

            trains[found].at_a      = !trips[j].from_a;
            trains[found].available = trips[j].end + t;
        }

        int start_at_a = 0;
        int start_at_b = 0;
        for(size_t j = 0; j < trains.size(); ++j)
        {
            if(trains[j].origin_a)
                ++start_at_a;
            else
                ++start_at_b;
        }

        cout << "Case #" << (i + 1) << ": " << start_at_a << " " << start_at_b << endl;
    }

    return 0;
}
