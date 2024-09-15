/*

            Shared memory System is one of models of Interprocess Communication 
            which is used for communicating between processes by creating region of a memory. 
            The processes that initiated communication will be creating the region of a memory 
            and others who wants to communicate has to put the shared memory-segment to their address space. 

            Originally operating system won't allow processes accessing each other's data, 
            but if two or more processes agree to remove their restriction then it's possible.

            In order to understand the concept we took an example of Producer Consumer problem. 

            Producer produces an information and consumer consumes information 
            (just like real life examples like having services, buying staff, surfing internet etc). 

            The problem is the producer and consumer has to work simultaneously so that while producer produces, 
            consumer will consume. 

            They has to be synchronized so that consumer will only consume what's available there 
            (instead of trying to consume which isn't produced yet). 

            The solution to the problem is shared memory, to allow producer and consumer work concurrently 
            we need something called buffer of items which can be constantly filled with information by producer and consumed by the consumer. 

            Buffer resides in shared memory region. 

            There are two types of buffers, 
            unbound buffer and bound buffer. 

            In either case if there is no information to be consumed then consumer must wait. 

            The difference is for unbound buffer, 
            the producer can produce without limitation while for the bound buffer producer can produce only fixed amount of data.













*/