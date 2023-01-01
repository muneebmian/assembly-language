import socket
import binascii
# import bind
import time
import math
from argparse import ArgumentParser


def parse_args():
    # parse the command line arguments
    args = ArgumentParser()
    args.add_argument('--server-host', default="192.33.4.12")
    args.add_argument('--server-port', default=53, type=int)
    return args.parse_args()


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
   # print(payload)


    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server_socket:
        x = 0
        for i in range(4):
            index=[]
            index1=[]
            if (x == 0):
                print("Root ip address: ", server_host)
            if (x == 1):
                print("TLD ip address: ", server_host)
            if (x == 2):
                print("AUTH ip address: ", server_host)
            if (x == 3):
                # y=0
                # for i in octets:
                #     y+=1
                #     if(i=="0c"):
                #         index1.append(y)
                # print(octets[int(index1[1])-6])
                    
                # server_host = str(int(octets[int(index1[1])-6], 16)) + "." + str(int(octets[int(index1[1])-5], 16)) + "." + str(
                # int(octets[int(index1[1])-4], 16)) + "." + str(int(octets[int(index1[1])-3], 16))
                print("Website ip address: ", server_host)

            if (x != 3):
                if(x==0):
                    timeroot=time.time()
                if(x==1):
                    timetld=time.time()
                if(x==2):
                    timeauth=time.time()
                
                server_socket.connect((server_host, server_port))  ##root server
                server_socket.sendto(binascii.unhexlify(payload), (server_host, server_port))
                data, address = server_socket.recvfrom(1024)
                if(x==0):
                    timeroot1=time.time()
                if(x==1):
                    timetld1=time.time()
                if(x==2):
                    timeauth1=time.time()

                # decode the message and print
                # print(f"Message from {addr}: {message.decode()}")\
                datainhex = binascii.hexlify(data).decode("utf-8")
               
                octets = [datainhex[i:i + 2] for i in range(0, len(datainhex), 2)]
                print(octets)
                y=0
                for i in octets:
                    y+=1
                    if(i=="c0"):
                        index.append(y)
                
               
                if(octets[-4] !="00"):
                    server_host = str(int(octets[-4], 16)) + "." + str(int(octets[-3], 16)) + "." + str(
                        int(octets[-2], 16)) + "." + str(int(octets[-1], 16))

                else:
                    server_host = str(int(octets[int(index[-1])-5], 16)) + "." + str(int(octets[int(index[-1])-4], 16)) + "." + str(
                        int(octets[int(index[-1])-3], 16)) + "." + str(int(octets[int(index[-1])-2], 16))
                print(octets[int(index[-1])],octets[int(index[-1])-5]) 
                x += 1

             
        print("RTT for client to root: ",timeroot1-timeroot)
        print("RTT for client to tld: ",timetld1-timetld)
        print("RTT for client to auth: ",timeauth1-timeauth)
        print("Total RTT: ", (timeroot1-timeroot)+(timetld1-timetld)+(timeauth1-timeauth))
        


if __name__ == '__main__':
    args = parse_args()
    start_udp_client(args.server_host, args.server_port)