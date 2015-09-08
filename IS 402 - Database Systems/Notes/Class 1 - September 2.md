# Class 1 - September 2, 2015

_Facts are stubborn things; and whatever may be our wishes, our inclinations, or the dictates of our passions, they cannot alter the state of facts and evidence. - John Adams_

### How do database systems work?

**Parts of a Database System**
* Data
* DBMS / Engine
    - Defines, secures and queries the data
    - Responsible for data integrity, security and recovery
    - Non-visual / Back end
* Application Software
    - Front end; makes the engine visual; this is what the user interacts with

The engine and the application have a request/response cycle

### Types of Database systems
* PC Architecture
    - Data, front end, back end - all live on 1 computer - like Microsoft Access
    - Cheap & fast, but only serves 1 user
* Mainframe
    - Data, front end, and back end live in one place, but queries are sent out to dumb terminals
    - Many users, but very expensive
* File Server
    - The data lives in one place, the back end and front end operate on terminals
    - This is ok...but if you have 1,000,000 records, all 1,000,000 travel over the network when you make a query on all records. This limits you to about 10 users.
* Client / Server Architecture
    - The data and back end live on the server, the front end lives on terminals
* Web


