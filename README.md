It is a program that creates 3 threads. These threads will access a shared resource, an integer called buffer, one at a time.
The buffer will initially be set to 0. They will each print their thread ID, process ID and the buffer's current value in one
statement, then increment the buffer by one. Use a mutex to ensure this whole process is not interrupted. The threads modify 
the buffer a total of 24 times. When each thread is done, it should return the number of times it modified the buffer to the 
main thread. The total number of modifications should be exactly 24.
