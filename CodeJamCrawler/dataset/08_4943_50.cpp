// Train.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <conio.h>
#include <iostream>
#include <stdio.h>

using namespace std;

// Main Q structure contains start and stop timings of both stations .
struct Queue
{
	int start;
	int end;
	int station;
	struct Queue *next;
};

// Availability Q for trains at both stations 
struct Avail
{
	int AvailTime;
	int station;
	struct Avail *next;
};

// Test Cases 

struct TestCase
{
	Queue *tc;
	struct TestCase *next;
};

struct Queue * start= NULL;
struct Avail * at;
int a[2];
FILE *f;
FILE *fo;
int tc;
char c;
//int b;

void			CreateMainQ(void);
struct Queue *	CreateMQNode();
void			InsertInToQ(struct Queue *);
void			printMQ();
void			deleteQ();
void			popAT(struct Avail *);
void			pushAT(struct Queue *);
struct Avail	*CreateAt();
void			Solve();
void			deleteAT();
void			printAT();

int _tmain(int argc, _TCHAR* argv[])
{

   f=fopen("Input.txt","r+");
   char pr[20];
 
   int count=0;
   fo=fopen("Output.txt","w+");
   //fgets(buf,2,f);
   while((c=fgetc(f))!='\n')
   {
   tc=(10*tc)+(c-'0');
   }

    while(tc--)
	{
    CreateMainQ();
	printMQ();
//	deleteQ();
//	printf("\n DEL");
//	printMQ();
	a[0]=0;a[1]=0;
	Solve();
	count++;
	printf("\n\n Results : A= %d  B= %d ",a[0],a[1]);
	fprintf(fo,"Case #%d: %d %d\n",count,a[0],a[1]);
	//sprintf(pr,"Case #%d: %d %d\n",count,a[0],a[1]);
	//int op=fputs(pr,fo);
	deleteQ();
	deleteAT();
	}
	fclose(f);
	fclose(fo);
    getch();

	return 0;
}

