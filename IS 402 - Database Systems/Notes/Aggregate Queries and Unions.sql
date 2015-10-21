SELECT category,
avg(ListPrice) AS AveragePrice,
max(ListPrice) AS MaxPrice,
min(ListPrice) AS MinPrice,
count(*) AS RecordCount,
count(ListPrice) AS countPrice,
count(distinct ListPrice) AS countDistinctPrice,
sum(ListPrice) AS sumPrice
FROM product
GROUP BY category
ORDER BY category
