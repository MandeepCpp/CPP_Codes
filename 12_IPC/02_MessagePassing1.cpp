/*
Message Passing System allows processes communicate each other without shared memory. 

This kind of system is particularly useful for the communicating processes 
where it resides in different computers connected through a network. 

Message Passing facility provides at least two operations send and receive. 

The message sent by the process can have fixed or variable size. 

Fixed size messages are easier for system level implementation, 
however it's difficult when comes to programming. 
Because when you're programming, you may want to control the way of how the messages are sent 
and you should always keep in mind that it's fixed size. 

On the other hand variable size messages are complicated on system level implementation but easier for programming. 

To send and receive messages between processes there needs to exist some kind of communication link. 

There are several ways to logically implement a link and send(), receive() operations like:

-Direct or indirect communication
-Synchronous or Asynchronous communication
-Automatic or explicit buffering

There are several issues that associated with above methods such as naming, synchronization, buffering etc.
















*/