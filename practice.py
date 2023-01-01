import socket
import binascii
# import bind
import time
import math
from argparse import ArgumentParser



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

    index=[]
    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server_socket:
                    
                # server_host = str(int(octets[int(index[1])-6], 16)) + "." + str(int(octets[int(index[1])-5], 16)) + "." + str(
                # int(octets[int(index[1])-4], 16)) + "." + str(int(octets[int(index[1])-3], 16))
                # print("Website ip address: ", server_host)
                

                server_socket.connect((server_host, server_port))  ##root server
                server_socket.sendto(binascii.unhexlify(payload), (server_host, server_port))
                data, address = server_socket.recvfrom(1024)
                

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
                print(index[-1])
               

                
                server_host = str(int(octets[int(index[-1]-1)], 16)) + "." + str(int(octets[int(index[-1])], 16)) + "." + str(
                    int(octets[int(index[-1])+1], 16)) + "." + str(int(octets[int(index[-1])+2], 16)) 
                print(server_host)
                print(octets[int(index[-1])])
        

             



if __name__ == '__main__':
    start_udp_client("192.12.94.30", 53)