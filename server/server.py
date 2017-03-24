

# SERVER

#!/usr/bin/env python

print "Welcome in server.py"

import socket


TCP_IP = ''
TCP_PORT = 1727
BUFFER_SIZE = 1024  # Normally 1024, but we want fast response


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # to avoid "socket already in use"
s.bind((TCP_IP, TCP_PORT))
s.listen(1)

conn, addr = s.accept()

print 'Connected ! Connection address:', addr
while 1:
	data = conn.recv(BUFFER_SIZE)
	if not data: break
	print "received data:", data
	#conn.send(data)  # echo
conn.close()



