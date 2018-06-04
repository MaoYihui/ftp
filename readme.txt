feature:
	1. list file in current  directory and also show the structure(position) of the directory 
            
            python3 client_ftp.py [hostname] [Pconnect_Port] -l [Qconnect_port]
        

        2. send short or long file to server
            
            python3 client_ftp.py [hostname] [Pconnect_Port] -g [file_sent]  [Qconnect_port]
            // send [file_sent] into server, and save the content in a file named receivedfile
            python3 client_ftp.py [hostname] [Pconnect_Port] -g [file_sent]  [file_recevie] [Qconnect_port] 
            //send [file_sent] into server, and save content in [file_received]    (whatever the file_received exist or not)
             
        3. make directory in current directory
                 
            python3 client_ftp.py [hostname] [Pconnect_Port] -m [new directory name]  [Qconnect_port]
        
        4. create new file  in current directory
                 
            python3 client_ftp.py [hostname] [Pconnect_Port] -f [new file name]  [Qconnect_port]
        
        5. change the position in any directory structure. which is as cd command in linux   
                 
            python3 client_ftp.py [hostname] [Pconnect_Port] -c [positon want to go]  [Qconnect_port]
            // in server end, it shows the current position after changed by client
        6. delete the file and directory in server side
           python3 client_ftp.py [hostname] [Pconnect_Port] -d [path_name]  [Qconnect_port]
           // path name is the path name of file or directory that you want to delete 


extra credit completed:
       1. send file without txt extension
       2. change directory positon
       3. make new file, the client can send the file to that new file in server
       4. make new directory
       5. server side get IP address from client.
       6. password
Text code:
         
     server end $   hostname                            
                    flip1.engr.oregonstate.edu          
                $   gcc server.c -o server_ftp                    
                $   ./server_ftp 8991                            $  python3 client_ftp.py flip1 8991 -l 32262
                                                               
 
      client end $   password: 123456
                 $   python3 client_ftp.py flip1 8991 -l 32262            // list files in current directory
                 $   python3 client_ftp.py flip1 8991 -f newfile 32262    // create a empty newfile in current directory 
                 $   python3 client_ftp.py flip1 8991 -g shortext 32262   // send a short textfile to server  
                 $   python3 client_ftp.py flip1 8991 -g shortext newfile 32262 // send a shortext to server's newfile
                 $   python3 client_ftp.py flip1 8991 -c ../ 32262        // change current directory position to up level 
                                                                          // cd ../
                 $   python3 client_ftp.py flip1 8991 -m newer 32262     // create a empty newdir in current directory 
                                                                         // because -c change the position into up level
                                                                         // newdir is in up level type cd .. to look at it
                 $   python3 client_ftp.py flip1 8991 -f new_file 32262    // create a empty newfile in current directory 
                 $   python3 client_ftp.py flip1 8991 -d new_file 32262   // delete a new_file in current directory 


                 the program also can send long text.


*hint because -c may cause that server end is not at the same level as the server.c
 -l could help you know where the sever end is. check it before you transfer data. 
reference from : apue book
