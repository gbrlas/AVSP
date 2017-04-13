#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::vector<std::string> StringVector;

template<class T>
StringVector::iterator GetHighestDistance(StringVector input, T targetBegin, T targetEnd)
{
  T highestDistanceIterator = targetBegin;

  for (unsigned int i = 0; i < input.size(); i++)
  {
    T currentIterator = std::find(targetBegin, targetEnd, input[i]);

    if (currentIterator > highestDistanceIterator)
    {
      highestDistanceIterator = currentIterator;
      continue;
    }
  }
  targetBegin = highestDistanceIterator;

  return targetBegin;
}

void main()
{
  std::ifstream file("codejam.in",    std::ios_base::in);
  std::ofstream result("codejam.out", std::ios_base::out);

  int casesCount;
  file >> casesCount;
  file.ignore();

  for (int caseIndex = 0; caseIndex < casesCount; caseIndex++)
  {
    StringVector queries;
    StringVector engines;

    int searchEnginesCount;
    file >> searchEnginesCount;
    file.ignore();

    for (int searchEngineIndex = 0; searchEngineIndex < searchEnginesCount; searchEngineIndex++)
    {
      std::string searchEngine;
      std::getline(file, searchEngine, '\n');

      engines.push_back(searchEngine);
    }

    int queriesCount;
    file >> queriesCount;
    file.ignore();

    for (int queryIndex = 0; queryIndex < queriesCount; queryIndex++)
    {
      std::string query;
      std::getline(file, query, '\n');

      queries.push_back(query);
    }

    StringVector::iterator highestDistanceIterator = queries.begin();
    int switchesNeeded = 0;
    
    while (true)
    {
      highestDistanceIterator = GetHighestDistance(engines, highestDistanceIterator, queries.end());
      
      if (highestDistanceIterator != queries.end())
      {
        switchesNeeded++;
      }
      else
      {
        break;
      }
    }

    result << "Case #" << caseIndex + 1 << ": " << switchesNeeded << '\n';
  }
}