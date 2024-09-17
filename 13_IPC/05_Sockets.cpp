/*

In order establish a connection between client and server we need sockets. 
Sockets are end point of communication and it can be identified by IP address, port number. 

Each process that is communicating has a socket. 
Servers that have specific services listen to specific socket ports. 
So when connection request comes from a client 
the server would be listening to specific port 
and accepts the request from client socket to complete the connection.


From host side or client side the process's sockets 
port number must be above 1024 because below 1024 ports are reserved for specific purpose.



*/