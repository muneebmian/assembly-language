import socket
import binascii
# import bind
import time
import math
from argparse import ArgumentParser


def parse_args():
    # parse the command line arguments
    args = ArgumentParser()
    args.add_argument('--server-host', default="169.237.229.88")
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
    print(payload)


    with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as server_socket:
        x = 0
        host = "198.41.0.4"
        timeDNS = time.time()
        for i in range(4):
            if (x == 0):
                 print("Root ip address: ", host)
            if (x == 1):
                print("TLD ip address: ", host)
            if (x == 2):
                 print("AUTH ip address: ", host)
            if (x == 3):
                 print("Website ip address: ", host)
        
            if (x != 3):
                server_socket.connect((host, server_port))  ##root server
                server_socket.sendto(binascii.unhexlify(payload), (host, server_port))
                data, address = server_socket.recvfrom(1024)

                # decode the message and print
                # print(f"Message from {addr}: {message.decode()}")\
                datainhex = binascii.hexlify(data).decode("utf-8")
                #print(datainhex)
                octets = [datainhex[i:i + 2] for i in range(0, len(datainhex), 2)]

                # if(type1=="1"):
                #    print("DNS record type is: A")
                host = str(int(octets[-4], 16)) + "." + str(int(octets[-3], 16)) + "." + str(int(octets[-2], 16)) + "." + str(int(octets[-1], 16))
                x += 1
               
        timeDNS1 = time.time()

        print(f"TTL is: {timeDNS1-timeDNS}")
                # type = str(int(TYPE[1],16))
                #
                # if (type == "")


# CACHE METHOD
#         CACHE METHODD
    # cache_dictionary = {}
    #
    # if payloadyoutube not in cache_dictionary:
    #     cache_dictionary['www.youtube.com'] = payloadyoutube
    # if payloadfacebook not in cache_dictionary:
    #      cache_dictionary['www.facebook.com'] = payloadfacebook
    # if payloadnytime not in cache_dictionary:
    #     cache_dictionary['www.nytimes.com'] = payloadnytime
    # if payloadcnn not in cache_dictionary:
    #     cache_dictionary['www.cnn.com'] = payloadcnn





if __name__ == '__main__':
    args = parse_args()
    while True:
        start_udp_client(args.server_host, args.server_port)

    # what encode() does, what to do with ip listed in assignment, remove for loop?, what ip to put on top, what to write to question or authority, what is payload
    # whole big string is pay load
    # for first part write upto question leave blank everything
    # no server in part one

    # to parse