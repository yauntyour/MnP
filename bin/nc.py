import socket
import sys
from ping3 import ping

if len(sys.argv) == 1:
    sys.argv.append(input("Host:"))
    sys.argv.append(input("Port:"))
    sys.argv.append(input("recvBufflen:"))
    
response = ping(str(sys.argv[1]))
print(str(response)+"ms")

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((str(sys.argv[1]), int(sys.argv[2])))

while True:
    data = client.recv(int(sys.argv[3]))
    print(data)
    msg =  input()
    if msg == "exit":
        break
    client.sendall(msg.encode('utf-8'))
client.close()