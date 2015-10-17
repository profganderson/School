-- Empty out tables when running multiple times
DROP VIEW Employees;
DROP VIEW Counselors;
DROP VIEW Clients;
DROP TABLE ScheduledFor;
DROP TABLE Appointment;
DROP TABLE Room;
DROP TABLE Client;
DROP TABLE Counselor;
DROP TABLE Employee;
DROP TABLE Person;
DROP SEQUENCE NDFCID;

-- Create sequences and tables
CREATE SEQUENCE NDFCID START WITH 1000 INCREMENT BY 1;

CREATE TABLE Person (
  PersonID int default next value for NDFCID primary key
 ,FirstName varchar(50)
 ,LastName varchar(50)
 ,Address varchar(50)
 ,City varchar(50)
 ,State char(2)
 ,ZipCode char(10)
 ,Phone char(14)
 ,Email varchar(100)
);

CREATE TABLE Employee (
  EmployeeID int primary key references Person(PersonID)
 ,HireDate datetime
 ,Wage decimal(4,2)
 ,SupervisorID int references Employee(EmployeeID) not null
);

CREATE TABLE Counselor (
  CounselorID int primary key references Person(PersonID)
 ,DegreeSuffix varchar(10)
);

CREATE TABLE Client (
  ClientID int primary key references Person(PersonID)
 ,FoundOut varchar(50)
 ,ReminderMethod varchar(50)
 ,ReferredByID int references Client(ClientID)
);

CREATE TABLE Room (
  RoomNumber int primary key
 ,RoomName varchar(60)
);

CREATE TABLE Appointment (
  AppointmentID int default next value for NDFCID primary key
 ,AppointmentTime datetime
 ,Duration int
 ,Notes varchar(2000)
 ,CounselorID int references Counselor not null
 ,RoomNumber int references Room not null
 ,EmployeeID int references Employee not null
);

CREATE TABLE ScheduledFor (
  Assignment varchar(3000)
 ,kept bit
 ,AppointmentID int references Appointment(AppointmentID) not null
 ,ClientID int references Client(ClientID) not null
 ,constraint ScheduledFor_PK primary key (AppointmentID, ClientID)
);

-- Create Employee View
CREATE VIEW Employees AS
SELECT e.EmployeeID, p.FirstName, p.LastName, p.Address, p.City, p.State, p.ZipCode, p.Phone, p.Email, e.HireDate, e.Wage,
  (SELECT FirstName + ' ' + LastName FROM Person supervisor WHERE supervisor.PersonID = e.SupervisorID) AS Supervisor
FROM Employee e JOIN Person p ON p.PersonID = e.EmployeeID;

CREATE VIEW Clients AS
SELECT c.ClientID, p.FirstName, p.LastName, p.Address, p.City, p.State, p.ZipCode, p.Phone, p.Email, c.ReminderMethod,
  (SELECT FirstName + ' ' + LastName FROM Person referredby WHERE referredby.PersonID = c.ReferredByID) AS ReferredBy
FROM Client c JOIN Person p ON p.PersonID = c.ClientID;

CREATE VIEW Counselors AS
SELECT c.CounselorID, p.FirstName, p.LastName, p.Address, p.City, p.State, p.ZipCode, p.Phone, p.Email, c.DegreeSuffix
FROM Counselor c JOIN Person p ON p.PersonID = c.CounselorID;

-- PERSON 'TEMPLATE'
-- INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('', '', '', '', '', '', '', '');

-- Insert Employees
INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Holly', 'White', '102 Ramona Street', 'Ramona', 'CA', '92065', '760-789-0561', 'hollyw@newdawn.com');
INSERT INTO Employee (EmployeeID, HireDate, Wage, SupervisorID) VALUES ((SELECT max(PersonID) FROM Person), '2013-07-01T00:00:00', 17.5, (SELECT max(PersonID) FROM Person));

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Mark', 'Lucas', '2204 N. Broadway', 'Escondido', 'CA', '92026', '760-789-5836', 'medward@newdawn.com');
INSERT INTO Employee (EmployeeID, HireDate, Wage, SupervisorID) VALUES ((SELECT max(PersonID) FROM Person), '2014-09-10T00:00:00', 17.5, (SELECT EmployeeID FROM Employees WHERE FirstName = 'Holly'));

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('John', 'Taylor', '1416 H Street', 'Poway', 'CA', '92064', '562-363-2914', 'johnt@newdawn.com');
INSERT INTO Employee (EmployeeID, HireDate, Wage, SupervisorID) VALUES ((SELECT max(PersonID) FROM Person), '2014-08-01T00:00:00', 15, (SELECT EmployeeID FROM Employees WHERE FirstName = 'Mark'));

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Molly', 'Helgeson', '2253 Eucalyptus St.', 'Julian', 'CA', '92036', '760-363-1429', 'mollyh@newdawn.com');
INSERT INTO Employee (EmployeeID, HireDate, Wage, SupervisorID) VALUES ((SELECT max(PersonID) FROM Person), '2013-06-01T00:00:00', 15, (SELECT EmployeeID FROM Employees WHERE FirstName = 'Holly'));

