# Class 4 - SQL

## Example Queries

#### To see all tables available
```sql
select * from information_schema.tables
```

#### Create Table with incrementing ID
```sql
# Create the sequence
create sequence entityid start with 100 increment by 1;

# Create the table
create table client(
    clientID  
   ,firstName varchar(50)
   ,lastName varchar(50)
);

# Insert a few records
insert into client (firstname, lastname) values('Laban', 'Schmeule'),('Lehi','theProphet');

# Get the records from table
select * from client;
```

