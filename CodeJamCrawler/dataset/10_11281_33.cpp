/* PROGRAM */
   #include<stdio.h>
   #include<conio.h>
   #include<string.h>
   #include<math.h>
   void read();
   void main()
     {
	read();
     }
   void read()
   {
	 FILE *fip,*fop;
	 long noofSwap,noofSnap,fon,fdiff;
	 int  nocase,caseread=0L,status;
	 char *ifilename,*ofilename;
	 printf("\n\nenter the input filename along with path and extension\n");
	 scanf("%s",ifilename);
	 //ifilename="A-smallat.in";
	 printf("enter the output filename along with path and extension\n");
	 scanf("%s",ofilename);
	 fip=fopen(ifilename,"rt");
	 fop=fopen(ofilename,"wt");

	 if(fip==NULL)
	    printf("Input file is not opening %s",ifilename);
	 else  if(fop==NULL)
	    printf("Output file is not opening");
	 else
	 {
	    fscanf(fip,"%d",&nocase);
	    //printf("%d",nocase);
	    while(caseread<nocase)
	    {
	       if(feof(fip))
	       break;
	       fscanf(fip,"%ld%ld",&noofSwap,&noofSnap);
	       fon=pow(2,noofSwap)-1;
	       fdiff=pow(2,noofSwap);
	       ++caseread;
	       if(((noofSnap-fon)%fdiff)==0)
	       {
	       fprintf(fop,"Case #%d: %s \n",caseread,"ON");
	       }
	       else
	       {
	       fprintf(fop,"Case #%d: %s \n",caseread,"OFF");
	       }
	     }
	 }
	    fclose(fop);
	    fclose(fip);
	    getch();
   }