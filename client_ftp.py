import sys
import socket
import struct
TCP_IP = 'flip1'
TCP_PORT = 8812
BUFFER_SIZE = 200
B_SIZE = 1000000


#print(len(sys.argv))
#print (sys.argv[1])



  

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((sys.argv[1],int(sys.argv[2])))
#s.connect((TCP_IP, TCP_PORT))
#s.send(str(len(sys.argv)).encode())
#for index in range(len(sys.argv)):


s.send(sys.argv[3].encode())
port_index= len(sys.argv)-1
s.send(sys.argv[port_index].encode())
data=s.recv(BUFFER_SIZE)
print('server:', (data.decode('ISO-8859-1')))
  

d_s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
   #d_s.connect((TCP_IP,int(sys.argv[5])))
port_index= len(sys.argv)-1
d_s.connect((sys.argv[1],int(sys.argv[port_index])    ))


ps=input("Password: ")
d_s.send(ps.encode());
d=d_s.recv(1)

if (d.decode()=="0"):
   print("invalid password");
   d_s.close()
   sys.exit(0)





if (sys.argv[3]=="-l"):
   data =d_s.recv(BUFFER_SIZE)
   #print( (data.decode('ISO-8859-1')))
   print( (data.decode("utf-8", "ignore")))
   s.close()
elif (sys.argv[3]=="-g"):
   message="text"
      #d_s.send(message.encode())
   d_s.send(sys.argv[4].encode())
   b_s=1
   data=d_s.recv(b_s)
   if(data.decode()=="0"):
      print('File not found')
      d_s.close()
      sys.exit(0)
   else : 
     #   with open('received_file', 'wb') as f:
      with open(sys.argv[5], 'wb') as f:
          print('file opened')
   #    while True:
           #print('receiving data...')
          data =d_s.recv(B_SIZE,socket.MSG_WAITALL)
          print('data=%s', (data.decode('ISO-8859-1')))
          s.close()
          if not data:
              f.close()
              print('file close()')
             #  break
           # write data to a file
          f.write(data.decode('ISO-8859-1').encode())
elif (sys.argv[3]=="-c"):
      #message="../";
   d_s.send(sys.argv[4].encode())
   s.close()
elif (sys.argv[3]=="-m"):
   #message="../";
   d_s.send(sys.argv[4].encode())
   s.close()
elif (sys.argv[3]=="-f"):
   #message="../";
   d_s.send(sys.argv[4].encode())
   s.close()
elif (sys.argv[3]=="-d"):
   #message="../";
   d_s.send(sys.argv[4].encode())
   s.close()
else:
   s.close()
   sys.exit(0);


d_s.close()
print('connection closed')
