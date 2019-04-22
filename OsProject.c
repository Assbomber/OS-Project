#include<stdio.h>
	#include<conio.h>
	
	#define yel  "\x1b[33m"
	#define gre "\x1b[32m"
	
	void function1();
	static int Total_wait_time;
	static float Average_wait_time,Average_turnaroundtime;
	void main()
	{  printf("\t\t\t\t\t\t\t---------------------------\n");
	    printf("\t\t\t\t\t\t\t WECLOME TO CPU SCHEDULER\n");
	    printf("\t\t\t\t\t\t\t--------------------------\n");
	    function1();
	    printf("\nTotal Waiting Time=%d\nAverage Waiting Time=%f\n",Total_wait_time,Average_wait_time);
	getch();
	}
	
	void function1(){
	    char p[10][5],temp[5];
	  int i,j,pro_time[10],wt[10],totwait=0, totpturn=0,pr[10],temp1,n;
	  unsigned pturn[10];
	  float avgwait,avgpturn;
	  system("setterm -bold on");
	 printf(yel "Please enter the number of processes to create=>");
	 scanf("%d",&n);
	  for(i=0;i<n;i++){
	        printf(yel "Enter the NAME of process >> %d <<:",i+1);
	        scanf("%s",&p[i]);
	        printf(yel "Enter the TIME for process >> %d <<:",i+1);
	        scanf("%d",&pro_time[i]);
	        printf(yel "Enter the PRIORITY for process >> %d <<:",i+1);
	        scanf("%d",&pr[i]);
	

	  }
	 for(i=0;i<n-1;i++){
	        for(j=i+1;j<n;j++){
	             if(pr[i]>pr[j]){
	                temp1=pr[i];pr[i]=pr[j];pr[j]=temp1; 
	                temp1=pro_time[i];pro_time[i]=pro_time[j];pro_time[j]=temp1;
	                strcpy(temp,p[i]);strcpy(p[i],p[j]);strcpy(p[j],temp);
	             }
	        }
	  }
	  wt[0]=0;
	  pturn[0]=pro_time[0]-wt[0];
	 for(i=1;i<n;i++){                
	        wt[i]=wt[i-1]+pro_time[i-1];
	        totwait=totwait+wt[i];
	        pturn[i]=pro_time[i]-wt[i];
	        totpturn=totpturn+pturn[i];
	  }   
	avgwait=(float)totwait/n; 
	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("Process Name\t Time\t Priority\t Wait Time\tTurnAroundTime\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for(i=0;i<n;i++){
	        printf(yel " %s\t\t %d\t %d\t\t %d\t\t%d\n" ,p[i],pro_time[i],pr[i],wt[i],pturn[i]);
	}
	Total_wait_time=totwait;
	Average_wait_time=avgwait;
//	Average_turnaroundtime=avgpturn;
	
	}
