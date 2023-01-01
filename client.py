import socket
import binascii
import time
import math
from argparse import ArgumentParser


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
    payload = ''
    payloadpart1 = "A06B01000001000000000000"
    payloadpart3 = "0000010001"
    payloadpart2 = input("Please enter website:")
    split = payloadpart2.split(".")
    leng1 = str(hex(len(split[0])))
    leng1 = leng1.replace("x", "")
    part1 = split[0].encode().hex()
    leng2 = str(hex(len(split[1])))
    leng2 = leng2.replace("x", "")
    part2 = split[1].encode().hex()
    leng3 = str(hex(len(split[2])))
    leng3 = leng3.replace("x", "")
    part3 = split[2].encode().hex()

    payload += payloadpart1 + leng1 + part1 + leng2 + part2 + leng3 + part3 + payloadpart3
    print(payload)
    
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as client_socket:

            t11=time.time()
          
            client_socket.connect((server_host, server_port))
            client_socket.sendto(binascii.unhexlify(payload), (server_host, server_port))
            data, address = client_socket.recvfrom(1024)
            t21=time.time()
            print("Time for US: ",t21-t11)
            datainhex=binascii.hexlify(data).decode("utf-8")
            octets = [datainhex[i:i+2] for i in range(0, len(datainhex), 2)]
            domain=""
            x=0
            predomain=int(octets[12],16) #==3
            for i in range(0,predomain):
                domain += bytearray.fromhex(octets[13+i]).decode()
            domain +="."
            
            domainlength= int(octets[13+predomain],16)#==16 
            for i in range(0,domainlength):
                domain += bytearray.fromhex(octets[14+predomain+i]).decode()
                x = i+1
            domain +="."
            
            postdomainlength= int(octets[14+domainlength+predomain],16)
            for i in range(0,domainlength):
                domain += bytearray.fromhex(octets[14+predomain+domainlength+1+i]).decode()
            RDDATA=octets[-4:]
            Ip= str(int(RDDATA[0],16)) + "." +  str(int(RDDATA[1],16)) + "." +  str(int(RDDATA[2],16)) + "." +  str(int(RDDATA[3],16))
            print("Ip of ",domain," in US is: ",Ip)
            print("The domain name is: ", domain)
            
            t13=time.time()
          
            client_socket.connect(("136.159.85.15", server_port))
            client_socket.sendto(binascii.unhexlify(payload), ("136.159.85.15", server_port))
            data, address = client_socket.recvfrom(1024)
            t23=time.time()
            print("Time for CANADA: ",t23-t13)
            datainhex=binascii.hexlify(data).decode("utf-8")
            octets = [datainhex[i:i+2] for i in range(0, len(datainhex), 2)]
            domain=""
            x=0
            predomain=int(octets[12],16) #==3
            for i in range(0,predomain):
                domain += bytearray.fromhex(octets[13+i]).decode()
            domain +="."
            
            domainlength= int(octets[13+predomain],16)#==16 
            for i in range(0,domainlength):
                domain += bytearray.fromhex(octets[14+predomain+i]).decode()
                x = i+1
            domain +="."
            
            postdomainlength= int(octets[14+domainlength+predomain],16)
            for i in range(0,domainlength):
                domain += bytearray.fromhex(octets[14+predomain+domainlength+1+i]).decode()
            RDDATA=octets[-4:]
            Ip= str(int(RDDATA[0],16)) + "." +  str(int(RDDATA[1],16)) + "." +  str(int(RDDATA[2],16)) + "." +  str(int(RDDATA[3],16))
            print("Ip of ",domain," in CANADA is: ",Ip)
            print("The domain name is: ", domain)
            
            t12=time.time()
          
            client_socket.connect(("91.245.229.1", server_port))
            client_socket.sendto(binascii.unhexlify(payload), ("91.245.229.1", server_port))
            data, address = client_socket.recvfrom(1024)
            t22=time.time()
            print("Time for IRAN: ",t22-t12)
            
            datainhex=binascii.hexlify(data).decode("utf-8")
            octets = [datainhex[i:i+2] for i in range(0, len(datainhex), 2)]
            pairs = [" ".join(octets[i:i+2]) for i in range(0, len(octets), 2)]
            response="\n".join(pairs)
          
            
            
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
            #RDDATA=octets[45:53]
            RDDATA=octets[-4:]
            
            
            domain=""
            x=0
            predomain=int(octets[12],16) #==3
            for i in range(0,predomain):
                domain += bytearray.fromhex(octets[13+i]).decode()
            domain +="."
            
            domainlength= int(octets[13+predomain],16)#==16 
            for i in range(0,domainlength):
                domain += bytearray.fromhex(octets[14+predomain+i]).decode()
                x = i+1
            domain +="."
            
            postdomainlength= int(octets[14+domainlength+predomain],16)
            for i in range(0,domainlength):
                domain += bytearray.fromhex(octets[14+predomain+domainlength+1+i]).decode()
            
            type1=  str(int(TYPE[1],16)) 
            
            Ip= str(int(RDDATA[0],16)) + "." +  str(int(RDDATA[1],16)) + "." +  str(int(RDDATA[2],16)) + "." +  str(int(RDDATA[3],16))
            if(type1=="1"):
                print("DNS record type is: A")
            print("The IP of ",domain, " in IRAN is: ",Ip)
            print("The domain name is: ", domain)
    
    with  socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        
            target_host="www.tmz.com"
            client_socket.connect(("13.35.125.122", 80))
            request = "GET / HTTP/1.1\r\nHost:%s\r\n\r\n" % target_host
            timehttp=time.time()
            client_socket.send(request.encode()) 
            response = client_socket.recv(4096)  
            timehttpr=time.time()
            print("RTT for HTTP client to server: ", timehttpr-timehttp)
            http_response = repr(response)
            http_response_len = len(http_response)
            print(http_response)
           
 
            #display the response
           # gh_imgui.text("[RECV] - length: %d" % http_response_len)
            #gh_imgui.text_wrapped(http_response)
            
            
            #AA=binascii.hexlify(binarydata[21:22]).decode("utf-8")
            #TC=binascii.hexlify(binarydata[22:23]).decode("utf-8")
            #RD=binascii.hexlify(binarydata[23:24]).decode("utf-8")
            #RA=binascii.hexlify(binarydata[24:25]).decode("utf-8")
            #Z=binascii.hexlify(binarydata[25:26]).decode("utf-8")
            #RCODE=binascii.hexlify(binarydata[26:30]).decode("utf-8")
            
            #QR=binascii.hexlify(binarydata[16:17]).decode("utf-8")
            #OPCODE=binascii.hexlify(binarydata[17:21]).decode("utf-8")
            #AA=binascii.hexlify(binarydata[21:22]).decode("utf-8")
            #TC=binascii.hexlify(binarydata[22:23]).decode("utf-8")
            #RD=binascii.hexlify(binarydata[23:24]).decode("utf-8")
            #RA=binascii.hexlify(binarydata[24:25]).decode("utf-8")
            #Z=binascii.hexlify(binarydata[25:26]).decode("utf-8")
            #RCODE=binascii.hexlify(binarydata[26:30]).decode("utf-8")
            #print(RCODE, ID)
            



if __name__ == '__main__':
    args = parse_args()
    start_udp_client(args.server_host, args.server_port)
    
    #what encode() does, what to do with ip listed in assignment, remove for loop?, what ip to put on top, what to write to question or authority, what is payload
    #whole big string is pay load
    #for first part write upto question leave blank everything 
    #no server in part one
    
    #to parse