/*

The message passing system is implemented with calls to two primitives, i.e.,  1) send() and 2) receive().

These primitives can be synchronous(blocking) or asynchronous(non-blocking).

Synchronous send():(Blocking send) : The sending process waits until the sent message is received by the receiving process or by mailbox
Asynchronous send():(non Blocking send) : The sending process sends a message and immediately resumes operation.
Synchronous receive():(Blocking receive): The receiver blocks until a message is available.
Asynchronous receive(): (Blocking receive):The receiver eithers receives a message or null.



No matter the type of message passing system(direct/indirect), the messages that are exchanged reside in a temporary buffer/queue. The buffer can be of 3 types:
1) Zero capacity buffer: Here, the sender must wait for the receiving process to receive the message before resuming execution. In other words, the link cannot have any messages waiting in it.
2) Bounded buffer: Here, the queue has a finite length. If the buffer is not full then the sender can resume execution after sending a message. But, if the buffer is full then the sender must block itself.
3) Unbounded buffer: Here, the queue is of infinite size. The sender never blocks.



1) Synchronous or asynchronous communication
- Processes can communicate through a call to send() and receive()
- These calls can be blocking (synchronous) or non-blocking (asynchronous)
- Send blocking: the sender is blocked until the receiver receives the message
- Send non-blocking: the sender can send the message and then resume its operation
- Receive blocking: the receiver needs to wait for the message from the sender
- Receive non-blocking: the receiver receives a valid message or null

2) Buffering
- A buffer acts as a temporary queue for processes to send and receive messages
- 3 types of buffer:
  + Zero capacity: no waiting message in the buffer. The sender is blocked until the receiver receives the message
  + Bounded buffer: The buffer has a fixed size. The sender can send messages whenever there is an available space in the buffer. But when the buffer is full, the sender is blocked until a space is available
  + Unbounded buffer: The buffer has infinite space. The sender can send any number of messages and resume its operation
















*/

/*


void Producer()
{

int item;
message m;

while(1)
{
receive(Consumer,&m);
item = procude_item();
build_message(&m,item);
send(Consumer,&m);
}

}


void Consumer()
{

int item;
message m;

while(1)
{

receive(Producer,&m);
item = extract_item();
send(Producer,&m);
consume _items(item);
}
}









*/