-- Insert Counselors
INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Louis', 'Larson', '26 Ventura Drive', 'Scotts Valley', 'CA', '95066', '831-438-7850', 'llarson@newdawn.com');
INSERT INTO Counselor (CounselorID, DegreeSuffix) VALUES ((SELECT max(PersonID) FROM Person), 'MS');

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Audrey', 'McLeod', '2083 Jim Rosa Lane', 'San Francisco', 'CA', '94107', '415-762-4047', 'amcleod@newdawn.com');
INSERT INTO Counselor (CounselorID, DegreeSuffix) VALUES ((SELECT max(PersonID) FROM Person), 'PhD');

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Kyle', 'Sisk', '2441 Shady Way', 'Garden Grove', 'CA', '92643', '714-636-6046', 'ksisk@newdawn.com');
INSERT INTO Counselor (CounselorID, DegreeSuffix) VALUES ((SELECT max(PersonID) FROM Person), 'EdD');

-- Insert Clients
INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Thomas', 'Vaughan', '3758 Armbrester Drive', 'Irvine', 'CA', '92614', '310-526-5232', 'Tommy66@superrito.com');
INSERT INTO Client (ClientID, FoundOut, ReminderMethod) VALUES ((SELECT max(PersonID) FROM Person), 'Radio', 'Phone');

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Jerry', 'Scranton', '1767 Reynolds Alley', 'Paramount', 'CA', '90723', '562-346-7291', 'levermore@gmail.com');
INSERT INTO Client (ClientID, FoundOut, ReminderMethod) VALUES ((SELECT max(PersonID) FROM Person), 'Billboard', 'Text');

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Sherie', 'Scranton', '1767 Reynolds Alley', 'Paramount', 'CA', '90723', '562-346-9172', 'sheeeeerie@gmail.com');
INSERT INTO Client (ClientID, FoundOut, ReminderMethod, ReferredByID) VALUES ((SELECT max(PersonID) FROM Person), 'Family', 'Text', (SELECT PersonID FROM Person WHERE FirstName='Jerry'));

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Helen', 'Pauley', '4332 Park Street', 'Livermore', 'CA', '94550', '925-424-4804', 'helenbear@dayrep.com');
INSERT INTO Client (ClientID, FoundOut, ReminderMethod) VALUES ((SELECT max(PersonID) FROM Person), 'Billboard', 'Email');

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Sarah', 'Pauley', '4332 Park Street', 'Livermore', 'CA', '94550', '952-422-0433', 'Sarahlives84@gmail.com');
INSERT INTO Client (ClientID, FoundOut, ReminderMethod, ReferredByID) VALUES ((SELECT max(PersonID) FROM Person), 'Family', 'Text', (SELECT PersonID FROM Person WHERE FirstName='Helen'));

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Jack', 'Pauley', '4332 Park Street', 'Livermore', 'CA', '94550', '925-422-0433', '7thcoy@gmail.com');
INSERT INTO Client (ClientID, FoundOut, ReminderMethod, ReferredByID) VALUES ((SELECT max(PersonID) FROM Person), 'Family', 'Email', (SELECT PersonID FROM Person WHERE FirstName='Helen'));

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Sergio',	'Silver',	'4622 Davis Avenue',	'Colton',	'CA',	'92324',	'909-570-3380',	'sergio@armyspy.com');
INSERT INTO Client (ClientID, FoundOut, ReminderMethod, ReferredByID) VALUES ((SELECT max(PersonID) FROM Person), 'Friend', 'Postcard', (SELECT PersonID FROM Person WHERE FirstName='Jack'));

