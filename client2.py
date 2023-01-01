import socket
import binascii
#import bind
import time
import math
from argparse import ArgumentParser

Ip=""


def parse_args():
    # parse the command line arguments
    args = ArgumentParser()
    args.add_argument('--server-host', default="169.237.229.88")
    args.add_argument('--server-port', default=53, type=int)
    return args.parse_args()
    
    #input domain name
    #look at rfc look at each header id random 1415=a04x, op code 1 bit
    #when sending query in server responce for qr 
    # for question 7 bits each
    #input domain name and changre accorfing to length of domain
    #add only header and question 
    #first build in hex add next to eachothermthen convert to binary and send
    #heaqder has 6 parts
    #only write till question in client for part 1
    
    #convert to binary before sending to server
    #create dns querry for tmz.com TMZ.COM IS QUERRY for first part
    
    #send binary as message below
    
    

def start_udp_client(server_host, server_port):
    
    
    timeyoutube1=0
    timeyoutube2=0
    timefacebook1=0
    timefacebook2=0
    timetmz1=0
    timetmz2=0
    timecnn1=0
    timecnn2=0
    timenytimes1=0
    timenytimes2=0
    payloadtmz=""
    payloadyoutube=""
    payloadfacebook=""
    payloadcnn=""
    payloadnytime=""
    payload=""
    payloadpart1="A06B01000001000000000000"
    payloadpart3="0000010001"
    payloadpart2= input("Please enter website:")
    split=payloadpart2.split(".")
    leng1=str(hex(len(split[0])))
    leng1=leng1.replace("x","")
    part1=split[0].encode().hex()
    leng2=str(hex(len(split[1])))
    leng2=leng2.replace("x","")
    part2=split[1].encode().hex()
    leng3=str(hex(len(split[2])))
    leng3=leng3.replace("x","")
    part3=split[2].encode().hex()
   
    payload+= payloadpart1+leng1 + part1 +leng2 + part2 +leng3 +part3+payloadpart3
    

    
    
    
    #payloadbinary=  bytes(''.join(format(i, '08b') for i in bytearray(payload, encoding ='utf-8')),'utf-8')
    #print(payloadbinary)
    # create a client socket with the following specifications
    #   AF_INET -> IPv4 socket
    #   SOCK_DGRAM -> UDP protocol
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client_socket:

            
            t13=time.time()
          
            client_socket.connect(("136.159.85.15", server_port))
            client_socket.sendto(binascii.unhexlify(payload), ("136.159.85.15", server_port))
            data, address = client_socket.recvfrom(1024)
            t23=time.time()
            print("Time for CANADA: ",t23-t13)
            
            t12=time.time()
            client_socket.connect(("185.161.112.34", server_port))
            client_socket.sendto(binascii.unhexlify(payloadtmz), ("185.161.112.34", server_port))
            data, address = client_socket.recvfrom(1024)
            t22=time.time()
            print("Time for IRAN: ",t22-t12)
            
            t11=time.time()
            client_socket.connect((server_host, server_port))
            client_socket.sendto(binascii.unhexlify(payloadtmz), (server_host, server_port))
            data, address = client_socket.recvfrom(1024)
            t21=time.time()
            print("Time for US: ",t21-t11)
           
            
            
            
            
            #print(f"Client #{address}: Message from server:", data)
            
            datainhex=binascii.hexlify(data).decode("utf-8")
            octets = [datainhex[i:i+2] for i in range(0, len(datainhex), 2)]
            pairs = [" ".join(octets[i:i+2]) for i in range(0, len(octets), 2)]
            response="\n".join(pairs)
            #binarydata=  ' '.join(map(bin, bytearray(str(datainhex), "utf-8")))
            
            
            ID=octets[0:2]
            FLAGS=octets[2:4]
            NUMQUESTION=octets[4:6]
            NUMANSWER=octets[6:8]
            NSCOUNT=octets[8:10]
            NUMADDITIONAL=octets[10:12]
            QUESTION=octets[12:25]
            QTYPE=octets[25:27]
            QCLASS=octets[27:29]
            NAME=octets[13:24]
            TYPE=octets[31:33]
            CLASS=octets[33:35]
            TTL=octets[37:41]
            RDLENGTH=octets[41:43]
           # RDDATA=octets[45:53]
            RDDATA=octets[-4:]
            #print(octets[27:])
            
            
            domain=""
            x=0
            predomain=int(octets[12],16) #==3
            for i in range(0,predomain):
                domain += bytearray.fromhex(octets[13+i]).decode()
                x+=1
            domain +="."
            
            domainlength= int(octets[13+predomain],16)#==16 
            for i in range(0,domainlength):
                domain += bytearray.fromhex(octets[14+predomain+i]).decode()
                x +=1
            domain +="."
            
            postdomainlength= int(octets[14+domainlength+predomain],16)
            for i in range(0,postdomainlength):
                domain += bytearray.fromhex(octets[14+predomain+domainlength+1+i]).decode()
                x+=1
            
            type1=  str(int(TYPE[1],16)) 
            
            
            Ip= str(int(RDDATA[0],16)) + "." +  str(int(RDDATA[1],16)) + "." +  str(int(RDDATA[2],16)) + "." +  str(int(RDDATA[3],16))
            if(type1=="1"):
                print("DNS record type is: A")
            print("The IP of ",domain," is: ",Ip)
            print("The domain name is: ", domain)
    
    with  socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        
            target_host="www.tmz.com"
            client_socket.connect((Ip, 80))
            request = "GET / HTTP/1.1\r\nHost:%s\r\n\r\n" % target_host
            timehttp=time.time()
            client_socket.send(request.encode()) 
            response = client_socket.recv(4096)  
            timehttpr=time.time()
            print("RTT for HTTP client to server: ", timehttpr-timehttp)
            http_response = repr(response)
            http_response_len = len(http_response)
            print(http_response)
    
    
     ##partB
     #PART B
