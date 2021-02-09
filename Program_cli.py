import socket

ip_address = input("enter IP to connect: ")

sockobj = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("trying to connect to ", ip_address, " port 8888")
sockobj.connect((ip_address, 8888))
print("connected")

while(1):
	message = str(input("Enter message to server: "))
	sockobj.send(message.encode())
	info = sockobj.recv(1024)
	print("server sent: ", info.decode())
