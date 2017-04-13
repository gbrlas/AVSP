#include<stdio.h>

void solve(int i,int ans1,int ans2,int mat1[],int mat2[],FILE *fp,FILE *out);

int main()
{
  int T,ans1,ans2,i,j;
  int mat1[16],mat2[16];
  FILE *fp,*out;

  fp = fopen("./A-small-attempt1.in","r");
  out = fopen("./A-small-output1.txt","w");

  fscanf(fp,"%d",&T);
  for(i=0;i<T;i++){
    fscanf(fp,"%d",&ans1);
    for(j=0;j<16;j++){
      fscanf(fp,"%d",&mat1[j]);
    }
    fscanf(fp,"%d",&ans2);
    for(j=0;j<16;j++){
      fscanf(fp,"%d",&mat2[j]);
    }
    solve(i,ans1,ans2,mat1,mat2,fp,out);
  }

  return 0;
}

void solve(int i,int ans1,int ans2,int mat1[],int mat2[],FILE *fp,FILE *out)
{
  int row1[4],row2[4],j,k,ans,num=0;

  for(j=0;j<4;j++){
    row1[j] = mat1[4*(ans1-1)+j];
    row2[j] = mat2[4*(ans2-1)+j];
  }

  for(j=0;j<4;j++){
    for(k=0;k<4;k++){
      if(row1[j] == row2[k]){
	ans = row1[j];
	num++;
      }
    }
  }

  fprintf(out,"Case #%d: ",i+1);
  if(num==0){
	fprintf(out,"Volunteer cheated!\n");
  }else if(num==1){
        fprintf(out,"%d\n",ans);
  }else{
        fprintf(out,"Bad magician!\n");
  }
}
