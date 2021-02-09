import socket

sockobj = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sockobj.bind(('localhost', 8888))
sockobj.listen(5)

print("waiting for incoming connection")
connection, address = sockobj.accept()
print("connected from", address)

while(1):
	info = connection.recv(1024)
	print("received: ", info.decode())
	if info:
		message = info.upper()
		connection.send(message)
		print("sent to client: ", message.decode())
	else:
		break
		
connection.close()
