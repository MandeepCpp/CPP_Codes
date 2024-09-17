/*

Here is what I understood:
In Interprocess Communication there are two main models and they are shared memory and message passing systems. 
And for message passing system the processes which are communicating each other must send and receive messages. 

To realize this, there must exist a link that can be logically implemented through certain methods for send() & receive() operations:
-Direct or indirect communication
-Synchronous or asynchronous communication
-Automatic or explicit buffering

For each implementation there exists an issue such as naming, synchronization, buffering. 

This text is mainly focused on Direct or indirect communication. 

Firstly Direct communication: 
The processes who wants to communicate must refer to each others identity (either sender or receiver). 

send(P,message)  -> send a message to P process
receive(Q,message) -> receive a message from Q.

There is no other additional information required except each others identity to start the communication. 

A link establishes automatically and for each pair of process there exists only one link. 
It holds true vice-versa (for each link there exists exactly two processes that is associated with the link). 

This scheme exhibits symmetry in addressing (because both sender and receiver must mention to one another).

Another Direct communication: Receiving process doesn't have to refer the sender, 
instead it has ID which can be vary depends on the sender. 

send(P,message)  -> send a message to P process
receive(ID,message) -> receive a message from any process, the varible id is set to the name of the process

For example if A sends B then ID in receiver will be replaced by A or if sender is C then the ID becomes C and so on. 

Here only sending process must refer receiver's identity, therefore, this scheme employs asymmetry.

The disadvantage of direct communication is naming. 
Because if one of the process changes it's identity then it'll cause a problem 
such as examining all other processes that is associated with the name changed process. 


Indirect communication: The processes use an object called mailbox(or port) 
for communication by sending and receiving messages from the mailbox. 

Each mailbox has its unique identification and two processes can only communicate if they've shared mailbox.

send(A,message) -> send a message to mailbox A
receive(A,message) -> receive a message from mailbox A

A communication link in this scheme has following properties:
-Link can exist only if the pair of processes has shared mailbox
-Link may associate more than two processes
-Each pair of process may have number of links, with each link corresponding to one mailbox.

Problem : 
send(A,message) -> send a message to mailbox A by process P1
receive(A,message) -> receive a message from mailbox A by process P2
receive(A,message) -> receive a message from mailbox A by process P3

What happens if there are more than one processes receive a message? 
Which one should receive the message? 
To solve this there are certain methods.

-Allow only two process for a single link
-Allow only one of the process receive the message
-Let the system choose which process should receive the message.






1) Direct communication
- The sender and receiver process must use the name of the other process to send a message (symmetry in addressing)
- A link can connect at most 2 processes and only one link exists between 2 processes
- If one process changes its name, all other links that use that process must be examined to adapt to the new name
- Variant of this method: only the sender process uses the name of the recipient, the recipient will use the id of the sender (asymmetry in addressing)

2) Indirect communication
- Processes communicate with each other through a mailbox
- A mailbox is an object where processes can send messages to and receive or remove messages from
- A link can only be established between 2 processes if they have a shared mailbox
- A link can connect 2 or more processes and between 2 processes can exist more than one link

- 3 processes P1, P2, and P3 share the same mailbox. When P1 sends a message, 
    and both P2 and P3 execute the receive() at the same time, which process will receive the message?
-  3 ways to handle this problem:
  + The link is only established for exactly 2 processes
  + Only one process can execute receive() at one time
  + Let the system decide which process will receive the message (algorithm like round robin)
- A mailbox may be owned by a process or by the OS



n direct communication, the processes must explicitly specify the name of the sending or receiving process. Each pair of communicating process has a unique link shared by them.
Variants are:
1) Symmetric: Both the sending process and the receiving process must name the recipient and the sender respectively.
2) Asymmetric: Here, only the sender needs to specify the recipient process. The receiving process has an id variable that is set to the name of the process it receives a message from.

In indirect communication, the sender process sends a message to a mailbox and the receiving process retrieves the message from  the mailbox. In this scheme, the mailbox can be shared by multiple processes. Between different pairs of communication processes, there may be different links but they all connect to the same mailbox.


















*/