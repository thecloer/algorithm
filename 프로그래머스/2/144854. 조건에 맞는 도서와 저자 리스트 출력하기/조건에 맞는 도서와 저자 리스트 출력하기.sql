select book_id, author_name, left(published_date, 10)
from book b
join author a on b.author_id = a.author_id
where category = '경제'
order by published_date;