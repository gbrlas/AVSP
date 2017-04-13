/* PROGRAM */
   #include<stdio.h>
   #include<conio.h>
   #include<string.h>
   #include<math.h>
   void read();
   int noofintersectpts(long * heightA,long * heightB,long noofWires)
   {
   long currentA,currentB;
   int noopts=0;
      for(int i=0;i<noofWires;i++)
      {
	currentA=heightA[i];
	currentB=heightB[i];
	for(int j=i+1;j<noofWires;j++)
	{
	    if((currentA<heightA[j])&&(currentB>heightB[j]))
	    {
	       noopts++;
	    }
	    else if((currentA>heightA[j])&&(currentB<heightB[j]))
	    {
	       noopts++;
	    }
	}
      }
    return noopts;
   }

      void main()
     {
	read();
     }
   void read()
   {
	 FILE *fip,*fop;
	 long noofWires,heightA[1000],heightB[1000],currentA,currentB;
	 int  nocase,caseread=0;
	 char *ifilename,*ofilename;
	 printf("\n\nenter the input filename along with path and extension\n");
	 //scanf("%s",ifilename);
	 ifilename="input.txt";
	 printf("enter the output filename along with path and extension\n");
	 //scanf("%s",ofilename);
	 ofilename="out.txt";
	 fip=fopen(ifilename,"rt");
	 fop=fopen(ofilename,"wt");

	 if(fip==NULL)
	    printf("Input file is not opening %s",ifilename);
	 else  if(fop==NULL)
	    printf("Output file is not opening");
	 else
	 {
	    fscanf(fip,"%d",&nocase);
	    while(caseread<nocase)
	    {
	       if(feof(fip))
	       break;
	       fscanf(fip,"%ld",&noofWires);
	       caseread++;
	       for(int i=0;i<noofWires;i++)
	       {
		 fscanf(fip,"%ld%ld",&heightA[i],&heightB[i]);
	       }
	       int noofpts=noofintersectpts(heightA,heightB,noofWires);
	       fprintf(fop,"Case #%d: %d \n",caseread,noofpts);
	     }
	 }
	    fclose(fop);
	    fclose(fip);
	    getch();
   }