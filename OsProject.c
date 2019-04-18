#include<stdio.h>
#include<conio.h>
void main()
{
  char p[10][5],temp[5];
  int i,j,pt[10],wt[10],totwt=0,pr[10],temp1,n;
  float avgwt;
 printf("Please enter the number of processes to create:");
 scanf("%d",&n);
  for(i=0;i<n;i++){
        printf("Enter the NAME of process >> %d <<:",i+1);
        scanf("%s",&p[i]);
        printf("Enter the TIME for process >> %d <<:",i+1);
        scanf("%d",&pt[i]);
        printf("Enter the PRIORITY for process >> %d <<:",i+1);
        scanf("%d",&pr[i]);

  }
 for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
             if(pr[i]>pr[j]){
                temp1=pr[i];
                pr[i]=pr[j];
                pr[j]=temp1;
                temp1=pt[i];
                pt[i]=pt[j];
                pt[j]=temp1;
                strcpy(temp,p[i]);
                strcpy(p[i],p[j]);
                strcpy(p[j],temp);
             }
        }
  }
 wt[0]=0;
 for(i=1;i<n;i++){
        wt[i]=wt[i-1]+pt[i-1];
        totwt=totwt+wt[i];
  }   
avgwt=(float)totwt/n;   
printf("p_name\t p_time\t priority\t w_time\n");
for(i=0;i<n;i++){
        printf(" %s\t %d\t %d\t\t %d\n" ,p[i],pt[i],pr[i],wt[i]);
}
printf("Total Waiting Time=%d and Average Waiting Time=%f",totwt,avgwt);
getch();
}
