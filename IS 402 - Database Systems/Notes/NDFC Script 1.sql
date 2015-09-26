DROP TABLE Appointment;
DROP TABLE Client;
DROP TABLE Counselor;
DROP TABLE Room;
DROP SEQUENCE NDFCID;

CREATE SEQUENCE NDFCID START WITH 1000 INCREMENT BY 1;

CREATE TABLE Counselor (
    CounselorID int default next value for NDFCID primary key
   ,FirstName varchar(50)
   ,lastname varchar(50)
   ,Address varchar(100)
   ,City varchar(50)
   ,State char(2)
   ,ZipCode char(10)
   ,Phone char(14)
   ,Email varchar(100)
);

CREATE TABLE Client (
    ClientID int default next value for NDFCID primary key
   ,FirstName varchar(50)
   ,lastname varchar(50)
   ,Address varchar(100)
   ,City varchar(50)
   ,State char(2)
   ,ZipCode char(10)
   ,Phone char(14)
   ,Email varchar(100)
);

CREATE TABLE Room (
    RoomNumber int primary key
   ,RoomName varchar(60)
);

CREATE TABLE Appointment (
    AppointmentID int default next value for NDFCID primary key
   ,AppointmentTime datetime
   ,Duration int
   ,CounselorID int references Counselor not null
   ,ClientID int references Client not null
   ,RoomNumber int references Room not null
);

-- 1000
INSERT INTO Counselor (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Louis', 'Larson', '26 Ventura Drive', 'Scotts Valley', 'CA', '95066', '831-438-7850', 'llarson@newdawn.com');
-- 1001
INSERT INTO Counselor (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Audrey', 'McLeod', '2083 Jim Rosa Lane', 'San Francisco', 'CA', '94107', '415-762-4047', 'amcleod@newdawn.com');
-- 1002
INSERT INTO Counselor (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Kyle','Sisk','2441 Shady Way','Garden Grove', 'CA', '92643', '714-636-6046', 'ksisk@newdawn.com');

-- 1003
INSERT INTO Client (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Thomas', 'Vaughan', '3758 Armbrester Drive', 'Irvine', 'CA', '92614', '310-526-5232', 'Tommy66@superrito.com');
-- 1004
INSERT INTO Client (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Jerry', 'Scranton', '1767 Reynolds Alley', 'Paramount', 'CA', '90723', '562-346-7291', 'levermore@gmail.com');
-- 1005
INSERT INTO Client (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Helen', 'Pauley', '4332 Park Street', 'Livermore', 'CA', '94550', '925-424-4804', 'helenbear@dayrep.com');
-- 1006
INSERT INTO Client (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Sarah', 'Pauley', '4332 Park Street', 'Livermore', 'CA', '94550', '952-422-0433', 'Sarahlives84@gmail.com');
-- 1007
INSERT INTO Client (FirstName, LastName, Address, City, State, ZipCode, Phone, Email) values ('Sergio',	'Silver',	'4622 Davis Avenue',	'Colton',	'CA',	'92324',	'909-570-3380',	'sergio@armyspy.com');

INSERT INTO Room (RoomNumber, RoomName) values (1, 'Clear sky');
INSERT INTO Room (RoomNumber, RoomName) values (2, 'Flowing waters');
INSERT INTO Room (RoomNumber, RoomName) values (3, 'Calm ocean');
INSERT INTO Room (RoomNumber, RoomName) values (4, 'Peaceful woods');

-- Audrey					Sarah					Clear sky					10/1/2014	8:00 AM						90
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) values (1001, 1006, 1, '2014-10-01T08:00:00', 90);
-- Audrey					Sergio				Clear sky					10/1/2014	11:00 AM					60
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) values (1001, 1007, 1, '2014-10-01T11:00:00', 60);
-- Louis						Jerry					Flowing waters		10/1/2014	10:00 AM					60
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) values (1000, 1004, 2, '2014-10-01T10:00:00', 60);
-- Audrey					Helen					Calm ocean				10/1/2014	10:00 AM					60
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) values (1001, 1005, 3, '2014-10-01T10:00:00', 60);
-- Kyle						Thomas				Peaceful woods		10/1/2014	10:00 AM					90
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) values (1002, 1003, 4, '2014-10-01T10:00:00', 90);
-- Audrey					Helen					Calm ocean				10/8/2014	10:00 AM					60
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) values (1001, 1005, 3, '2014-10-08T10:00:00', 60);
-- Louis						Jerry					Flowing waters		10/8/2014	10:00 AM					60
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) values (1000, 1004, 2, '2014-10-08T10:00:00', 60);
-- Kyle						Thomas				Peaceful woods		10/8/2014	10:00 AM					90
INSERT INTO Appointment (CounselorID, ClientID, RoomNumber, AppointmentTime, Duration) values (1002, 1003, 4, '2014-10-08T10:00:00', 90);



