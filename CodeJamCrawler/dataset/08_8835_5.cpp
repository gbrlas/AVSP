#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::vector<int> IntVector;

struct Key
{
  IntVector letterIndexes;
};

void main()
{
  std::ifstream file("codejam.in",    std::ios_base::in);
  std::ofstream result("codejam.out", std::ios_base::out);

  int casesCount;
  file >> casesCount;
  file.ignore();

  for (int caseIndex = 0; caseIndex < casesCount; caseIndex++)
  {
    int lettersPerKey;
    file >> lettersPerKey;
    file.ignore();

    int keysAvaiable;
    file >> keysAvaiable;
    file.ignore();

    int totalLetters;
    file >> totalLetters;
    file.ignore();

    IntVector letterFrequencies;
    std::vector<Key> keyPad;

    keyPad.resize(keysAvaiable);

    for (int i = 0; i < totalLetters; i++)
    {
      int frequency;
      file >> frequency;
      file.ignore();

      letterFrequencies.push_back(frequency);
    }

    IntVector letterFrequenciesOld = letterFrequencies;
    int clicks = 0;

    for (int i = 0, j = 0; i < totalLetters; i++)
    {
      IntVector::iterator maxFrequency = std::max_element(letterFrequenciesOld.begin(), letterFrequenciesOld.end());

      if  (maxFrequency == letterFrequenciesOld.end()) break;
      if (*maxFrequency == -1) break;

      int keyIndex = maxFrequency - letterFrequenciesOld.begin();
      keyPad[j].letterIndexes.push_back(keyIndex);
      clicks += *maxFrequency * keyPad[j].letterIndexes.size();

      *maxFrequency = -1;

      if (j == keysAvaiable-1) j = 0;
      else j++;
    }

    result << "Case #" << caseIndex + 1 << ": " << clicks << '\n';
  }
}