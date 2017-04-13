#include <stdio.h>
#include <stdlib.h>

#define FWD 1
#define BCK 2

class c_bot
{
public:
	int position;
	c_bot()
	{
		position=1;
	}
	void move(int v)
	{
		if(v==FWD)
			this->position++;
		else
			this->position--;
	}
}bot_B,bot_O;

struct s_button
{
	int number;
	s_button * next_button;
	int rating;
};
class c_button_order_row
{
public:
	int buttons_amount;
	int buttons_done;
	s_button * first_button;
	s_button * last_button;
	s_button * curr_button;
	bool done;
	c_button_order_row()
	{
		this->first_button=NULL;
		this->last_button=NULL;
		this->buttons_amount=0;
		this->buttons_done=0;
		this->done=false;
	}
	void add(int button,int rating)
	{
		s_button *curr = (s_button *)malloc(sizeof(s_button));
		curr->number=button;
		curr->rating=rating;
		if(this->last_button==NULL)
			this->last_button=curr;
		else
		{
			this->last_button->next_button=curr;
			this->last_button=curr;
		}
		if(this->first_button==NULL)
		{
			this->first_button=curr;
		}
		curr->next_button=NULL;
		this->buttons_amount++;
	}
	void clear()
	{
		s_button *curr=this->first_button;
		s_button *next;
		while(curr!=NULL)
		{
			next=curr->next_button;
			free(curr);
			curr=next;			
		}
		this->first_button=NULL;
		this->last_button=NULL;
	}
	void print()
	{
		s_button *curr=this->first_button;
		s_button *next;
		while(curr!=NULL)
		{
			next=curr->next_button;
			printf("%i ",curr->number);
			curr=next;			
		}
	}
};

void timer();

class c_state
{
public:
	int seconds;
	int episode;
	int episode_amount;
	int position_B;
	int position_O;
	c_button_order_row *buttons_order_B;
	c_button_order_row *buttons_order_O;
	c_state()
	{
		this->seconds=0;
		this->episode=0;
		this->episode_amount=0;
		this->position_B=0;
		this->position_O=0;
	}
	void fill(char *input)
	{
		char line[1000];
		int input_position,line_position;
		for(input_position=0,line_position=0;input_position==0 || input[input_position-1]!='\n';input_position++,line_position++)
		{
			line[line_position]=input[input_position];
		}
		episode_amount=atoi(line);

		buttons_order_B=new c_button_order_row[episode_amount];
		buttons_order_O=new c_button_order_row[episode_amount];

		int buttons_amount,number;
		bool orange;
		for(int episode_num=0;episode_num<episode_amount;episode_num++)
		{
			//new line with action orders from 0 pos.
			line_position=0;
			while(input[input_position]!=' ')
			{
				line[line_position]=input[input_position];
				input_position++;
				line_position++;
			}
			line[line_position]=0;
			buttons_amount=atoi(line);
			number=0;
			for(int i=0;i<buttons_amount;i++)
			{
				input_position++;
				if(input[input_position]=='O')
					orange=true;
				else
					orange=false;
				input_position+=2;
				line_position=0;
				while(input[input_position]!=' ' && input[input_position]!='\n' && input[input_position]!='\0')
				{
					line[line_position]=input[input_position];
					input_position++;
					line_position++;
				}
				line[line_position]=0;
				if(orange)
					buttons_order_O[episode_num].add(atoi(line),number);
				else
					buttons_order_B[episode_num].add(atoi(line),number);
				number++;
			}
			input_position++;/*
			printf("===\nep%i\n",episode_num);
			printf("O: ");buttons_order_O[episode_num].print();
			printf("\nB: ");buttons_order_B[episode_num].print();
			printf("\n\n");*/
			if(buttons_order_O[episode_num].first_button==NULL)
				buttons_order_O[episode_num].done=true;
			if(buttons_order_B[episode_num].first_button==NULL)
				buttons_order_B[episode_num].done=true;
		}//episode cyrcle
		for(int i=0;i<episode_amount;i++)
		{
			if(buttons_order_O[i].first_button!=NULL)
			{
				buttons_order_O[i].curr_button=buttons_order_O[i].first_button;
				buttons_order_O[i].done=false;
			}
			else
				buttons_order_O[i].done=true;
			if(buttons_order_B[i].first_button!=NULL)
			{
				buttons_order_B[i].curr_button=buttons_order_B[i].first_button;
				buttons_order_B[i].done=false;
			}
			else
				buttons_order_B[i].done=true;
		}
		timer();
	}
	bool SendOrder()
	{
		bool Bpress=false;
		if(buttons_order_B[episode].done && buttons_order_O[episode].done)
		{
			printf("Case #%i: %i\n",episode+1,seconds);
			seconds=0;
			return false;
		}
		 if(!buttons_order_B[episode].done)
		if(bot_B.position<buttons_order_B[episode].curr_button->number)
			bot_B.move(FWD);
		else if(bot_B.position>buttons_order_B[episode].curr_button->number)
			bot_B.move(BCK);
		else if(buttons_order_O[episode].done || buttons_order_B[episode].curr_button->rating < buttons_order_O[episode].curr_button->rating)
		{
			if(buttons_order_B[episode].curr_button->next_button!=NULL)
			{
				buttons_order_B[episode].curr_button=buttons_order_B[episode].curr_button->next_button;
			}
			else
				buttons_order_B[episode].done=true;
			Bpress=true;
		}

		 if(!buttons_order_O[episode].done)
		if(bot_O.position<buttons_order_O[episode].curr_button->number)
			bot_O.move(FWD);
		else if(bot_O.position>buttons_order_O[episode].curr_button->number)
			bot_O.move(BCK);
		else if((buttons_order_B[episode].done && !Bpress) || (buttons_order_O[episode].curr_button->rating < buttons_order_B[episode].curr_button->rating && !Bpress))
		{
			if(buttons_order_O[episode].curr_button->next_button!=NULL)
				buttons_order_O[episode].curr_button=buttons_order_O[episode].curr_button->next_button;
			else
				buttons_order_O[episode].done=true;
		}
		this->seconds++;
		Bpress=false;
		return true;
	}
}state;

void timer()
{
	for(state.episode=0;state.episode<state.episode_amount;state.episode++)
	{
		bot_O.position=1;bot_B.position=1;
		while(true)
		{
			if(!state.SendOrder())
				break;
		}
	}
}

void main()
{
	char file_content[10000];
	int i=0;
	file_content[0]=0;
	FILE * f=fopen("input","r");
	while(true)
	{
		file_content[i]=fgetc(f);
		if(i>0 && file_content[i-1]==EOF)
			break;
		i++;
	}
	fclose(f);
	file_content[i+1]='\0';
	state.fill(file_content);
}

