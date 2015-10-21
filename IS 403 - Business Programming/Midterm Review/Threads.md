# Threads

### What are threads?

A **thread** is a process moving through time; every application uses at least one thread. Threads can improve performance if used correctly, but will hinder performance if implemented poorly. They should be used to separate computations and logical processes.

**Multi-threading** is the use of more than one thread and can help increase responsiveness but also increase the chance for a deadlock.

In a GUI C# app, the UI thread is created automatically and used by the application when executed. Attempts to access form control from threads other than the UI thread will cause a **cross-thread exception**. All UI operations are queued in that thread.

Thread execution is scheduled by the operating system. There is no guarantee that multiple threads will be split onto multiple processors. When running on a single processor, multiple threads take turns running; with multiple processors, they can run simultaneously. Multi-processing is, however, much more complex (scheduling, sharing of resources, timing, etc.).

### Thread Lifecycle

| State | Description |
| --- | --- |
| Un-started State | The thread is created but has not been started |
| Ready State (Running) | Thread is ready to run and waiting for the CPU cycle |
| Not Runnable State (WaitSleepJoin) | The thread is not executable because the Sleep or Wait methods have been called or it is Block by other I/O operations |
| Dead State (Stopped) | Thread execution is aborted or has been completed |
| Suspend | Paused by the program and waiting for command to resume |

### Threads in Action
* **Step 1** - include the `System.Threading` namespace
* **Step 2** - create your threads
* **Step 3** - start the threads
* **Step 4** - join the threads
* **Step 5** - write the methods called by the thread constructor and are executed during the running of the thread.

##### Thread Methods
* `Start` - Starts the thread
* `Abort` - Begins the process of terminating the thread
* `Join` - Blocks the calling thread until a thread terminates or enables us to wait until a thread completes
* `Sleep` - Causes the thread to wait a specified number of milliseconds
* `Yield` - Causes a thread to yield execution to another thread that is ready to run on the current processor (controlled by the operating system)

```c#
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace ConsoleThreads
{
  class Program
  {
    static void Main(string[] args)
    {
      Thread thread1 = new Thread(new ThreadStart(A));
      Thread thread2 = new Thread(new ThreadStart(B));

      thread1.Start();
      thread2.Start();
      thread1.Join();
      thread2.Join();

      Console.ReadLine();
    }

    static void A()
    {
      int iCount;

      for (iCount = 0; iCount < 100; iCount++)
      {
        Console.WriteLine("A " + Convert.ToString(iCount));
      }
    }

    static void B()
    {
      int iCount;

      for (iCount = 0; iCount < 100; iCount++)
      {

        Console.WriteLine("B " + Convert.ToString(iCount));
      }
    }
  }
}
```

### Using Threads
Don't use them just because they are cool! You don't need to try to make things "faster" until you have proved that a single thread implementation is slow - if done incorrectly, multi-threading can cause problems.

**When to use multi-threading**:
* If a particular piece of code takes a long time to complete
* If you can run code parallel
* If you are waiting a long time for File I/O to complete or respond
