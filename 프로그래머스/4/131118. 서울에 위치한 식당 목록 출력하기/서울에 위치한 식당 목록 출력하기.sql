-- 코드를 입력하세요
SELECT i.rest_id, i.rest_name, i.food_type, i.favorites, i.address, round(avg(r.review_score),2) as score
from rest_review as r
join rest_info as i
on i.address like "서울%"
    and i.rest_id = r.rest_id
group by i.rest_id
order by score desc, i.favorites desc;