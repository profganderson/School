---------------------------------------------
--
-- Self-referencing tables & Outer Joins
--
---------------------------------------------

DROP TABLE Employee;
CREATE TABLE Employee(eid int primary key, name char(20), supervisorID int references Employee);

INSERT INTO Employee (eid, name) VALUES (5, 'Sariah');
INSERT INTO Employee (eid, name) VALUES (31, 'Laban');
INSERT INTO Employee (eid, name, supervisorID) VALUES (10, 'Lehi', 5);
INSERT INTO Employee (eid, name, supervisorID) VALUES (20, 'Nephi', 10);
INSERT INTO Employee (eid, name, supervisorID) VALUES (30, 'Sam', 20);
INSERT INTO Employee (eid, name, supervisorID) VALUES (50, 'Laman', 20);
INSERT INTO Employee (eid, name, supervisorID) VALUES (60, 'Lemuel', 20);

-- SELECT only employees without supervisors
select e.eid, e.name as employee, s.name as supervisor
from employee e left outer join employee s on e.supervisorid = s.eid
where s.eid is null
;

---------------------------------------------
--
-- Creating Many to Many relationships
--
---------------------------------------------
DROP TABLE Item;
-- Create item table
CREATE TABLE Item(
  itemid int primary key,
  name char(30)
);
-- Create association class
CREATE TABLE Build(
  parentItemID int references Item,
  childItemID int references Item,
  qty int,
  constraint build_pk primary key (parentItemID, childItemID)
);

-- insert items
INSERT INTO Item VALUES (1, 'harry potter minifigure');
INSERT INTO Item VALUES (2, 'lego guy torso');
INSERT INTO Item VALUES (3, 'lego guy legs');
INSERT INTO Item VALUES (4, 'harry potter head with scar');
INSERT INTO Item VALUES (5, 'touseled hair');
INSERT INTO Item VALUES (6, 'hand');
INSERT INTO Item VALUES (7, 'left arm');
INSERT INTO Item VALUES (8, 'right arm');

-- Put all the items together

-- Build the torso
INSERT INTO Build VALUES (2, 6, 2);
INSERT INTO Build VALUES (2, 7, 1);
INSERT INTO Build VALUES (2, 8, 1);

-- Put the whole figure together
INSERT INTO Build VALUES (1, 2, 1);
INSERT INTO Build VALUES (1, 3, 1);
INSERT INTO Build VALUES (1, 4, 1);
INSERT INTO Build VALUES (1, 5, 1);

-- Dr. Allen put this all in on the advanced query editor
SELECT * FROM lego.item;

-- WITH IMAGES
SELECT * FROM lego.items;
