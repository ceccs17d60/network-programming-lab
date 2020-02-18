#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
int trim(char buff[])
{
buff[strcspn(buff,"\r\n")]=0;
}
int main()
{
int fd,i,n,rno,found=0;
char buff[32];
fd=open("students.txt",O_RDWR|O_CREAT|O_TRUNC,0755);
printf("enter no of students:");
fgets(buff,32,stdin);
trim(buff);
n=atoi(buff);
for(i=0;i<n;i++)
{
printf("student %d\n",i+1);
printf("enter rno:");
fgets(buff,32,stdin);
trim(buff);
write(fd,buff,sizeof(buff));

printf("enter name:");
fgets(buff,32,stdin);
trim(buff);


write(fd,buff,sizeof(buff));

printf("enter branch:");
fgets(buff,32,stdin);
trim(buff);
write(fd,buff,sizeof(buff));
printf("\n");
}
lseek(fd,0,SEEK_SET);
printf("enter rno of student to read");
fgets(buff,32,stdin);
rno=atoi(buff);
printf("\n");
for(i=0;i<n;i++)
{
read(fd,buff,sizeof(buff));
if(atoi(buff)==rno)
{
found=1;
printf("student found\n");
read(fd,buff,sizeof(buff));
printf("name:%s\n",buff);
read(fd,buff,sizeof(buff));
printf("branch:%s\n",buff);
break;
}else
{
lseek(fd,64,SEEK_CUR);
}
}
if(!found)
{
printf("student not found\n");
}
close(fd);
return 0;
}


