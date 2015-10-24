-- 1
SELECT FirstName, LastName, Phone, SaleDate
FROM Customer c LEFT OUTER JOIN Sale s ON c.customerID=s.customerID
WHERE City='Arlington' AND State='VA'
ORDER BY LastName, FirstName

-- 2
SELECT FirstName, LastName, Phone, SaleDate
FROM Customer c LEFT OUTER JOIN Sale s ON c.customerID=s.customerID
WHERE City='Arlington' AND State='VA'
ORDER BY LastName, FirstName

-- 3
SELECT DISTINCT FirstName, LastName, Phone
FROM Customer c LEFT OUTER JOIN Sale s ON c.CustomerID=s.CustomerID
WHERE state='BC' AND SaleDate IS NULL
ORDER BY LastName, FirstName

-- 4
SELECT DISTINCT e.FirstName, e.LastName, se.Salary, we.Wage
FROM Employee e LEFT OUTER JOIN SalaryEmployee se on e.EmployeeID=se.EmployeeID LEFT OUTER JOIN WageEmployee we ON e.EmployeeID=we.EmployeeID
ORDER BY LastName, FirstName

-- 5
SELECT DISTINCT e.FirstName, e.LastName, we.MaxHours
FROM Employee e JOIN Purchase p ON e.EmployeeID=p.EmployeeID LEFT OUTER JOIN WageEmployee we ON e.EmployeeID=we.EmployeeID

-- 6
SELECT DISTINCT FirstName, LastName
FROM Employee e JOIN Purchase p ON e.EmployeeID=p.EmployeeID JOIN Manufacturer m ON p.ManufacturerID=m.ManufacturerID
WHERE m.ManufacturerName='Nike' AND month(p.PurchaseDate)=10 AND year(p.PurchaseDate)=2014

-- 7
SELECT DISTINCT e.FirstName, e.LastName
FROM (SELECT DISTINCT FirstName, LastName, ManagerID
        FROM Employee e JOIN Purchase p ON e.EmployeeID=p.EmployeeID JOIN Manufacturer m ON p.ManufacturerID=m.ManufacturerID
        WHERE m.ManufacturerName='Nike' AND month(p.PurchaseDate)=10 AND year(p.PurchaseDate)=2014) a
    JOIN Employee e ON e.EmployeeID=a.ManagerID

-- 8
SELECT DISTINCT m.ManufacturerName, c.FirstName, c.LastName, c.State
FROM Customer c JOIN Sale s ON c.CustomerID=s.CustomerID JOIN SaleItem si ON s.SaleID=si.SaleID JOIN InventoryItem ii ON si.ProductID=ii.ProductID JOIN PurchaseItem pi ON ii.ProductID=pi.ProductID JOIN Purchase p ON pi.PurchaseID=p.PurchaseID JOIN Manufacturer m ON p.ManufacturerID=m.ManufacturerID
WHERE m.State=c.State AND month(p.PurchaseDate)=6
ORDER BY m.ManufacturerName, c.LastName, c.FirstName

-- 9
SELECT DISTINCT m.ManufacturerName, c.FirstName, c.LastName, c.City
FROM Customer c JOIN Manufacturer m ON m.State=c.State
WHERE c.State='MA' AND c.City=m.City

-- 10
SELECT DISTINCT p.ProductName
FROM Employee e JOIN Purchase pu ON e.EmployeeID=pu.EmployeeID JOIN PurchaseItem pi ON pu.PurchaseID=pi.PurchaseID JOIN InventoryItem ii ON pi.ProductID=ii.ProductID JOIN Product p ON p.ProductID=ii.ProductID
WHERE e.EmployeeID=61 AND month(pu.purchasedate)=3 AND year(pu.purchasedate)=2014 AND day(pu.purchasedate)=21
ORDER BY p.ProductName
