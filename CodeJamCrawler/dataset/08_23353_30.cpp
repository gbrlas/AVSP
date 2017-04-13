#include <iostream>

#include <boost/functional/hash.hpp>

typedef unsigned int u32;
typedef int s32;
typedef unsigned short u16;
typedef short s16;
typedef char s8;
typedef unsigned char u8;

using namespace std;

std::size_t search_names[120];
u32 numSearchEngines;
u16 bestStart[120];
u16 currentBest;
char lineBuffer[200];

boost::hash<std::string> string_hash;

u16 findEngine(u32 hash)
{
    for (u16 engine = 0; engine < numSearchEngines; ++ engine)
    {
        if (search_names[engine] == hash)
            return engine;
    }
    return 150;
}

u16 findBest(u16 excluding)
{
    u16 currentBest = 0;
    u16 currentScore = 10000;

    for (u16 engine = 0; engine < numSearchEngines; ++ engine)
    {
        const u16 thisScore = bestStart[engine];
        if (engine != excluding && 
            thisScore < currentScore)
        {
            currentScore = thisScore;
            currentBest = engine;
        }
    }
    return currentScore;
}

    
int main()
{
    boost::hash<std::string> string_hash;

    u32 numProblems = 0;

    cin >> numProblems;

    for (u32 probNum = 0; probNum < numProblems; ++ probNum)
    {
        cout << "Case #" << probNum + 1<<": ";
        numSearchEngines = 0;
        cin >> numSearchEngines;
        cin.getline(lineBuffer, 199);
        for (u32 engine = 0; engine < numSearchEngines; ++ engine)
        {
            cin.getline(lineBuffer, 199);
            search_names[engine] = string_hash(lineBuffer);
            bestStart[engine] = 0;
//            cout << "added : "<< lineBuffer <<"(" << search_names[engine]<<")" << endl;
        }
        
        u32 numQueries = 0;
        cin >> numQueries;
        cin.getline(lineBuffer, 199);

        for (u32 query = 0; query < numQueries; ++ query)
        {
            cin.getline(lineBuffer, 199);
//            cout << "query : "<< lineBuffer <<"(" << string_hash(lineBuffer)<<")" << endl;
            u16 engineNum = findEngine(string_hash(lineBuffer));
            if (engineNum >= numSearchEngines)
            {
                cout << "=========== Engine ("<<lineBuffer<<") not found! " << endl;
                engineNum = 0;
            } 


            bestStart[engineNum] = findBest(engineNum) + 1;
//            cout <<"(" << engineNum <<", " << bestStart[engineNum] << "), ";
        }
        cout << findBest(150) << endl;
    }
}
