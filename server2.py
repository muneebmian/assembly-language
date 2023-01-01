import socket
from argparse import ArgumentParser
import binascii

IpTLD=""
IpAUTH=""
IpTMZ=""


def parse_args():
    # parse the command line arguments
    args = ArgumentParser()
    args.add_argument('--host', default="198.41.0.4")
    args.add_argument('--port', default=53, type=int)
    return args.parse_args()

def start_udp_server(host, port):
    
    
    payload = "AABB010000010000000000000377777703746D7A03636F6D0000010001"
    # create a server socket with the following specifications
    #   AF_INET -> IPv4 socket
    #   SOCK_DGRAM -> UDP protocol
    x=0
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server_socket:
     server_socket.connect(("10.0.0.50", port))
     data, address = server_socket.recvfrom(1024)
     print("jddjddjdj")
     for  i in range(3):
            if(x==0):
                print("Root ip address: ",host)
            if(x==1):
                print("TLD ip address: ",host)
            if(x==2):
                print("AUTH ip address: ",host)
          
            

            # bind the socket to a OS port
            #server_socket.bind((host, port))
           
        # start listening for connections
                # # server_socket.listen()
            server_socket.connect((host, port))
            server_socket.sendto(binascii.unhexlify(payload), (host, port))
            message, addr = server_socket.recvfrom(1024)
            print("fjfjfjfjfj")

                # decode the message and print
                #print(f"Message from {addr}: {message.decode()}")\
            datainhex=binascii.hexlify(message).decode("utf-8")
            print(datainhex)
            octets = [datainhex[i:i+2] for i in range(0, len(datainhex), 2)]
            predomain=int(octets[12],16) #==3
            domainlength= int(octets[13+predomain],16)#==16 
            postdomainlength= int(octets[14+domainlength+predomain],16)
            RDDATAstart= 31 + predomain + postdomainlength + domainlength
            TYPEstart= 22 + predomain + postdomainlength + domainlength
                #print(octets)
            TYPE=octets[TYPEstart:TYPEstart+2]
            RDDATA=octets[RDDATAstart:RDDATAstart+4]
            print(RDDATA)
            type1=  str(int(TYPE[1],16))
            print(type1)
                
            if(type1=="1"):
                print("DNS record type is: A")
            host= str(int(RDDATA[0],16)) + "." +  str(int(RDDATA[1],16)) + "." +  str(int(RDDATA[2],16)) + "." +  str(int(RDDATA[3],16))
            x+=1
            if(x==2):
                print("Website ip address: ",host)
            payload = datainhex
    
    
    
    

if __name__ == '__main__':
    args = parse_args()
    start_udp_server(args.host, args.port)