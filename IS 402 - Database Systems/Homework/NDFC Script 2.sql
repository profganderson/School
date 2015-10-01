-- TODO:
--  Ask about ScheduledBy column in table
--  Ask about some duplicate records in the appointments table

-- Empty out tables when running multiple times
DROP VIEW Employees;
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
);

CREATE TABLE Counselor (
  CounselorID int primary key references Person(PersonID)
 ,DegreeSuffix varchar(10)
);

CREATE TABLE Client (
  ClientID int primary key references Person(PersonID)
 ,ReferredBy varchar(50)
 ,ReminderMethod varchar(50)
);

CREATE TABLE Room (
  RoomNumber int primary key
 ,RoomName varchar(60)
);

CREATE TABLE Appointment (
  AppointmentID int default next value for NDFCID primary key
 ,AppointmentTime datetime
 ,Duration int
 ,Assignment varchar(3000)
 ,Notes varchar(2000)
 ,Kept bit
 ,CounselorID int references Counselor not null
 ,ClientID int references Client not null
 ,RoomNumber int references Room not null
);

-- Create Employee View
CREATE VIEW Employees AS
SELECT e.EmployeeID, p.FirstName, p.LastName, p.Address, p.City, p.State, p.ZipCode, p.Phone, p.Email, e.HireDate, e.Wage
FROM Employee e JOIN Person p ON p.PersonID = e.EmployeeID;

CREATE VIEW Clients AS
SELECT c.ClientID, p.FirstName, p.LastName, p.Address, p.City, p.State, p.ZipCode, p.Phone, p.Email, c.ReferredBy, c.ReminderMethod
FROM Client c JOIN Person p ON p.PersonID = c.ClientID;

CREATE VIEW Counselors AS
SELECT c.CounselorID, p.FirstName, p.LastName, p.Address, p.City, p.State, p.ZipCode, p.Phone, p.Email, c.DegreeSuffix
FROM Counselor c JOIN Person p ON p.PersonID = c.CounselorID;

-- PERSON 'TEMPLATE'
-- INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('', '', '', '', '', '', '', '');

-- Insert Employees
INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Holly', 'White', '102 Ramona Street', 'Ramona', 'CA', '92065', '760-789-0561', 'hollyw@newdawn.com');
INSERT INTO Employee (EmployeeID, HireDate, Wage) VALUES ((SELECT max(PersonID) FROM Person), '2013-07-01T00:00:00', 17.5);

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('John', 'Taylor', '1416 H Street', 'Poway', 'CA', '92064', '562-363-2914', 'johnt@newdawn.com');
INSERT INTO Employee (EmployeeID, HireDate, Wage) VALUES ((SELECT max(PersonID) FROM Person), '2014-08-01T00:00:00', 15);

-- Insert Counselors
INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Louis', 'Larson', '26 Ventura Drive', 'Scotts Valley', 'CA', '95066', '831-438-7850', 'llarson@newdawn.com');
INSERT INTO Counselor (CounselorID, DegreeSuffix) VALUES ((SELECT max(PersonID) FROM Person), 'MS');

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Audrey', 'McLeod', '2083 Jim Rosa Lane', 'San Francisco', 'CA', '94107', '415-762-4047', 'amcleod@newdawn.com');
INSERT INTO Counselor (CounselorID, DegreeSuffix) VALUES ((SELECT max(PersonID) FROM Person), 'PhD');

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) VALUES ('Kyle', 'Sisk', '2441 Shady Way', 'Garden Grove', 'CA', '92643', '714-636-6046', 'ksisk@newdawn.com');
INSERT INTO Counselor (CounselorID, DegreeSuffix) VALUES ((SELECT max(PersonID) FROM Person), 'EdD');

-- Insert Clients
INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Thomas', 'Vaughan', '3758 Armbrester Drive', 'Irvine', 'CA', '92614', '310-526-5232', 'Tommy66@superrito.com');
INSERT INTO Client (ClientID, ReferredBy, ReminderMethod) VALUES ((SELECT max(PersonID) FROM Person), 'Radio', 'Phone');

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Jerry', 'Scranton', '1767 Reynolds Alley', 'Paramount', 'CA', '90723', '562-346-7291', 'levermore@gmail.com');
INSERT INTO Client (ClientID, ReferredBy, ReminderMethod) VALUES ((SELECT max(PersonID) FROM Person), 'Billboard', 'Text');

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Helen', 'Pauley', '4332 Park Street', 'Livermore', 'CA', '94550', '925-424-4804', 'helenbear@dayrep.com');
INSERT INTO Client (ClientID, ReferredBy, ReminderMethod) VALUES ((SELECT max(PersonID) FROM Person), 'Billboard', 'Email');

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Sarah', 'Pauley', '4332 Park Street', 'Livermore', 'CA', '94550', '952-422-0433', 'Sarahlives84@gmail.com');
INSERT INTO Client (ClientID, ReferredBy, ReminderMethod) VALUES ((SELECT max(PersonID) FROM Person), 'Family', 'Text');

INSERT INTO Person (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Sergio',	'Silver',	'4622 Davis Avenue',	'Colton',	'CA',	'92324',	'909-570-3380',	'sergio@armyspy.com');
INSERT INTO Client (ClientID, ReferredBy, ReminderMethod) VALUES ((SELECT max(PersonID) FROM Person), '', 'Postcard');

-- Insert Rooms
INSERT INTO Room (RoomNumber, RoomName) VALUES (1, 'Clear sky');
INSERT INTO Room (RoomNumber, RoomName) VALUES (2, 'Flowing waters');
INSERT INTO Room (RoomNumber, RoomName) VALUES (3, 'Calm ocean');
INSERT INTO Room (RoomNumber, RoomName) VALUES (4, 'Peaceful woods');

-- Insert Appointments
-- INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration, ScheduledBy)
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Audrey'), (SELECT ClientID FROM Clients WHERE FirstName='Sarah'), (SELECT RoomNumber FROM Room WHERE RoomName='Clear sky'), '2014-10-01T08:00:00', 90);
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Audrey'), (SELECT ClientID FROM Clients WHERE FirstName='Sergio'), (SELECT RoomNumber FROM Room WHERE RoomName='Clear sky'), '2014-10-01T11:00:00', 60);
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Louis'), (SELECT ClientID FROM Clients WHERE FirstName='Jerry'), (SELECT RoomNumber FROM Room WHERE RoomName='Flowing waters'), '2014-10-01T10:00:00', 60);
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Audrey'), (SELECT ClientID FROM Clients WHERE FirstName='Helen'), (SELECT RoomNumber FROM Room WHERE RoomName='Calm ocean'), '2014-10-01T10:00:00', 60);
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Kyle'), (SELECT ClientID FROM Clients WHERE FirstName='Thomas'), (SELECT RoomNumber FROM Room WHERE RoomName='Peaceful woods'), '2014-10-01T10:00:00', 90);
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Audrey'), (SELECT ClientID FROM Clients WHERE FirstName='Helen'), (SELECT RoomNumber FROM Room WHERE RoomName='Calm ocean'), '2014-10-01T10:00:00', 60);
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Louis'), (SELECT ClientID FROM Clients WHERE FirstName='Jerry'), (SELECT RoomNumber FROM Room WHERE RoomName='Flowing waters'), '2014-10-01T10:00:00', 60);
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) VALUES ((SELECT CounselorID FROM Counselors WHERE FirstName='Kyle'), (SELECT ClientID FROM Clients WHERE FirstName='Thomas'), (SELECT RoomNumber FROM Room WHERE RoomName='Peaceful woods'), '2014-10-01T10:00:00', 90);
