# C# Data Structures

A data structure is a format for organizing and storing data; if used properly, they can make your programs more efficient.

### Array

An array contains a list of objects or values. The objects and values need to be of the same data type.

| Pros | Cons |
| --- | --- |
| Fast Access | It is very slow to change the size if need be |

```c#
int[] aiNums = new int[3];
aiNums[0] = 14;
aiNums[1] = 20;
```

### ArrayList

An ArrayList is a dynamic array. It can contain a list of objects or values of any data type - even many different data types.

```c#
ArrayList alNames = new ArrayList();
alNames.Add("Bugs");
alNames.Add("Daffy");
alNames.Add(1);
alNames.Add(true);

string sName = alNames[0].ToString();
```

### List

A list is a collection and is similar to the ArrayList. With a list, however, you must specify the data type. When possible, you should favor lists over array lists; they are cleaner to code and faster in execution.

```c#
List<string> alNames = new List<string>();
alNames.Add("Bugs");
alNames.Add("Daffy");
```

### LinkedList

A collection like a list but where each of the elements are linked together as nodes. They allow for easy insertion in the "middle" of the list.

```

|----------|          |----------|
|          | -------> |          |
|----------|          |----------|

```

LinkedLists are fast on insertion and deletion. They cannot, however, directly access items, so they can be slower than arrays.

```c#
LinkedList<string> lnklstNames = new LinkedList<string>();
lnklstNames.AddFirst("Goofy");
lnklstNames.AddFirst("Daffy");
```

### Dictionary

A dictionary is similar to an ArrayList but it allows the developer to create and handle their own keys for indexing. They are optimized for speed and have very fast lookups.

```c#
Dictionary<string, int> myDictionary = new Dictionary<string, int>();
myDictionary.Add("bugs", 25);
myDictionary.Add("daffy", 35);
Console.WriteLine("Bugs Bunny is " + myDictionary["bugs"] + " years old."); // prints "Bugs Bunny is 25 years old."

Dictionary<int, string> myOtherDictionary = new Dictionary<int, string>();
myOtherDictionary.Add(25, "bugs");
myOtherDictionary.Add(35, "Daffy");
Console.WriteLine("The character that is 35 years old is " + myOtherDictionary[35]); // prints "The character that is 35 years old is Daffy"
```

### Hash Table

A hash table is like a dictionary in that is has key/value pairs; however, the order in which they are added is not preserved like a dictionary. This means that a hash table can store items faster than a dictionary and lookup is even more optimized. They are still slower than dictionaries, though, and are mostly obsolete.

```c#
Hashtable myHashTable = new Hashtable();
myHashTable.Add("Bugs", 25);
myHashTable.Add("Daffy", 35);
Console.WriteLine(myHashTable["Bugs"]);
```

### Hash Set

A hash set is a special kind of list where there cannot be any duplicate values. When an element is added, the set will make sure it is unique. Dictionaries still have slightly better performance than sets.

```c#
HashSet<int> mySet = new HashSet<int>();
mySet.Add(3); // Good!
mySet.Add(5); // Good!
mySet.Add(5); // Not Allowed :(
```

### Stack

A stack resembles a list and has an add (`Push`) and get (`Pop`) method. `Pop`, however, retrieves **and** removes the item from the list. The `Peek` method allows you to check the top value without removing it.

Stacks are **LIFO** (last in, first out), meaning the last element you push onto the stack will be the first element you retrieve. You can think about it like a stack of plates at Hometown Buffet.

Stacks are commonly used within languages and operating systems.

```c#
Stack<string> myStack = new Stack<string>();
myStack.Push("1");
myStack.Push("2");
myStack.Push("3");

while (myStack.Count > 0)
{
  Console.Write(myStack.Pop() + " ");
}

// Prints "3 2 1 "
```

### Queue

A queue is similar to a stack but is **FIFO** (first in, first out). You can think of it like a line to buy something - the first in line is the first one to get out of the line.

The add method for a queue is called `Enqueue`, the pop method is `Dequeue`.

```c#
Queue<string> myQueue = new Queue<string>();
myQueue.Enqueue("1");
myQueue.Enqueue("2");
myQueue.Enqueue("3");

while (myQueue.Count > 0)
{
  Console.Write(myQueue.Dequeue() + " ")
}

// Prints "1 2 3 "
```
