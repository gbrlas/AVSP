# include <iostream>
# include <algorithm>

using namespace std;

int main()
{
	char str[100], c;
	int i, j, tcase = 1, t, last;
	bool flag;

	scanf("%d", &t);

	while(t--)
	{
		scanf("%s", str);
		last = strlen(str)-1;
		flag = false;

		for(i = last; i >= 0 && !flag; i--)
			for(j = i; j <= last; j++)
				if(str[j] > str[i])
				{
					flag = true;
					break;
				}

		i++;

		if(flag)
		{
			sort(str+i+1, str+last+1);

			for(j = i; str[j] <= str[i]; j++);

			char tmp = str[i];
			str[i] = str[j];
			str[j] = tmp;

			sort(str+i+1, str+last+1);
		}

		else
		{
			str[last+2] = '\0';
			sort(str, str+last+1);

			if(str[0] == '0')
			{
				for(i = 0; str[i] == '0'; i++);
				str[0] = str[i];
				str[i] = '0';
			}

			for(i = last; i; i--)
				str[i+1] = str[i];

			str[1] = '0';
			sort(str+1, str+last+2);
		}

		printf("Case #%d: %s\n", tcase++, str);
	}

	return 0;
}