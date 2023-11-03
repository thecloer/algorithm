-- 코드를 입력하세요
SELECT 
    b.title, b.board_id, r.reply_id, r.writer_id, r.contents, 
    left(r.created_date, 10)
from USED_GOODS_REPLY as r
join USED_GOODS_BOARD as b
on b.CREATED_DATE like "2022-10%" and b.BOARD_ID = r.BOARD_ID
order by r.created_date, b.title;