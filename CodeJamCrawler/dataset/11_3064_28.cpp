#include <fstream>
using std :: ifstream;
using std :: ofstream;

const int MAX_ALL_SOUND = 10110;

bool is_real (int s, int all, int sound[])
{
	for (int i = 0; i < all; ++i)
		if (sound[i] % s != 0 &&
			s % sound[i] != 0)
			return false;
	return true;
}


int find_min_sound (int low, int hight, int all, int sound[])
{
	int ans = low;
	while (ans <= hight)
	{
		if (is_real (ans, all, sound))
			return ans;
		++ans;
	}

	return -1;
}

int main ()
{
	ifstream input ("input.txt");
	ofstream output ("output.txt");
	
	int all_query = 0;
	input >> all_query;
	for (int query = 0; query < all_query; ++query)
	{
		int all_sound = 0;
		input >> all_sound;
		int low = 0, hight = 0;
		input >> low >> hight;
		int sounds[MAX_ALL_SOUND] = {};
		for (int i = 0; i < all_sound; ++i)
			input >> sounds[i];

		output << "Case #" << query + 1 << ": ";
		int min = find_min_sound (low, hight, all_sound, sounds);
		if (min == -1)
			output << "NO\n";
		else
			output << min << '\n';
	}

	return 0;
}