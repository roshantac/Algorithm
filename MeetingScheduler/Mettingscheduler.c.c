#include <stdio.h>
#include <stdlib.h>



struct workingHours
{
    int start;
    int end;
}w_hours;

struct ipdata
{
    int idx;
    long long int date;
    long int time;
    int duration;
    char empid[10];
} ;

/*Split the string */
void split(char *inStr,int start,int end, char *resStr)
{
    int count=0;
    for(int i=start;i<=end;i++)
           *(resStr + count++)= *(inStr+i);

    *(resStr+ count)='\0';
}

/*Fill employee id in structure array*/
void fillEmpID(char *str, struct ipdata *st)
{
    split(str,20,25,st->empid);
}
/*Convert date from time to number*/
long long int datetol(char *str)
{
    char substring[12];
    int count=0;
    for(int i=0;i<4;i++)
        substring[count++] = *(str+i);
    for(int i=5;i<7;i++)
        substring[count++] = *(str+i);
    for(int i=8;i<10;i++)
        substring[count++] = *(str+i);
    substring[count] = '\0';
    return atoi(substring);

}
/*Convert time from string to number*/
int timetol(char *str)
{
    char substring[12];
    int count=0;
    for(int i=0;i<2;i++)
        substring[count++] = *(str+i);
    for(int i=3;i<5;i++)
        substring[count++] = *(str+i);
    substring[count] = '\0';
    return atoi(substring);
}

void disp(struct ipdata st)
{
    printf("\n %d , %lld , %d , %s \n",st.time,st.date,st.duration, st.empid);

}

void sort_st(struct ipdata *st, int count)
{
    struct ipdata st_temp;
    int min_idx;int j;
    for(int i=0; i<count-1;i++)
       {
        for(j=0; j<count-i-1;j++)

            if((st[j].date*10000 + st[j].time) > (st[j+1].date*10000+st[j+1].time))
                {
                    memcpy(&st_temp, &st[j], sizeof(struct ipdata));
                    memcpy(&st[j], &st[j+1], sizeof(struct ipdata));
                    memcpy(&st[j+1], &st_temp, sizeof(struct ipdata));
                }
        }
}

void fillSchedule(char *str, struct ipdata *st)
{
    static int idx=0;
    char substr[15];
    st->idx=idx++;
    split(str,0,9,substr);
    st->date = datetol(substr);
    split(str,11,15,substr);
    st->time = timetol(substr);
    split(str,17,17,substr);
    st->duration = atoi(substr);
}
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Read the file name from user
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
void getFileName(char *file)
{
	printf("\n Enter the file name(keep the file in same directory) : ");
	scanf("%s",file);
}


void setWorkingHour(char *str)
{
    char *substr[20];
    split(str,0,3,substr);
    w_hours.start = atoi(substr);
    split(str,5,8,substr);
    w_hours.end = atoi(substr);

}
void printResult(struct ipdata *st,int idx)
{
long long int prevDate=0;
int day,year,month;
for (int i=0;i<idx;i++)
{
    /*Checking time in working hours*/
    if((st[i].time + st[i].duration*100) <= w_hours.end && (st[i].time >=w_hours.start) )
    {
        if(prevDate!= st[i].date)
        {
            year = st[i].date/10000;
            month = (st[i].date - year*10000)/100;
            day = (st[i].date - (year*10000 + month*100));
            printf("\n %d-%02d-%02d",year,month,day);
            prevDate = st[i].date;
        }
        //TODO Meeting overlap is not done.
        printf("\n %02d:%02d %02d:%02d %s ",(int)(st[i].time/100),(int)(st[i].time - ((st[i].time/100)*100)),(int)(st[i].time+st[i].duration*100) /100,st[i].time -(st[i].time/100)*100,st[i].empid);
    }
}
}
void renderFile(char *fileName)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    int read, count =0, idx =0;
    struct ipdata st[10];
    fp = fopen(fileName, "r");
    if (fp == NULL)
        printf("\n Error in opening file \n");

    while ((read = getline(&line, &len, fp)) != -1) {
            if(count == 0)
            {
                setWorkingHour(line);
            }
            else if(count%2 == 1)
            {
                fillEmpID(line, &st[idx]);

            }
            else{
                fillSchedule(line, &st[idx++]);
            }
        count++;
    }
    if (line)
        {free(line);line=NULL;}
fclose(fp);
/*Sort in the order of date and time*/
sort_st(st, idx);

printResult(st,idx);
}

int main()
{

char fileName[50];
getFileName(fileName);
renderFile(fileName);
	return 0;
}
