#include "..\..\my_header.h"


class solver
{
public:

  bool is_similar(string &real_word, string &word, bool_v &guessed)
  {
    int len = real_word.length();
    for (int i=0 ; i < len ; i++)
      if (guessed[i] && real_word[i] != word[i])
        return false;
    return true;  
  }
  
  bool has_char(string &word, char ch)
  {
    for (int i=0 ; i < int(word.size()) ; i++)
      if (word[i] == ch)
        return true;
    return false;  
  }
  
  bool is_all_true(bool_v &bv)
  {
    for (int i=0 ; i < int(bv.size()) ; i++)
      if (!bv[i])
        return false;
    return true;  
  }
  
  bool is_consistent(string &real_word, string &word, string &list, int count)
  {
    for (int i=0 ; i < count ; i++)
    {
      char letter = list[i];
      if (has_char(real_word, letter))
      {
        for (int j=0 ; j < int(real_word.size()) ; j++)
          if ((real_word[j] == letter) != (word[j] == letter))
            return false;      
      }
      else
      {
        if (has_char(word, letter))
          return false;
      }
    }
    
    return true;
  }
  
  
  int lost_points(int word_idx, str_v &words, string &list)
  {
    int N = words.size();
    
    string &word = words[word_idx];
    int len = word.length();
    
    int_v remaining;
    for (int i=0 ; i < N ; i++)
      if (words[i].size() == len)
        remaining.push_back(i);
    if (remaining.size() == 1)
      return 0;
    
    assert(list.size() == 26);
    
    int score = 0;
    bool_v guessed(len);
    
    for (int i_l=0 ; i_l < 26 ; i_l++)
    {
      char letter = list[i_l];
      
      bool found = false;
      for (int i_w=0 ; i_w < int(remaining.size()) ; i_w++)
      {
        string &curr_word = words[remaining[i_w]];
        if (has_char(curr_word, letter))
        {
          found = true;
          break;
        }
      }
      
      if (!found)
        continue;
      
      bool guess_ok = false;
      for (int i=0 ; i < len ; i++)
        if (word[i] == letter)
        {
          assert(!guessed[i]);
          guess_ok = true;
          guessed[i] = true;
        }


      int_v new_rem;
      for (int i=0 ; i < int(remaining.size()) ; i++)
      {
        string &w = words[remaining[i]];
        if (is_consistent(word, w, list, i_l+1))
          new_rem.push_back(remaining[i]);
      }
      assert(new_rem.size() > 0);

      //if (new_rem.size() == 1)
      //  return score;

      remaining = new_rem;
            
      if (!guess_ok)
      {
        score++;
        continue;
      }
      else
      {
        if (is_all_true(guessed))
          return score;
      }
    }
    
    return score;
    //assert(false);
    //throw;
    //return -1;
  }

	string solve(str_v &words, str_v &lists)
	{
	  int N = words.size();
	  int M = lists.size();
	  
	  string output;
	  
	  for (int i_l=0 ; i_l < M ; i_l++)
	  {
	    int best_idx = -1;
	    int best_score = -1;
	    for (int i_w=0 ; i_w < N ; i_w++)
	    {
	      int score = lost_points(i_w, words, lists[i_l]);
	      if (best_idx == -1 || score > best_score)
	      {
	        best_idx = i_w;
	        best_score = score;
	      }
	    }
	    
	    assert(best_idx >= 0 && best_score >= 0);
	    
	    output += (i_l == 0 ? "" : " ") + words[best_idx];
	  }
	  
	  return output;
	}
};

/*************************************************************************************/

void process_test_case(int case_num, ifstream &ifs, ofstream &ofs)
{
  int N, M;
  ifs >> N >> M;
  
  str_v words, lists;
  
  for (int i=0 ; i < N ; i++)
  {
    string s;
    ifs >> s;
    words.push_back(s);
  }
  
  for (int i=0 ; i < M ; i++)
  {
    string s;
    ifs >> s;
    lists.push_back(s);
  }
  
	string res = solver().solve(words, lists);

	cout << "Case #" << case_num << ": " << res << endl;
	ofs << "Case #" << case_num << ": " << res << endl;
}

/*************************************************************************************/

void main(int argc, char **argv)
{
	ifstream ifs(argv[1], ifstream::in);
	ofstream ofs(argv[2]);

	ofs.precision(7);
	ofs << fixed;

	int n = to_int(get_line(ifs));

	assert(n > 0 && n < 200);

	for (int i=0 ; i < n ; i++)
	{
		if (i > 0)
			cout << "\n---------------------------------------------\n\n";
		process_test_case(i+1, ifs, ofs);
	}
}
