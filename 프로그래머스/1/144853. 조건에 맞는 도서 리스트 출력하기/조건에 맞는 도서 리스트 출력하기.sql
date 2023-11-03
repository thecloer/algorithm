-- 코드를 입력하세요
SELECT book_id, LEFT(published_date, 10)
from book
where category = '인문' and published_date like '2021%'
order by published_date;

# SELECT BOOK_ID, DATE_FORMAT(PUBLISHED_DATE, '%Y-%m-%d') 
# FROM BOOK 
# WHERE PUBLISHED_DATE BETWEEN '2021-01-01' AND '2021-12-31' AND CATEGORY = '인문' 
# ORDER BY PUBLISHED_DATE ASC;