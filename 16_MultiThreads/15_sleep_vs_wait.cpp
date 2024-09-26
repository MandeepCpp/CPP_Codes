/*

        Sleep                                                           Wait
    --> I am done with my timeslice(work)                   -->     i am done with my timeslice(work).
         do not give me another work for                            Do n't give me another work until someone 
         at least n time(ms).                                       calls notify() and notifyall().
         The OS doesnot even try to schedule                        the OS won't even try to schedule
         the sleeping thread untill requested                       untill someone calls notify/notifyall()
         time passed.

         Point :                                                    Points:
         1. it will keep the lock and sleep                         1. it releases the lock and wait
         2. sleep is directly to thread,                            2. wait is on Condition variable
            it is a thread function














*/