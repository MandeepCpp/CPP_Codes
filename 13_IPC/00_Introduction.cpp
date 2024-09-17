/*

        Interprocess Communication which provides an environment, allows process communication. 
        And the reason why we need IPC:
        Information sharing - when several users wants an access to an information it's essential to provide an environment 
        which they can access at the same time. 

        Computation speedup - instead of taking one task at a time, it's better to divide the task to several subtasks 
        which they all work for single task concurrently. In order to achieve this, the subtasks need to communicate each other.

        Modularity -  when designing a system, one person will not be designing whole system alone. 
        Therefore, we divide the system to different modules and they'll be put together later on. 
        Also these modules need to cooperate with each other.

        Convenience - from user perspective, if they are utilizing multiple task at a same time meaning 
        different processes are running concurrently. 
        So it'd be convenient if those processes can communicate each other and avoid clashing to one another. 

        There are two fundamental models of Interprocess Communication:

        1. Shared memory - There'll be shared memory region for cooperating processes which will be used for 
        communicating by processes read and write to this memory region. 
        For example: If A process writes an information in a memory region, 
        B process will read the information and thus it can understand. 


        2. Message passing - Processes can communicate through Kernel by sending and receiving messages from Kernel.

























*/