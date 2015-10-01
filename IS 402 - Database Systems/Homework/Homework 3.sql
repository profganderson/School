-- 1
select sale.*
from product join sale on sale.productid = product.productid
where category = 'slippers'


-- 2
select sale.*
from product join sale on sale.productid = product.productid
where (category = 'slippers' or category = 'casual shoes')
  AND month(sale.SaleDate) = 1


-- 3
select s.*
from product p join sale s on s.productid = p.productid
where (color='green' AND category='sneakers')


-- 4
select s.*, p.productname, p.category, p.color
from product p join sale s on s.productid = p.productid
where color='green' AND (category = 'sneakers' OR category='sandals')


-- 5
select distinct c.state
from customer c join sale s on s.customerid=c.customerid
where month(s.saledate)=1 AND year(s.saledate)=2015
order by c.state


-- 6
select distinct m.manufacturername
from product p join manufacturer m on p.manufacturerid=m.manufacturerid
where p.price>=50 AND p.category='heels'


-- 7
select distinct p.color, p.category
from manufacturer m join product p on m.manufacturerid = p.manufacturerid
where m.manufacturername='Puma'
order by color, category


-- 8
select distinct p.category
from sale s join product p on p.productid=s.productid
where month(s.saledate)=1 AND year(s.saledate)=2014


-- 9
select c.FirstName, c.LastName, s.quantity
from customer c join sale s on c.customerid=s.customerid
where month(s.saledate)=1 AND year(s.saledate)=2015 AND c.state='CA'


-- 10
select distinct c.FirstName, c.LastName 
from customer c join sale s on s.customerid=c.customerid 
where year(s.saledate)=2015 AND c.state='WA' 
order by c.LastName, c.FirstName