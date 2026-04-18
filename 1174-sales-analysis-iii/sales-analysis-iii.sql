# Write your MySQL query statement below
SELECT P.product_id,P.product_name FROM Product as P
WHERE NOT EXISTS (
    SELECT 1
    FROM Sales as S
    WHERE S.product_id = P.product_id
      AND (S.sale_date < '2019-01-01' OR S.sale_date > '2019-03-31')
)
AND EXISTS (
    SELECT 1
    FROM Sales S
    WHERE S.product_id = P.product_id
      AND S.sale_date BETWEEN '2019-01-01' AND '2019-03-31'
);