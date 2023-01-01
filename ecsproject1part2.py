import matplotlib.pyplot as plt
import numpy as np
import dpkt
import sys
import socket
# create a reader

devices=0
uniqueip=0

fig,ax = plt.subplots()
time1=[]
time2=[]
time3=[]
time4=[]
iplist=[]
ip1s=0
ip2s=0
ip3s=0
ip4s=0
ip1d=0
ip2d=0
ip3d=0
ip4d=0

ipvisit=[]
visitedtwice=[]
ipvisitby1=[]
ipvisitby2=[]
ipvisitby3=[]
ipvisitby4=[]

timestamp=[]

nhttp=0
nhttps=0
npackets=0
ndns=0
nftp=0
nssh=0
ndhcp=0
ntelnet=0
nsmtp=0
npop3=0
nntp=0

f = open('project1_part2.pcap', 'rb')
pcap = dpkt.pcap.Reader(f)

# iterate over the pcap
for ts, buf in pcap:
    
    timestamp.append(ts)
    
    # gives you the link layer content
    eth = dpkt.ethernet.Ethernet(buf)
    #number of packets
    
    
    if not isinstance(eth.data, dpkt.ip.IP):
        continue
    
    # gives you the network layer content
    ip = eth.data
    
    if not isinstance(ip.data, dpkt.tcp.TCP):
        continue
   
    #add by me
    #if https,http
    tcp = ip.data
    npackets +=1
    
    if(socket.inet_ntoa(ip.src) == "10.42.0.149"):
        time1.append(ts)
        ip1s+=1
    if(socket.inet_ntoa(ip.src) == "10.42.0.32"):
        time2.append(ts)
        ip2s+=1
    if(socket.inet_ntoa(ip.src) == "10.42.0.52"):
        time3.append(ts)
        ip3s+=1
    if(socket.inet_ntoa(ip.src) == "10.42.0.193"):
        time4.append(ts)
        ip4s+=1
    
    if(socket.inet_ntoa(ip.dst) == "10.42.0.149"):
        ip1d+=1
    if(socket.inet_ntoa(ip.dst) == "10.42.0.32"):
        ip2d+=1
    if(socket.inet_ntoa(ip.dst) == "10.42.0.52"):
        ip3d+=1
    if(socket.inet_ntoa(ip.dst) == "10.42.0.193"):
        ip4d+=1
    
    if(socket.inet_ntoa(ip.dst) not in iplist):
        splitip=socket.inet_ntoa(ip.dst).split(".")
        if(int(splitip[0])==10 and int(splitip[1])==42 and int(splitip[2])==0 and int(splitip[3]) >= 2 and int(splitip[3]) <=255):
            iplist.append(socket.inet_ntoa(ip.dst))
            uniqueip +=1
    
    if(socket.inet_ntoa(ip.dst) == "10.42.0.149"):
        if(socket.inet_ntoa(ip.src) not in ipvisitby1):
            ipvisitby1.append(socket.inet_ntoa(ip.src))
            if((socket.inet_ntoa(ip.src) in ipvisitby2) or (socket.inet_ntoa(ip.src) in ipvisitby3) or (socket.inet_ntoa(ip.src) in ipvisitby4)):
                if(socket.inet_ntoa(ip.src) not in visitedtwice):
                    visitedtwice.append(socket.inet_ntoa(ip.src))
    if(socket.inet_ntoa(ip.dst) == "10.42.0.32"):
        if(socket.inet_ntoa(ip.src) not in ipvisitby2):
            ipvisitby2.append(socket.inet_ntoa(ip.src))
            if((socket.inet_ntoa(ip.src) in ipvisitby1) or (socket.inet_ntoa(ip.src) in ipvisitby3) or (socket.inet_ntoa(ip.src) in ipvisitby4)):
                if(socket.inet_ntoa(ip.src) not in visitedtwice):
                    visitedtwice.append(socket.inet_ntoa(ip.src))
    if(socket.inet_ntoa(ip.dst) == "10.42.0.52"):
        if(socket.inet_ntoa(ip.src) not in ipvisitby3):
            ipvisitby3.append(socket.inet_ntoa(ip.src))
            if((socket.inet_ntoa(ip.src) in ipvisitby1) or (socket.inet_ntoa(ip.src) in ipvisitby2) or (socket.inet_ntoa(ip.src) in ipvisitby4)):
                if(socket.inet_ntoa(ip.src) not in visitedtwice):
                    visitedtwice.append(socket.inet_ntoa(ip.src))
    if(socket.inet_ntoa(ip.dst) == "10.42.0.193"):
        if(socket.inet_ntoa(ip.src) not in ipvisitby4):
            ipvisitby4.append(socket.inet_ntoa(ip.src))
            if((socket.inet_ntoa(ip.src) in ipvisitby1) or (socket.inet_ntoa(ip.src) in ipvisitby2) or (socket.inet_ntoa(ip.src) in ipvisitby3)):
                if(socket.inet_ntoa(ip.src) not in visitedtwice):
                    visitedtwice.append(socket.inet_ntoa(ip.src))
            
   # if(socket.inet_ntoa(ip.dst) in ipvisit):
    #    if(socket.inet_ntoa(ip.dst) not in visitedtwice):
    #        visitedtwice.append(socket.inet_ntoa(ip.dst))
    #else:
    #    ipvisit.append(socket.inet_ntoa(ip.dst))
    
        
        
            
    #protocol used
    if(tcp.dport==80 or tcp.sport==80):
        nhttp +=1
    elif(tcp.dport==443 or tcp.sport==443):
        nhttps+=1
    elif(tcp.dport==53 or tcp.sport==53):
        ndns+=1
    elif(tcp.dport==21 or tcp.sport==21):
        nftp+=1
    elif(tcp.dport==22 or tcp.sport==22):
        nssh+=1
    elif(tcp.dport==67 or tcp.sport==67):
        ndhcp+=1
    elif(tcp.dport==23 or tcp.sport==23):
        ntelnet+=1
    elif(tcp.dport==25 or tcp.sport==25):
        nsmtp+=1
    elif(tcp.dport==110 or tcp.dport==995):
        npop3+=1
    elif(tcp.dport==123 or tcp.sport==123):
        nntp+=1
    
    # gives you the transport layer content
  
    
    
    # gives you the application layer content
    data = tcp.data
    
    # # check if the packet is a http packet
    # if len(data) <= 0 or tcp.sport != 80:
    #     continue

    if len(data) <= 0 or tcp.dport != 80:
        continue
        
    # print response body
    try:
      http = dpkt.http.Request(tcp.data)
      print(http)
    except Exception as e:
      print(e)
      continue
  