#     with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server_socket:
#       x=0
#       host = "198.41.0.4"
#       timeDNS=time.time()
#       for  i in range(4):
#              if(x==0):
#                  print("Root ip address: ",host)
#              if(x==1):
#                  print("TLD ip address: ",host)
#              if(x==2):
#                  print("AUTH ip address: ",host)
#              if(x==3):
#                  print("Website ip address: ",host)
          
#              if(x!=3):
#                  server_socket.connect((host, server_port))##root server
#                  server_socket.sendto(binascii.unhexlify(payloadtmz), (host, server_port))
#                  data, address = server_socket.recvfrom(1024)

#                      # decode the message and print
#                      #print(f"Message from {addr}: {message.decode()}")\
#                  datainhex=binascii.hexlify(data).decode("utf-8")
#                  #print(datainhex)
#                  octets = [datainhex[i:i+2] for i in range(0, len(datainhex), 2)]
#                  #predomain=int(octets[12],16) #==3
#                  #domainlength= int(octets[13+predomain],16)#==16 
#                  #postdomainlength= int(octets[14+domainlength+predomain],16)
#                  #RDDATAstart= 31 + predomain + postdomainlength + domainlength
#                  #TYPEstart= 22 + predomain + postdomainlength + domainlength
#                      #print(octets)
# #                 #TYPE=octets[TYPEstart:TYPEstart+2]
#              # RDDATA=octets[RDDATAstart:RDDATAstart+4]
# #                 #print(RDDATA)
# #             # type1=  str(int(TYPE[1],16))
# #             # print(type1)
                    
# #                 #if(type1=="1"):
# #                 #    print("DNS record type is: A")
#                  host= str(int(octets[-4],16)) + "." +  str(int(octets[-3],16)) + "." +  str(int(octets[-2],16)) + "." +  str(int(octets[-1],16))
#                  x+=1
#       timeDNS1=time.time()
#       print("The RTT for DNS: ",timeDNS1-timeDNS)
        
    
    