void CreateMainQ()
{
  // FILE *f;
   char buf[2];
   char c=0;
   int ta=0,time=0,t=0,ca=0,cb=0;
   
   while((c=fgetc(f))!='\n')
   {
   ta=(10*ta)+(c-'0');
   }
   while((c=fgetc(f))!=' ')
   {
   ca=(10*ca)+(c-'0');
   }
   while((c=fgetc(f))!='\n')
   {
   cb=(10*cb)+(c-'0');
   }
   for(int i=0;i<ca;i++)
   {
     struct Queue *p=start;
     struct Queue *tmp=CreateMQNode();
	 tmp->station=0;
     for(int j=0;j<12;j++)
	 {
	   c=fgetc(f);
      	  if(c==':')
		  { 
			 time=t*60;
			 t=0;
		  }
		  else if(c==' ')
		  {   time+=t;
	          tmp->start=time;
			  time=0;
			  t=0;
		  }
		  else if(c=='\n')
		  {
			  time+=t;
			  tmp->end=time+ta;
			  time=0;
			  t=0;
		  }
		  else
          {
			 t=(t*10)+(c-'0'); 
		  }
	 }

	InsertInToQ(tmp);
   }
	 for(int i=0;i<cb;i++)
   {
     struct Queue *p=start;
     struct Queue *tmp=CreateMQNode();
	 tmp->station=1;
     for(int j=0;j<12;j++)
	 {
	   c=fgetc(f);
      	  if(c==':')
		  { 
			 time=t*60;
			 t=0;
		  }
		  else if(c==' ')
		  {   time+=t;
	          tmp->start=time;
			  time=0;
			  t=0;
		  }
		  else if(c=='\n')
		  {
			  time+=t;
			  tmp->end=time+ta;
			  time=0;
			  t=0;
		  }
		  else
          {
			 t=(t*10)+(c-'0') ;
		  }
	 }
	  InsertInToQ(tmp);
   }
	  
  }
     
   
   struct Queue * CreateMQNode()
   {
	   struct Queue *tmp = (struct Queue *) malloc(sizeof(struct Queue));
	   tmp->next=NULL;
	   return tmp;
   }

   void printMQ()
   {
	   struct Queue *p=start;
	   while(p!=NULL)
	   {
		   printf("\nstart= %d : end= %d : station= %d",p->start,p->end,p->station);
		   p=p->next;
	   }
   }

   void InsertInToQ(struct Queue *tmp)
   {

	  struct Queue *p=start;
	  struct Queue *q;
	  if(p==NULL)
		start=tmp;
	  else if(p->start>tmp->start)
	  {
		  tmp->next=start;
		  start=tmp;
	  }

	  else
	  { 
		  //while(p->next!=NULL)
		  while(p->next!=NULL&&p->next->start<tmp->start)
			  p=p->next;
		  q=p->next; 
		  p->next=tmp;
		  tmp->next=q;
	  }
   }
   void deleteQ()
   {
	   struct Queue *p=start;
	   struct Queue *q;
	   if(start==NULL)
		   return;
	   else
	   {
		   while(start!=NULL)
		   {
	     q= start;
		 start=start->next;
		 free(q);
		   }
	   }
   }

   void popAT(struct Avail *q)
   {
	   struct Avail *p=at;
	   struct Avail *t;
	   if(p==q)
	   {
		   at=p->next;
		   free(q);
		   return;
	   }
	   while(p->next!=q)
		   p=p->next;
	   t=q->next;
	   p->next=t;
	   free(q);
	 //  fprintf(fo,"\nPOP");
	   printAT();
   }
   void pushAT(struct Queue *p)
   {
	   struct Avail *q=at;
	   struct Avail *tmp=CreateAt();
	   tmp->AvailTime=p->end;
	   tmp->station=1-p->station;
	   if(q==NULL)
	   {
		   at=tmp;
		   return;
   	   }
	   else if(q->AvailTime>=tmp->AvailTime)
	   {
		   tmp->next=q;
		   at=tmp;
		   return;
	   }
	   while(q->next&&q->next->AvailTime<p->end)
		   q=q->next;
	   tmp->next=q->next;
	   q->next=tmp;

	//   fprintf(fo,"\nPUSH");
	   printAT();
   }

   struct Avail *CreateAt()
   {
	   struct Avail *tmp;
	   tmp=(struct Avail *)malloc(sizeof(struct Avail));
	   tmp->next=NULL;
	   return tmp;
   }
	   
   void deleteAT()
   {
	   struct Avail *p=at;
	   struct Avail *q;
	   if(at==NULL)
		   return;
	   else
	   {
		   while(at!=NULL)
		   {
	     q= at;
		 at=at->next;
		 free(q);
		   }
	   }
   }


   void Solve()
   {
      struct Queue *p=start;
      struct Avail *q=at;
	  while(p)
	  {
		  
		  struct Avail *q=at;

		  while(q)
		  {
			  if(p&&p->start>=q->AvailTime&&q->station==p->station)
			  {
				  popAT(q);
				  pushAT(p); 
				  p=p->next;
				  break;
				   
			  }
			  else 
			  if(p&&p->start>=q->AvailTime&&q->station!=p->station)
			  {
				  q=q->next;
				  if(q==NULL)
					  q=NULL;
			  }
			  else if(p) 
			  { 
				  a[p->station]++;
				  pushAT(p);
				  p=p->next;
				  q=at;
				  break;
			  }
			  else
				  break;
		   }
		   
		  if(q==NULL)
		  {       
			      a[p->station]++;
				  pushAT(p);
				  p=p->next;
				  q=at;
		  }
		    
	  }
   }

   void printAT()
   {
	   struct Avail *p=at;
	 //  fprintf(fo,"\n\ntime:");
	   if(at==NULL)
		   return;
	   while(p!=NULL)
	   {
	//	   fprintf(fo,"%d-%d ",p->AvailTime,p->station);
		   p=p->next;
	   }
   }







	 