print("number of device connected: ",uniqueip)
print("IP of devices connected: ", iplist)
print("Packets sent by IP: ", iplist[0])
print(ip1s)
print("Packets sent by IP: ", iplist[1])
print(ip2s)
print("Packets sent by IP: ", iplist[2])
print(ip3s)
print("Packets sent by IP: ", iplist[3])
print(ip4s)
print("Hence IP: ",iplist[2]," sent out the most packets","\n")

print("Packets received by IP: ", iplist[0])
print(ip1d)
print("Packets received by IP: ", iplist[1])
print(ip2d)
print("Packets received by IP: ", iplist[2])
print(ip3d)
print("Packets received by IP: ", iplist[3])
print(ip4d)
print("Hence IP: ",iplist[0]," received the most packets","\n")

print("IP's visited by multiple devices:\n", visitedtwice,"\n")


print("HTTPS: ", (nhttps/npackets)*100,"%"," ")
print("HTTP: ", (nhttp/npackets)*100,"%"," ")
print("DNS: ", (ndns/npackets)*100,"%"," ")
print("FTP: ", (nftp/npackets)*100,"%"," ")
print("SSh: ", (nssh/npackets)*100,"%"," ")
print("DHCP: ", (ndhcp/npackets)*100,"%"," ")
print("TELNET ", (ntelnet/npackets)*100,"%"," ")
print("SMTP: ", (nsmtp/npackets)*100,"%"," ")
print("POP3: ", (npop3/npackets)*100,"%"," ")
print("NTP: ", (nntp/npackets)*100,"%",'\n')
print("Hence HTTPS is used the most which is: ",  (nhttps/npackets)*100,"%", "\n")
timetaken=float(round(timestamp[-1]-timestamp[0])/60)
print("Time taken to capture file: ", timetaken, " minutes")

x1 = ["10.42.0.149"] * len(time1)
plt.plot(time1,x1)

x2 = ["10.42.0.32"] * len(time2)
plt.plot(time2,x2)

x3 = ["10.42.0.52"] * len(time3)
plt.plot(time3,x3)

x4 = ["10.42.0.193"] * len(time4)
plt.plot(time4,x4)
plt.show()