#     #part C
#        #part C     
#   #part C
#     with  socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
#         #generte payload and time for each website
#         for i in range(4):
#             payloadpart1="A06B01000001000000000000"
#             payloadpart3="0000010001"
#             if(i==0):
#                 payloadpart2=="www.youtube.com"
#             if(i==1):
#                 payloadpart2=="www.facebook.com"
#             if(i==2):
#                 payloadpart2=="www.nytimes.com"
#             if(i==3):
#                 payloadpart2=="www.cnn.com"
#             split=payloadpart2.split(".")
#             leng1=str(hex(len(split[0])))
#             leng1=leng1.replace("x","")
#             part1=split[0].encode().hex()
#             leng2=str(hex(len(split[1])))
#             leng2=leng2.replace("x","")
#             part2=split[1].encode().hex()
#             leng3=str(hex(len(split[2])))
#             leng3=leng3.replace("x","")
#             part3=split[2].encode().hex()
#             payloadpart1+= leng1 + part1 +leng2 + part2 +leng3 +part3+payloadpart3
#             if(i==0):
#                 payloadyoutube=payloadpart1
#                 print("youtbe payload: ",payloadyoutube)
#             if(i==1):
#                 payloadfacebook=payloadpart1
#                 print("Facebook payload: ", payloadfacebook)
#             if(i==2):
#                 payloadnytime=payloadpart1
#                 print("Nytimes payload: ", payloadnytime)
#             if(i==3):
#                 payloadcnn=payloadpart1
#                 print("CNN payload: ", payloadcnn)
#         ipyoutube=""
#         ipfacebook=""
#         ipnytimes=""
#         ipcnn=""
#         x=0
#         host = "198.41.0.4"
#         timeDNS=time.time()
#         for  i in range(4):
#             if(x==0):
#                 print("Root ip address: ",host)
#             if(x==1):
#                 print("TLD ip address: ",host)
#             if(x==2):
#                 print("AUTH ip address: ",host)
#             if(x==3):
#                 print("Website ip address: ",host)
          
#             if(x!=3):
#                 server_socket.connect((host, server_port))##root server
#                 server_socket.sendto(binascii.unhexlify(payloadfacebook), (host, server_port))
#                 data, address = server_socket.recvfrom(1024)

#                     # decode the message and print
#                     #print(f"Message from {addr}: {message.decode()}")\
#                 datainhex=binascii.hexlify(data).decode("utf-8")
#                 #print(datainhex)
#                 octets = [datainhex[i:i+2] for i in range(0, len(datainhex), 2)]
                
#                 host= str(int(octets[-4],16)) + "." +  str(int(octets[-3],16)) + "." +  str(int(octets[-2],16)) + "." +  str(int(octets[-1],16))
#                 x+=1
#         timeDNS1=time.time()
#         print("The RTT for DNS: ",timeDNS1-timeDNS)
        
      
            
#         # print("Time to resolve facebook: ",timefacebook2-timefacebook1)
#         # print("Time to resolve youtube: ",timeyoutube2-timeyoutube1)
#         # print("Time to resolve TMZ: ",timetmz2-timetmz1)
#         # print("Time to resolve nytime: ",timenytime2-timenytime1)
#         # print("Time to resolve cnn: ",timecnn2-timecnn1)
            
#         # print("TTL facebook: ",octetsf[TTLstartf:TTLstartf+4])
#         # print("TTL youtube: ",octetsy[TTLstarty:TTLstarty+4])
#         # print("TTL TMZ: ",octetst[TTLstartt:TTLstartt+4])
#         # print("TTL nytime: ",octetsn[TTLstartn:TTLstartn+4])
#         # print("TTL cnn: ",octetsc[TTLstartc:TTLstartc+4])
            
            
    
            


if __name__ == '__main__':
    args = parse_args()
    start_udp_client(args.server_host, args.server_port)
    
    #what encode() does, what to do with ip listed in assignment, remove for loop?, what ip to put on top, what to write to question or authority, what is payload
    #whole big string is pay load
    #for first part write upto question leave blank everything 
    #no server in part one
    
    #to parse