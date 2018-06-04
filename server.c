#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include <fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdarg.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <sys/stat.h>
#define MAXLINE 1000

#ifdef PATH_MAX
static int pathmax = PATH_MAX;
#else
static int pathmax = 0;
#endif

char *path_alloc(int *size);
void err_sys(const char *fmt, ...);
void err_doit(int useerrno, const char *fmt, va_list ap);




int main(int argc,char **argv)

{
   FILE *fp;
   int sd,newsd,ser,n,a,cli,pid,bd,port,clilen,i,data_port,s_d;
   char name[100],fileread[1000000],fname[100],ch,file[100],rcv[100],flag,port_s[100];
   struct sockaddr_in servaddr,cliaddr;
   struct sockaddr_in servaddr_data,cliaddr_data;
   int u=0;




   if (argc > 2){
      printf("Error: command length!\n");
   }


   //	while(1){


   int port_command=i = atoi (argv[1]);







   //while(1){
   data_port=0;
   port=port_command;
   sd=socket(AF_INET,SOCK_STREAM,0);
   for(i=0;i<100;i++)
      fileread[i]='\0';
   if(sd<0)
      printf("Cant create\n");
   else
      printf("Socket is created\n");

int reuse=1;
 if(setsockopt(sd,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int))<0){
     perror("error in setsockopt");
      }


   servaddr.sin_family=AF_INET;
   servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
   port=port+u;
   servaddr.sin_port=htons(port);

   a=sizeof(servaddr);

   bd=bind(sd,(struct sockaddr*)&servaddr,a);
   if(bd<0){
      printf("Cant bind\n");
      perror("bind failed. Error");
   }else
      printf("Binded\n");
   listen(sd,10);
   while(1){
      clilen=sizeof(cliaddr);
      newsd=accept(sd,(struct sockaddr*) &cliaddr,(socklen_t *)  &clilen);
      if(newsd<0)
      {
	 printf("Cant accept\n");
	 exit(1);
      }
      else
	 printf("Accepted\n");

      /*
   
      for(i=0;i<100;i++  )
	 rcv[i]='\0';
      if (recv(newsd,rcv,2,0)<0)
	 perror("error ");
   
      if (strcmp(rcv,"123456")==0)
       send (newsd,"1",1,0);
      else
       send (newsd,"0",1,0);
	 sleep(1);

	 */
      //   printf("cliaddr.sa_data=  %i\n",cliaddr.sin_port );   
      struct in_addr ipAddr=cliaddr.sin_addr;   
      char str[INET_ADDRSTRLEN];
      inet_ntop( AF_INET, &ipAddr, str, INET_ADDRSTRLEN );

      printf(" client connected, the ip: %s\n ",str);



      for(i=0;i<100;i++  )
	 rcv[i]='\0';
      fflush(stdout);
      if (recv(newsd,rcv,2,0)<0)
	 perror("error command from client, using (-l/-g/-c/-m)");
      for(i=0;i<100;i++)
	 port_s[i]='\0';
      char  mmm[]="get request from client \n";
      send (newsd,mmm,sizeof(mmm),0);
      fflush(stdout);
      if (recv(newsd,port_s,6,0)<0)
	 perror("error command format from client");

      if (strcmp (rcv,"-l")==0)
	 flag='l'; 
      else if (strcmp (rcv,"-g")==0)
	 flag='g';
      else if (strcmp (rcv,"-c")==0)
	 flag='c';
      else if (strcmp (rcv,"-m")==0)
	 flag='m';
      else if (strcmp (rcv,"-f")==0)
	 flag='f';
      else if (strcmp (rcv,"-d")==0)
	 flag='d';
      else 
	 flag='w';


      if ((strcmp(rcv,"-l")!=0)&&(strcmp(rcv,"-g")!=0)&&(strcmp(rcv,"-c")!=0)&&(strcmp(rcv,"-m")!=0)&&(strcmp(rcv,"-f")!=0)&&(strcmp(rcv,"-d")!=0)             ) {   

	 char error_message[]="error command line\0";
	 if(send(newsd,error_message,sizeof(error_message),0)<0)
	 {
	    printf("Cant send error message\n");
	 }
      }
      else{
	 char message[]="correct command line sent by client\0";
	 if(send(newsd,message,sizeof(message),0)<0)
	 {
	    printf("Cant send error message\n");
	 }

      }



      data_port=atoi(port_s);
      s_d=socket(AF_INET,SOCK_STREAM,0);
 if(setsockopt(s_d,SOL_SOCKET,SO_REUSEADDR,&reuse,sizeof(int))<0){
     perror("error in setsockopt");
      }
      for(i=0;i<100;i++)
	 fileread[i]='\0';
      if(s_d<0)
	 printf("Cant create\n");
      else
	 printf("Socket is created\n");
      servaddr_data.sin_family=AF_INET;
      servaddr_data.sin_addr.s_addr=htonl(INADDR_ANY);
      servaddr_data.sin_port=htons(data_port);
      a=sizeof(servaddr_data);
      bd=bind(s_d,(struct sockaddr*)&servaddr_data,a);
      if(bd<0)
	 perror("Cant bind\n");
      else
	 printf("Binded\n");
      listen(s_d,10);
      clilen=sizeof(cliaddr_data);
      newsd=accept(s_d,(struct sockaddr*) &cliaddr_data,(socklen_t *)  &clilen);
      if(newsd<0)
      {
	 printf("Cant accept\n");
      }
      else
	 printf("Accepted\n");


      for(i=0;i<100;i++  )
	 rcv[i]='\0';
      if (recv(newsd,rcv,6,0)<0)
	 perror("error ");
   
      if (strcmp(rcv,"123456")==0)
       send (newsd,"1",1,0);
      else{
       send (newsd,"0",1,0);
       flag='w';
      }	 
       sleep(1);
     
      ////////////////


      if (flag=='l'){
	 char *ptr;
	 int size;
         
	 ptr= path_alloc (&size);
	 if(getcwd(ptr,size)==NULL)
	    err_sys("get directory failed\n");
	 printf ("Receiving directory structure from %s\n",ptr);
	 struct dirent *de;  // Pointer for directory entry

	 DIR *dr = opendir("./");

	 if (dr == NULL)  // opendir returns NULL if couldn't open directory
	 {
	    printf("Could not open current directory" );
	 }

	 // Refer http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
	 // for readdir()
	 char string_files[]="The  directory is ";
	 strcat(string_files,ptr);
	 char string_space[]="\n";
	 strcat(string_files,string_space);

	 char string_directory[]=" The files includes: ";
	 strcat(string_files,string_directory);
	 while ((de = readdir(dr)) != NULL){
	    strcat(string_files,string_space);

	    strcat(string_files,de->d_name);

	 }
	 if(send(newsd,string_files,200,0)<0)
	 {
	    printf("Cant send current directory to client\n");
	 }

	 closedir(dr);   
	 sleep(1);



	 close(newsd);
	 //		close(s_d);
      }

      else if(flag=='m'){
	 for(i=0;i<100;i++  )
	    rcv[i]='\0';

	 if (recv(newsd,rcv,100,0)<0)
	    perror("Do not receive  directory which is for making in current directory\n");               

	 printf("recv_dir=%s",rcv);
	 if(mkdir(rcv,0777)<0)
	    perror("makoe direct error\n");               

	 close(newsd);


      }
      else if(flag=='d'){
	 for(i=0;i<100;i++  )
	    rcv[i]='\0';

	 n=recv(newsd,rcv,100,0);
	 if(remove(rcv)<0)
	    perror("remove failed\n");

    }
      else if(flag=='f'){
	 for(i=0;i<100;i++  )
	    rcv[i]='\0';
	 if (recv(newsd,rcv,100,0)<0)
	    perror("Do not receive  file name \n");               
         mode_t perms = S_IRWXU;
	 if(open(rcv,O_WRONLY|O_CREAT|O_TRUNC,perms)<0)
	    perror("create file failed \n");               


        close(newsd);
      }
      else if(flag=='c'){
	 for(i=0;i<100;i++  )
	    rcv[i]='\0';

	 n=recv(newsd,rcv,100,0);
	 if(chdir(rcv)<0)
	    perror("change direct file\n");               
	 char *ptr;
	 int size;

	 ptr= path_alloc (&size);
	 if(getcwd(ptr,size)==NULL)
	    err_sys("get directory failed\n");
	 printf ("Receiving directory structure from %s\n",ptr);

	 sleep(1);
	 close(newsd);
      }
      else if(flag=='g'){

	 for(i=0;i<100;i++  )
	    rcv[i]='\0';

	 n=recv(newsd,rcv,100,0);
	 sleep(1);
	 rcv[n]='\0';
	 fp=fopen(rcv,"r");
	 if(fp==NULL)

	 {

	    send(newsd,"0",1,0); 
	    sleep(5); 
	    close(newsd);
	 }

	 else
	 {

	    send(newsd,"1",1,0); 
	    for(i=0;i<1000000;i++)
	       fileread[i]='\0';
	    while(fgets(fileread,sizeof(fileread),fp))
	    { 
	       printf("%s",fileread);

	       if(send(newsd,fileread,sizeof(fileread),0)<0)
	       {
		  printf("Cant send\n");
	       }
	       sleep(1);
	    }

	    //		if(!fgets(fileread,sizeof(fileread),fp))
	    //		{
	    //			send(newsd,"completed",999999999,0);
	    //		}
	    close(newsd);
	 }

	 u=u+1;
	 //		close(s_d);
      }
      else{
	 close(newsd);
	 //	close(s_d);
      }
      close(s_d);
   }
   return(0);
}





char *path_alloc(int *size) {
   char *ptr;

   if (pathmax == 0) {
      errno = 0;
      if ( ( pathmax = pathconf("/", _PC_PATH_MAX) ) < 0 ) {
	 if ( errno == 0 )
	    pathmax = 1024;
	 else
	    err_sys("pathconf error for _PC_PATH_MAX");
      }
      else
	 pathmax++;
   }

   if ( ( ptr = malloc(pathmax + 1) ) == NULL )
      err_sys("malloc error for pathname");

   if ( size != NULL )
      *size = pathmax + 1;

   return(ptr);
}




void err_sys(const char *fmt, ...) {
   va_list ap;
   va_start(ap, fmt);
   err_doit(1, fmt, ap);
   va_end(ap);
   exit(1);
}




void err_doit(int useerrno, const char *fmt, va_list ap) {
   int errno_orig;
   char buf[MAXLINE + 1];

   errno_orig = errno;
   vsnprintf(buf, MAXLINE, fmt, ap);
   if (useerrno) {
      strncat(buf, ": ", MAXLINE + 1);
      strncat(buf, strerror(errno_orig), MAXLINE + 1);
   }
   strncat(buf, "\n", MAXLINE + 1);
   fputs(buf, stderr);

   return;
}