-- Insert Rooms
INSERT INTO Room (RoomNumber, RoomName) VALUES (1, 'Clear sky');
INSERT INTO Room (RoomNumber, RoomName) VALUES (2, 'Flowing waters');
INSERT INTO Room (RoomNumber, RoomName) VALUES (3, 'Calm ocean');
INSERT INTO Room (RoomNumber, RoomName) VALUES (4, 'Peaceful woods');

-- Insert Appointments
-- INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration, ScheduledBy)
INSERT INTO Appointment (CounselorID, RoomNumber, AppointmentTime, Duration, EmployeeID) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Audrey'), (SELECT RoomNumber FROM Room WHERE RoomName='Clear sky'), '2014-10-01T08:00:00', 90, (SELECT EmployeeID FROM Employee e JOIN Person p on p.PersonID=e.EmployeeID WHERE FirstName='Holly'));
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Sarah'), 1);

INSERT INTO Appointment (CounselorID, RoomNumber, AppointmentTime, Duration, EmployeeID) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Audrey'), (SELECT RoomNumber FROM Room WHERE RoomName='Clear sky'), '2014-10-01T11:00:00', 60, (SELECT EmployeeID FROM Employee e JOIN Person p on p.PersonID=e.EmployeeID WHERE FirstName='Holly'));
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Sergio'), 1);

INSERT INTO Appointment (CounselorID, RoomNumber, AppointmentTime, Duration, EmployeeID) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Louis'), (SELECT RoomNumber FROM Room WHERE RoomName='Flowing waters'), '2014-10-01T10:00:00', 60, (SELECT EmployeeID FROM Employee e JOIN Person p on p.PersonID=e.EmployeeID WHERE FirstName='John'));
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Jerry'), 1);
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Sherie'), 1);

INSERT INTO Appointment (CounselorID, RoomNumber, AppointmentTime, Duration, EmployeeID) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Audrey'), (SELECT RoomNumber FROM Room WHERE RoomName='Calm ocean'), '2014-10-01T10:00:00', 60, (SELECT EmployeeID FROM Employee e JOIN Person p on p.PersonID=e.EmployeeID WHERE FirstName='Holly'));
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Helen'), 1);
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Sarah'), 1);

INSERT INTO Appointment (CounselorID, RoomNumber, AppointmentTime, Duration, EmployeeID) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Kyle'), (SELECT RoomNumber FROM Room WHERE RoomName='Peaceful woods'), '2014-10-01T10:00:00', 90, (SELECT EmployeeID FROM Employee e JOIN Person p on p.PersonID=e.EmployeeID WHERE FirstName='Holly'));
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Thomas'), 1);

INSERT INTO Appointment (CounselorID, RoomNumber, AppointmentTime, Duration, EmployeeID) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Audrey'), (SELECT RoomNumber FROM Room WHERE RoomName='Calm ocean'), '2014-10-08T10:00:00', 60, (SELECT EmployeeID FROM Employee e JOIN Person p on p.PersonID=e.EmployeeID WHERE FirstName='Holly'));
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Helen'), 1);
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Sarah'), 1);
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Jack'), 0);

INSERT INTO Appointment (CounselorID, RoomNumber, AppointmentTime, Duration, EmployeeID) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Louis'), (SELECT RoomNumber FROM Room WHERE RoomName='Flowing waters'), '2014-10-08T10:00:00', 60, (SELECT EmployeeID FROM Employee e JOIN Person p on p.PersonID=e.EmployeeID WHERE FirstName='Holly'));
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Jerry'), 0);

INSERT INTO Appointment (CounselorID, RoomNumber, AppointmentTime, Duration, EmployeeID) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Kyle'), (SELECT RoomNumber FROM Room WHERE RoomName='Peaceful woods'), '2014-10-08T10:00:00', 90, (SELECT EmployeeID FROM Employee e JOIN Person p on p.PersonID=e.EmployeeID WHERE FirstName='Holly'));
INSERT INTO ScheduledFor (AppointmentID, ClientID, kept) VALUES ((SELECT max(AppointmentID) FROM Appointment), (SELECT ClientID FROM Clients WHERE FirstName='Thomas'), 1);
